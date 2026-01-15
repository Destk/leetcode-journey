#include "../include/entity.h"
#include <iostream>

Entity::Entity() : hp(100), damage(25), x(0), y(0) {}
Entity::Entity(int h,int d, int x1, int y1) : hp(h), damage(d), x(x1), y(y1) {}

void Entity::move(char d){
    if(d == 'w' || d == 'W'){ y++; }
    else if(d == 's' || d == 'S'){ y--; }
    else if(d == 'a' || d == 'A'){ x--; }
    else if(d == 'd' || d == 'D'){ x++; }
}

void Entity::setPos(int x, int y){ this->x = x; this->y = y; }
void Entity::setHp(int h){ hp = h; }

int Entity::getX() const{ return x; }
int Entity::getY() const{ return y; }

void Entity::setDamage(int d){
    if(d <= 50){ damage = d; }
    else{ std::cerr << "Урон не может превышать 50!\n"; }
}

int Entity::getHp() const { return hp; }
std::string Entity::getName() const { return "Entity"; }
void Entity::takeDamage(int dmg) {
    hp -= dmg; 
    if(hp < 0) hp = 0;
}

Player::Player() : Name("Player"), armor(30), superdamage(60) {}

void Player::setName(const std::string& name){ Name = name; }
void Player::setArmor(int a){
    if(a <= 60){ armor = a; }
    else{ std::cerr << "Броня не может превышать 60!\n"; }
}

bool Player::isPlayer() const{ return true; }

void Player::getInfo(){
    std::cout << "=== PLAYER ===\n";
    std::cout << "Имя: " << Name << " | HP: " << hp 
              << " | Урон: " << damage << " | Броня: " << armor << "\n";
}

void Player::attack(Entity* target) {
    if(target && target->getHp() > 0) {
        target->takeDamage(damage);
        std::cout << Name << " бьёт " << target->getName() 
                  << " на " << damage << " урона! HP: " << target->getHp() << "\n";
    } else {
        std::cout << Name << ": Нет цели!\n";
    }
}

Enemy::Enemy() : Name("Enemy"), jump_power(5) {}
Enemy::Enemy(int h,int d,int x,int y) : Entity(h,d,x,y), Name("Goblin"), jump_power(5) {}

void Enemy::setName(const std::string& name) { Name = name; }
void Enemy::setJump(int j){
    if(j <= 10){ jump_power = j; }
    else{ std::cerr << "Прыжок > 10!\n"; }
}

bool Enemy::isPlayer() const{ return false; }

void Enemy::getInfo(){
    std::cout << "=== ENEMY ===\n";
    std::cout << "Имя: " << Name << " | HP: " << hp 
              << " | Урон: " << damage << "\n";
}

void Enemy::attack(Entity* target) {
    if(target && target->getHp() > 0) {
        target->takeDamage(damage);
        std::cout << Name << " контратакует на " << damage << "!\n";
    }
}
