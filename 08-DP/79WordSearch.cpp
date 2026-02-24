#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <limits>

class Solution {
private:
    std::vector<std::vector<char>> board{};
    std::string word{};
public:
    void inter(){
        std::cout<<"Программа на поиск слов.\n";
        std::cout<<"----Правила----\n";
        std::cout<<"1.Слово можно составить из букв, расположенных в последовательно идущих друг за другом ячейках, где соседние ячейки расположены по горизонтали или вертикали.\n";
        std::cout<<"2.Одну и ту же ячейку с буквой нельзя использовать более одного раза.\n";
    }
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите размер строк: ";
            int m{};
            std::cin>>m;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            std::cout<<"\nВведите кол-во столбцов: ";
            int n{};
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }
            else{
                board.resize(m,std::vector<char>(n));
                for(size_t i = 0; i < board.size(); i++){
                    for(size_t j = 0; j < board[0].size(); j++){
                        std::cout<<"\nВведите букву: ";
                        char x{};
                        std::cin>>x;
                        if(std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore();
                            std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                            continue;
                        }
                        board[i][j] = x;
                    }
                }
                std::cout<<"\nВведите слово: ";
                std::cin.ignore();
                std::getline(std::cin, word);
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    bool exist() {
        if(board.empty() || word.empty()) return false;
        std::vector<std::vector<bool>> use(board.size(), std::vector<bool>(board[0].size(), false));
        std::function<bool(int, int, int)> func;
        func = [&] (int i,int j, int ind){
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
                return false;
            }
            if(use[i][j]) return false;
            if(word[ind] != board[i][j]){
                return false;
            }
            if (ind == word.size() - 1) {
                return true;
            }
            std::vector<std::pair<int,int>> map = {{0,1}, {1,0}, {-1,0}, {0,-1}};
            use[i][j] = true;
            for(auto [ii, jj] : map){
                if(func(i + ii,j + jj, ind +1)){
                    return true;
                }
            }
            use[i][j] = false;
            return false;
        };
        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[0].size(); j++){
                if(func(i,j, 0) == true){
                    return true;
                }
            }
        }
        return false;
    }
    void out(bool r){
        if(r){
            std::cout<<"Слово "<<word<<" присутствует в board\n";
        }else{
            std::cout<<"Слово "<<word<<" невозможно составить из букв в board\n";
        }
    }
};

int main(){
    char stop{};
    do{
        Solution w;
        w.inter();
        w.inp();
        bool r = w.exist();
        w.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(stop == 'y' || stop == 'Y');
    return 0;
}