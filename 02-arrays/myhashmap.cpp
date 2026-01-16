#include <iostream>
#include <vector>
#include <utility>

class MyHashMap {
private:
    std::vector<std::pair<int,int>> hash_map{};
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(size_t i  = 0; i < hash_map.size(); i++){
            if(hash_map[i].first == key){
                hash_map[i].second = value;
                return ;
            }
        }
        hash_map.push_back({key,value});
    }
    
    int get(int key) {
        for(size_t i = 0; i < hash_map.size(); i++){
            if(hash_map[i].first == key){
                return hash_map[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(size_t i = 0; i < hash_map.size(); i++){
            if(hash_map[i].first == key){
                hash_map.erase(hash_map.begin() + i);
                return ;
            }
        }
    }
};


int main(){
MyHashMap map{};
map.put(5,15);
std::cout<<map.get(5)<<'\n';
map.remove(5);
std::cout<<map.get(5)<<'\n';
return 0;
}
