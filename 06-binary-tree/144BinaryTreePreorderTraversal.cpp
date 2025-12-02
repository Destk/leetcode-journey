#include<iostream>
#include<vector>
#include<limits>
#include<functional>
struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

TreeNode* ins(TreeNode* root,int val){
    if(root == nullptr){
        return new TreeNode(val);
    }
    if(root->val > val){
        root->left = ins(root->left,val);
    }else{
        root->right = ins(root->right,val);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int val = data[i];
        root = ins(root,val);
    }
    return root;
}
TreeNode* Input(){
    TreeNode* root;
    do{
        std::cout<<"Сколько элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз!\n";
        }
        std::vector<int> data{};
        for(int i = 0; i < x; i++){
            int y{};
            std::cout<<"Вводите число: ";
            std::cin>>y;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте ещё раз!\n";
                i--;
            }
            data.push_back(y);
            std::cout<<'\n';
        }
        root = BST(data);
    }while(std::cin.fail());
    return root;
}

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> r{};
    if(root == nullptr){
        return std::vector<int>{};
    }
    std::function<void(TreeNode*root)> Res;
    Res = [&] (TreeNode* root){
        if(root == nullptr){
            return;
        }
        r.push_back(root->val);
        Res(root->left);
        Res(root->right);
    };
    Res(root);
    return r;
}
void DelT(TreeNode* root){
    if(root == nullptr){
        return;
    }
    DelT(root->left);
    DelT(root->right);
    delete root;
}
void Output(std::vector<int>& r){
    std::cout<<"Бинарное дерево = [ ";
    for(size_t i = 0; i < r.size(); i++ ){
        std::cout<<r[i];
        if(i < r.size()-1){
            std::cout<<", ";
        }
    }
    std::cout<<" ]\n";
}
int main(){
    char c{};
    std::cout<<"Программа по обоходу бинарного дерева в прямом порядке\n";
    do{
        TreeNode* root = Input();
        std::vector<int> r = preorderTraversal(root);
        Output(r);
        DelT(root);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}