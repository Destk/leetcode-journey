#include <iostream>
#include <vector>
#include <utility>

class MyHashMap {
private:
    static const int BUCKET_COUNT = 1000; 
    std::vector<std::vector<std::pair<int,int>>> hash_map{};
public:
    MyHashMap() {
        hash_map.resize(BUCKET_COUNT);
    }
    size_t hash(int key){
        return key % BUCKET_COUNT;
    }

    void put(int key, int value) {
        size_t ind = hash(key);
        auto& map = hash_map[ind];
        for(size_t i = 0; i < map.size(); ++i){
            if(map[i].first == key){
                map[i].second = value;
                return ;
            }
        }
        map.push_back({key,value});
    }
    
    int get(int key) {
        size_t ind = hash(key);
        auto& map = hash_map[ind];
        for(size_t i = 0; i < map.size(); ++i){
            if(map[i].first == key){
                return map[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        size_t ind = hash(key);
        auto& map = hash_map[ind];
        for(size_t i = 0; i < map.size(); i++){
            if(map[i].first == key){
                map.erase(map.begin() + i);
                return;
            }
        }
    }
};

int main(){
MyHashMap map;
map.put(3,15);
std::cout<<map.get(3);

return 0;
}
