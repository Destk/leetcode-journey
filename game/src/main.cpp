#include "../include/world.h"
#include <iostream>
#include <limits>

int menu(){
    bool s{false};
    int x{};
    while(!s){
        std::cout << "Game Menu:\n"
          << "1. move (WASD)\n"
          << "2. attack nearest\n" 
          << "3. status\n"
          << "4. add enemy\n"
          << "5. quit\n";
        std::cin>>x;
        if(std::cin.fail()|| x > 5 || x < 1){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            std::cout<<'\n';
            s=true;
        }
    }
    return x;
}
int main(){
    std::cout << "Мини-игра RPG\n";
    World w;
    
    w.setTerrain("^|^", 15, 5);   
    w.setTerrain("..", 10, 10);

    Player* hero = new Player();
    hero->setHp(150);
    hero->setDamage(30);
    hero->setPos(5, 18);
    w.addEntity(hero);
    
    Enemy* goblin = new Enemy(80, 40, 25, 1);
    goblin->setPos(25, 2);
    w.addEntity(goblin);
    while(true) {
        w.placeEntities();
        w.render();

        int choice = menu();
        if(choice == 5) break;
        
        switch(choice) {
            case 1: {
                char dir; 
                std::cout << "Направление (WASD): ";
                std::cin >> dir;
                hero->move(dir);
                break;
            }
            case 2: {
            bool attacked = false;
            for(auto* e : w.getEntities()) {  
                if(!e->isPlayer()) {
                    hero->attack(static_cast<Enemy*>(e));
                    attacked = true;
                    break;
                }
            }
    if(!attacked) std::cout << "Нет врагов поблизости!\n";
    break;
}
            case 3: hero->getInfo(); break;
        }
        
        w.placeEntities();
        w.render();
        std::cout << "\n";
    }
    return 0;
}