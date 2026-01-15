#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
protected:
    int hp{}, damage{}, x{}, y{};
public:
    Entity();
    Entity(int h, int d, int x, int y);
    void move(char d);
    void setPos(int x, int y);
    void setHp(int h);
    void setDamage(int dam); 
    
    int getX() const;
    int getY() const;
    int getHp() const;                    
    std::string getName() const;          
    virtual void takeDamage(int dmg);    
    
    virtual bool isPlayer() const { return false; }
    virtual void attack(Entity* target) = 0;  
    virtual ~Entity() = default;
};

class Player : public Entity {
private:
    std::string Name;
    int armor{};
    int superdamage{};
public:
    Player();
    void setName(const std::string& name);
    void setArmor(int ar);
    void getInfo();
    bool isPlayer() const override;
    void attack(Entity* target) override; 
};

class Enemy : public Entity {
private:
    std::string Name{};
    int jump_power{};
public:
    Enemy();
    Enemy(int h, int d, int x, int y);
    void setName(const std::string& n);
    void setJump(int j);
    void getInfo();
    bool isPlayer() const override;
    void attack(Entity* target) override; 
};

#endif // ENTITY_H
