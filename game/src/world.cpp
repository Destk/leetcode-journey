#include "../include/world.h"
#include <iostream>
World::World() : map(std::vector<std::vector<char>> (20, std::vector<char>(30, ' '))), entitys(), terrain() {}

void World::addEntity(Entity* e){
    entitys.push_back(e);
}

void World::render(){
    std::cout<<"╔══════════════════════════════╗\n";
    for(size_t i = 0; i < map.size(); i++){
            std::cout << "║";
        for(size_t j = 0; j < map[0].size(); j++){
            std::cout<<map[i][j];
        }
         std::cout << "║\n";
    }
    std::cout<<"╚══════════════════════════════╝\n";
}

void World::placeEntities(){
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++){
            map[i][j] = ' ';
        }
    }
    for(auto* e : entitys){
        size_t map_x = e->getX();
        size_t map_y = e->getY();
        if(e->isPlayer() == true){
            map[map_y][map_x] = 'P';
        }else{
            map[map_y][map_x] = 'E';
        }
    }
}

std::vector<Entity*>& World::getEntities() { 
    return entitys; 
}

void World::setTerrain(std::string t, int x, int y){
    map[y][x] = t[0];
}