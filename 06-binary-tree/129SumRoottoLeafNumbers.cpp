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

int sumNumbers(TreeNode* root) {
    if(root == nullptr) return 0;
    std::vector<std::string> v{};
    std::function<void(TreeNode*, std::string)> DFS;
    DFS = [&] (TreeNode* node, std::string currpath) {
        if(node == nullptr) return ;
        currpath += std::to_string(node->val);
        if(node->left == nullptr && node->right == nullptr){
            v.push_back(currpath);
        }
        DFS(node->left,currpath);
        DFS(node->right,currpath);
    };
    DFS(root,"");
    int sum{0};
    for(const std::string& c : v){
        sum+=std::stoi(c);
    }
    return sum;  
}

void out(int r){
    std::cout<<"суммa путей от корня до листа - "<<r<<'\n';
}

void delt(TreeNode* rt){
    if(rt == nullptr) return ;
    delt(rt->left);
    delt(rt->right);
    delete rt;
}

int main(){
    char c{};
    std::cout<<"Программа по поиску суммы путей от корня до листа\n";
    do{
        TreeNode* root = inp();
        int r = sumNumbers(root);
        out(r);
        delt(root);
        std::cout<<"Продрлжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}