#include<iostream>
#include<limits>
#include<vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left1, TreeNode *right1) : val(x), left(left1), right(right1) {}
};
TreeNode* insert(TreeNode* root, int dval){
    if(root == nullptr) return new TreeNode(dval);
    if(root->val > dval){
        root->left = insert(root->left, dval);
    }else if( root->val < dval){
        root->right = insert(root->right, dval);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size();i++){
        int dval = data[i];
        insert(root,dval);
    }
    return root;
}
TreeNode* Input(){
    int x{};
    do{
        std::cout<<"Кол-во элементов в дереве: \n";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
        }
    }while(std::cin.fail());
    std::vector<int> data{};
    for(int i = 0; i < x; i++){
        int tmp{};
        std::cout<<"Введите значение: ";
        std::cin>>tmp;
        if(std::cin.fail() || tmp == 0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
            i--;
        }
        data.push_back(tmp);
        std::cout<<'\n';
    }
    TreeNode* root = BST(data);
    return root;
}
void printTree(TreeNode* root){
    if (root == nullptr) {
        std::cout << "NULL";
        return;
    }
    std::cout << "L(";
    printTree(root->left);
    std::cout << ") ";
    std::cout << root->val;  
    std::cout << " R(";
    printTree(root->right);
    std::cout << ")";
}
TreeNode* invertTree(TreeNode* root) {
    //1) базовый случай
    if(root == nullptr){
        return root;
    }
    //2)создаем вспомогательные узлы для обмена веток и запуска рекурсии
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    //3)меням значения
    std::swap(root->left,root->right);
    //4)возвращаем корень
    return root;
}
void delTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    delTree(root->left);
    delTree(root->right);
    delete root;
}
int main(){
    char c{};
    std::cout<<"Программа по инвуртированию бинарного дерева\n";
    do{
        TreeNode* root = Input();
        printTree(root);
        root = invertTree(root);
        std::cout<<"Инвертированное дерево\n";
        printTree(root);
        std::cout<<std::endl;
        delTree(root);
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c=='y' || c=='Y');
    return 0;
}