#include<iostream>
#include<vector>
#include<limits>
#include<queue>

void input(std::vector<std::vector<int>>& grid){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во горизонтальных линий на карте(строк) ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }
        std::cout<<"Введите кол-во вертикальных линий на карте(столбцов) ";
        int x1{};
        std::cin>>x1;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }
        if(x <= 0 || x1 <= 0) {
            std::cout << "Размер матрицы должен быть > 0\n";
            continue;
        }
        else{
            grid.resize(x);
            for(size_t i = 0; i < x; i++) {
                grid[i].resize(x1);
            }
            std::cout << "Введите матрицу (0 или 1):\n";
            for(size_t i = 0; i < x; i++){
                for(size_t j = 0; j < x1; j++){
                    std::cout<<"Введите кординаты клетки по x & y\n";
                    std::cout << "[" << i << "][" << j << "]: ";
                    std::cin>>grid[i][j];
                    std::cout<<'\n';
                }
            }
            stop = true;
        }
    }
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    int maxis{};
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[0].size();j++){
            int curris{};
            if(grid[i][j] == 1){
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()){
                    std::pair<int,int> curr = q.front();
                    q.pop();
                    curris++;
                    int ci = curr.first;
                    int cj = curr.second;
                    int nci = ci - 1;
                    int ncj = cj;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && !visited[nci][ncj] && grid[nci][ncj] == 1){
                        visited[nci][ncj] = true;
                        q.push({nci,ncj});
                    }
                    nci = ci + 1;
                    ncj = cj;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && !visited[nci][ncj] && grid[nci][ncj] == 1){
                        visited[nci][ncj] = true;
                        q.push({nci,ncj});    
                    }
                    nci = ci;
                    ncj = cj - 1;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && !visited[nci][ncj] && grid[nci][ncj] == 1){
                        visited[nci][ncj] = true;
                        q.push({nci,ncj});  
                    }
                    nci = ci;
                    ncj = cj + 1;
                    if(nci >= 0 && nci < grid.size() && ncj >= 0 && ncj < grid[0].size() && !visited[nci][ncj] && grid[nci][ncj] == 1){
                        visited[nci][ncj] =true;
                        q.push({nci,ncj});
                    }
                }
            }
        maxis = std::max(maxis,curris);
        }
    }
    return maxis;
}

void output(int r){
    if(r != 0){
        std::cout<<"Площадь самого крупного острова на карте составляет "<<r<<'\n';
    }else{
        std::cout<<"Один океан, на ближайших просторах нет островов\n"; 
    }
}

int main(){
    char c{};
    std::cout<<"Программа по нахождению крупного острова\n";
    do{
        std::vector<std::vector<int>> grid{};
        input(grid);
        int r = maxAreaOfIsland(grid);
        output(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}