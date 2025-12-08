#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include <functional>

struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) :  val(x) , left(nullptr), right(nullptr) {};
    TreeNode(int x,TreeNode* l,TreeNode* r) :  val(x) , left(l), right(r) {};
};
TreeNode* ins(TreeNode* root, int v){
    if(root == nullptr) return new TreeNode(v);
    if(v < root->val){
        root->left = ins(root->left,v);
    }else{
        root->right = ins(root->right,v);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    if (data.empty()) return nullptr;
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int v = data[i];
        root = ins(root, v);
    }
    return root;
}
TreeNode* Input(){
    TreeNode* root;
    do{
        std::cout<<"\nКол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }
        std::vector<int> data;
        std::cout<<'\n';
        for(int i = 0; i < x; i++){
            std::cout<<"Вводите значение: ";
            int y{};
            std::cin>>y;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                i--;
            }
            data.push_back(y);
            std::cout<<'\n';
        }
        root = BST(data);
    }while(std::cin.fail());
    return root;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root == nullptr) return 0;
    std::function<int(TreeNode* root)> mdfs;
    int maxdiam{};
    mdfs = [&] (TreeNode* root) {
        if(root == nullptr) return 0;
        int l = mdfs(root->left);
        int r = mdfs(root->right);
        int currdiam = l + r ;
        maxdiam = std::max(maxdiam,currdiam);
        return std::max(l,r) + 1;
    };
    mdfs(root);
    return maxdiam;        
} 

void del(TreeNode* r){
    if(r == nullptr) return ;
    del(r->left);
    del(r->right);
    delete r;
}
void Output(int r){
    std::cout<<"Диаметр бинарного дерева - "<< r<<'\n';
}
int main(){
    char c{};
    std::cout<<"Программу по поиску диаметреа бинарного дерева\n";
    do{
        TreeNode* root = Input();
        int r = diameterOfBinaryTree(root);
        Output(r);
        del(root);
        std::cout<<"\nПродолжить? (y/n) ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\n";
    }while(c == 'y' || c == 'Y');
    return 0;
}