#include<iostream>
#include<vector>
#include<limits>
#include<functional>
#include <climits>
struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {};
    TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l),right(r) {};
};

TreeNode* ins(TreeNode* r, int v){
    if(r == nullptr) return new TreeNode(v);
    if(r->val < v){
        r->right = ins(r->right, v);
    }else{
        r->left = ins(r->left, v);
    }
    return r;
}

TreeNode* BST(std::vector<int>& data){
    TreeNode* r = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int v = data[i];
        r = ins(r,v);
    }
    return r;
}

TreeNode* inp(){
    bool stop = false;
    TreeNode* root;
    while(!stop){
        std::cout<<"Введите кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            std::vector<int> data{};
            std::cout<<"СПРАВКА: ввод данных в бинарное дерево соответсвует правило построения -> \n *левая ветвь все меньшее \n *правая ветвь все большее\n";
            for(int i = 0; i < x ;i++){
                std::cout<<"Ввод элемента: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                }
                data.push_back(y);
            }
            root = BST(data);
            stop = true;
        }
    }
    return root;
}

int inpt(){
    bool stop = false;
    int x{};
    while(!stop){
        std::cout<<"Введите сумму для поиска в дереве: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            stop = true;
        }
    }
    return x;
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return std::vector<std::vector<int>>{};
    std::vector<std::vector<int>> res{};
    std::vector<int> currpath{};
    int currsum{};
    std::function<void(TreeNode* node, int currsum)> DFS;
    DFS = [&] (TreeNode* node, int currsum) {
        if(node == nullptr) return ;
        currpath.push_back(node->val);
        currsum += node->val;
        if(node->left == nullptr && node->right == nullptr){
            if(currsum == targetSum){
                res.push_back(currpath);
            }
        }
        DFS(node->left, currsum);
        DFS(node->right, currsum);
        currpath.pop_back();
    };
    DFS(root,currsum);
    return res;        
}

void out(std::vector<std::vector<int>> r){
    if(r.empty()) {
        std::cout << "Пути не найдены\n";
        return;
    }
    std::cout<<"Вот путь который равен введенному: ";
    for(size_t i = 0; i < r.size(); i++){
        std::cout << "Путь " << i+1 << ": ";
        for(size_t j = 0; j < r[i].size(); j++){
            std::cout<<r[i][j];
            if(j < r[i].size() - 1) std::cout << "->";
        }
    }
    std::cout<<'\n';
}

void delt(TreeNode* rt){
    if(rt == nullptr) return ;
    delt(rt->left);
    delt(rt->right);
    delete rt;
}

int main(){
    char c{};
    std::cout<<"Программа по поиску суммы путей равному введенному\n";
    do{
        TreeNode* root = inp();
        int targetSum = inpt();
        std::vector<std::vector<int>> r = pathSum(root, targetSum);
        out(r);
        delt(root);
        std::cout<<"Продрлжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}