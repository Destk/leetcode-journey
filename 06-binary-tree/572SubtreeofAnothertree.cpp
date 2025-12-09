#include<iostream>
#include<limits>
#include<functional>
#include<vector>
struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}; 
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
TreeNode* BST(std::vector<int> data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size();i++){
        int v = data[i];
        root = ins(root,v);
    }
    return root;
}
TreeNode* input(){
    TreeNode* root;
    do{
        std::cout<<"Введите кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }
        std::cout<<'\n';
        std::vector<int> data{};
        for(int i = 0; i < x; i++){
            std::cout<<"Введит элемент дерева: ";
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
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr ) return false;
    std::function<bool(TreeNode* root, TreeNode* subRoot)> isSame;
    isSame = [&] (TreeNode* rt, TreeNode*st) {
        if (rt == nullptr && st == nullptr) return true;
        if (rt == nullptr || st == nullptr) return false;
        if(rt->val != st->val) return false;
        bool l = isSame(rt->left, st->left);
        bool r = isSame(rt->right, st->right);
        return l && r;
    };
    bool res = isSame(root,subRoot);
    bool Lroot = isSubtree(root->left,subRoot);  
    bool Rroot = isSubtree(root->right,subRoot);
    return res || Lroot || Rroot;      
}

void Output(bool r){
    if( r == true){
        std::cout<<"Поддерево есть в основном дереве" << std::boolalpha <<r<<'\n';
    }else{
        std::cout<<"Поддерево нет в основном дереве" << std::boolalpha <<r<<'\n';
    }
}
void delt(TreeNode* root){
    if(root == nullptr) return ;
    delt(root->left);
    delt(root->right);
    delete root;
}
int main(){
    char c{};
    std::cout<<"Программа для сравнения поддерева с основным деревом\n";
    do{
        TreeNode* root = input();
        TreeNode* subRoot = input();
        bool r = isSubtree(root, subRoot);
        Output(r);
        delt(root);
        delt(subRoot);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<'\n';
    }while(c == 'y' || c == 'Y');
    return 0;
}
