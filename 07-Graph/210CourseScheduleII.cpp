#include<iostream>
#include<vector>
#include<limits>
#include<queue>

void input(int& x,std::vector<std::vector<int>>& prerequisites){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во уроков: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }
        std::cout<<"\nВведи кол-во зависимостей: ";
        int y{};
        std::cin>>y;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }
        else{
            prerequisites.resize(y);
            std::cout << "\nВведите расписание занятий (курс, зависимость):\n";
            for(int i = 0; i < y; i++){
                prerequisites[i].resize(2);  
                std::cout << "Зависимость " << i << ": ";
                std::cin >> prerequisites[i][0] >> prerequisites[i][1];
            }
            std::cout<<'\n';
            stop = true;
        }
    }
}

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {  
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> i(numCourses, 0);
    std::queue<int> q{};
    std::vector<int> res{};
    for(auto& pre : prerequisites){
        int a = pre[0];
        int b = pre[1];
        graph[b].push_back(a);
        i[a]++;
    }
    for(int kurs = 0; kurs < numCourses; kurs++){
        if(i[kurs] == 0){
            q.push(kurs);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(int neib : graph[curr]){
            i[neib]--;
            if(i[neib] == 0) q.push(neib);
        }
    }
    if(res.size() != numCourses) return {};
    return res;
}

void output(std::vector<int> r){
    std::cout<<"Уроки которые нужно пройти: \n";
    for(auto n : r){
        std::cout<<n<<" ";
    }
    std::cout<<'\n';
}
int main(){
    char stop{};
    std::cout<<"Программа для прохождения занятий\n";
    do{
        std::vector<std::vector<int>> prerequisites{};
        int numCourses{};
        input(numCourses, prerequisites);
        std::vector<int> r = findOrder(numCourses, prerequisites);
        output(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(stop == 'y' || stop == 'Y');
    return 0;
}