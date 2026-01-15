#ifndef WORLD_H
#define WORLD_H

#include "../include/Entity.h"
#include <vector>

class World{
    private:
        std::vector<Entity*> entitys{};
        std::vector<std::vector<char>> map{};
        std::string terrain{};
    public:
        World();
        void addEntity(Entity* e);
        void placeEntities();
        void render();
        void setTerrain(std::string t, int x, int y);
        std::vector<Entity*>& getEntities();
};

#endif //WORLD_H