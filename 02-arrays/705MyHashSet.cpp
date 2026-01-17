#include <iostream>
#include <vector>
#include <limits>
class MyHashSet {
private:
std::vector<std::vector<int>> hash_set{};
int bucket = 1000;
public:
    MyHashSet() {
        hash_set.resize(bucket);
    }
    
    size_t getSet(int key){
        return key % bucket;
    }

    void add(int key) {
        size_t ind = getSet(key);
        auto& set = hash_set[ind];
        for(size_t i = 0; i < set.size(); ++i){
            if(set[i] == key){
                return ;
            }
        }
        set.push_back(key);
    }
    
    void remove(int key) {
        size_t ind = getSet(key);
        auto& set = hash_set[ind];
        for(size_t i = 0; i < set.size(); ++i){
            if(set[i] == key){
               set.erase(set.begin()+i);
               return;
            }
        }
    }
    
    bool contains(int key) {
        size_t ind = getSet(key);
        auto& set = hash_set[ind];
        for(size_t i = 0; i < set.size(); ++i){
            if(set[i] == key){
                return true;
            }
        }
        return false;
    }
};

void inp(MyHashSet& s){
    bool c = true;
    while(c){
        std::cout<<"Введите ключ: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
            continue;
        }else{
            std::cout<<'\n';
            s.add(x);
            s.contains(x);
            c = false;
        }
    }
}

void del(MyHashSet& s){
        bool c = true;
        std::cout<<"Удаление ключа\n";
    while(c){
        std::cout<<"Введите ключ: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
            continue;
        }else{
            std::cout<<'\n';
            s.remove(x);
            s.contains(x);
            c = false;
        }
    }
}
int main(){
    char stop{};
    std::cout<<"Программа про: <<Hash set>>\n";
    do{
        MyHashSet s;
        inp(s);
        del(s);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
return 0;
}