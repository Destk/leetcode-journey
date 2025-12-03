#include<iostream>
#include<vector>
#include<limits>
#include<functional>

struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(TreeNode*l,TreeNode*r,int x) : val(x), left(l), right(r) {};
};

TreeNode* ins(TreeNode* root,int v){
    if(root == nullptr) return new TreeNode(v);
    if(v > root->val){
        root->right = ins(root->right,v);
    }else{
        root->left = ins(root->left,v);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int v = data[i];
        root = ins(root,v);
    }
    return root;
}
TreeNode* Input(){
    TreeNode* root;
    do{
        std::cout<<"Введи кол-во элементов в дереве: ";
        int x{};
        std::cin >> x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }
        std::vector<int> data{};
        for(int i = 0; i < x; i++){
            std::cout<<"Вводите элемент: ";
            int y{};
            std::cin>>y;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                i--;
            }
            data.push_back(y);
        }
        root = BST(data);
    }while(std::cin.fail());
    return root;
}
std::vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr) return std::vector<int>{};
    std::vector<int> r{};
    std::function<void(TreeNode*)> Res;
    Res = [&] (TreeNode* root){
        if(root == nullptr) return ;
        Res(root->left);
        Res(root->right);
        r.push_back(root->val);
    };
    Res(root);
    return r;
}
void Output(std::vector<int>& r){
    std::cout<<"Вывод = [ ";
    for(size_t i = 0; i < r.size(); i++){
        std::cout<<r[i];
        if(i < r.size()-1){
            std::cout<<", ";
        }
    }
    std::cout<<" ]\n";
}
void DelT(TreeNode* r){
    if(r == nullptr) return ;
    DelT(r->left);
    DelT(r->right);
    delete r;
}
int main(){
    char c{};
    std::cout<<"Программа по обходу бинарного дерева в обратно порядке\n";
    do{
        TreeNode* root = Input();
        std::vector<int> r = postorderTraversal(root);
        Output(r);
        DelT(root);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<'\n';
    }while(c == 'y' || c =='Y');
    return 0;
}