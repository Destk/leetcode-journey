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
        std::cout<<"Кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }
        std::vector<int> data;
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
std::vector<std::string> binaryTreePaths(TreeNode* root) {
    if(root == nullptr) return std::vector<std::string> {};
    std::vector<std::string> res{};
    std::function<void(TreeNode* root, std::string currpath)> DFS;
    DFS = [&] (TreeNode* root, std::string currpath){
        if(root == nullptr) return ;
        if(!currpath.empty()){
            currpath+="->";
        }
        currpath+=std::to_string(root->val);
        if(!root->left && !root->right){
             res.push_back(currpath);
        }
        DFS(root->left,currpath);
        DFS(root->right,currpath);
    };
    DFS(root,"");
    return res;
}
void del(TreeNode* r){
    if(r == nullptr) return ;
    del(r->left);
    del(r->right);
    delete r;
}
void Output(std::vector<std::string> r){
    for(const auto& path : r){
        std::cout<<path<<'\n';
    }
}
int main(){
    char c{};
    std::cout<<"Программу по выводу путей бинарного дерева\n";
    do{
        TreeNode* root = Input();
        std::vector<std::string> r1 = binaryTreePaths(root);
        Output(r1);
        del(root);
        std::cout<<"Продолжить? (y/n)";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\n";
    }while(c == 'y' || c == 'Y');
    return 0;
}