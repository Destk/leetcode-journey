#include<iostream>
#include<queue>
#include<limits>
#include<vector>
#include<fstream>
#include<string>

std::ofstream Logfile("Log.txt",std::ios::app);
void logger(const std::string& s){
    if(!Logfile){
        std::cerr<<"Ошибка открытия файла\n";
    }
    Logfile<<s<<'\n';    
}
struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};


TreeNode* ins(TreeNode* r, int v){
    if(r == nullptr) return new TreeNode(v);
    if(r->val > v){
        r->left = ins(r->left, v);
    }else{
        r->right = ins(r->right, v);
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
    TreeNode* r;
    while(!stop){
        std::cout<<"Введите кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
            continue;
        }else{
            logger("Пользовталеь ввел кол-во элементов в дереве");
            std::vector<int> data{};
            for(int i = 0; i < x; i++){
                std::cout<<"\nВводите элементы: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\nОшибка ввода, попробуйте еще раз\n";
                    continue;
                }
                data.push_back(y);
            }
            logger("Пользовталеь ввел элементы для дерева");
            r = BST(data);
            stop = true;
        }
    }
    return r;
}

std::vector<int> getLonelyNodes(TreeNode* root) {
    std::vector<int> res{};
    if(root == nullptr) return res;
    std::queue<TreeNode*> q{};
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        bool l= node->left != nullptr;
        bool r = node->right != nullptr;
        if(l!=r){
            res.push_back(node->val);
        }
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }
    return res;
}

void out(std::vector<int>& r){
    if(r.empty()) std::cout<<"Таких узлов нет\n";
    else{
        std::cout<<"Узлы у которых нет соседей: ";
        for(int el : r) std::cout << el << " ";
        std::cout<<'\n';
    }
}
void delt(TreeNode* r){
    if(r == nullptr) return ;
    delt(r->left);
    delt(r->right);
    delete r;
}
int main(){
    char stop{};
    std::cout<<"Программа по поиску всех узлов, у которых нет соседей (нет левого ИЛИ нет правого потомка, но не оба)\n";
    do{
        TreeNode* root = inp();
        std::vector<int> r = getLonelyNodes(root);
        delt(root);
        out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(stop == 'y' || stop == 'Y');
    Logfile.close();
    return 0;
}