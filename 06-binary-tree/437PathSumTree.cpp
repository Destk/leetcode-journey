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

int pathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return 0;
    int countpath{};
    std::function<void(TreeNode*, long long)> DFS;
    DFS = [&] (TreeNode* node, long long currsum) {
        if(node == nullptr) return ;
        currsum += node->val;
        if(currsum == targetSum){
            countpath+=1;
        }
        DFS(node->left, currsum);
        DFS(node->right, currsum);
    };
    std::function<void(TreeNode*)> travel;
    travel = [&] (TreeNode* node){
        if(node == nullptr) return ;
        DFS(node,0);
        travel(node->left);
        travel(node->right);
    };
    travel(root);
    return countpath;        
}

void out(int r){
    if(r == 0){
        std::cout<<"Нет подходящих путей\n";
    }else{
        std::cout<<"Количество путей равных targetSum -> "<<r<<'\n';
    }
}

void delt(TreeNode* rt){
    if(rt == nullptr) return ;
    delt(rt->left);
    delt(rt->right);
    delete rt;
}

int main(){
    char c{};
    std::cout<<"Программа по поиску кол-ва суммы путей равному введенному\n";
    do{
        TreeNode* root = inp();
        int targetSum = inpt();
        int r = pathSum(root, targetSum);
        out(r);
        delt(root);
        std::cout<<"Продрлжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}