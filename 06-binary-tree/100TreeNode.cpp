#include<iostream>
#include<limits>
#include<vector>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* insert(TreeNode* root, int value){
    if(root == nullptr){
        return new TreeNode(value);
    }

    if(value < root->val){
        root->left = insert(root->left,value);
    } else if(value > root->val){
        root->right = insert(root->right, value);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    if(data.empty()){
        return nullptr;}
        TreeNode* root = new TreeNode(data[0]);
        for(size_t i = 1; i < data.size(); i++){
            int value = data[i];
            root = insert(root, value);
        }
    return root;
}
TreeNode* Input(){
    int x{};
    std::vector<int> data;
    do{
    std::cout<<"Сколько элементов будет в бинарном дереве: \n";
    std::cin>>x;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ошибка ввода, попробуйте еще раз\n";
    }
    for(int i = 0; i < x; i++){
        int y{};
        std::cin>>y;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
            i--;
        }
        data.push_back(y);
    }
    }while(std::cin.fail());
    return BST(data);
}
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;  // базовый случай
    
    // Сначала удаляем потомков
    deleteTree(root->left);
    deleteTree(root->right);
    
    // Затем удаляем текущий узел
    delete root;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    //базовый случаи
    if( p == nullptr && q == nullptr){
        return true;
    }
    if(p == nullptr || q == nullptr){
        return false;
    }else{
        if(p->val != q->val){
            return false;
        }
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        if(l && r == true){
            return true;
        }else{
            return false;
        }
    }
}
void OutputR(bool r){
    if(r == true){
        std::cout<<"Бинарные деревья сходятся - " <<std::boolalpha<<r;
    }else{
        std::cout<<"Бинарные деревья не сходятся - " <<std::boolalpha<<r;
    }
    std::cout << std::endl;  
}
int main(){
    char c{};
    do{
        std::cout<<"Программа по определению схожести бинарных деревьев\n";
        TreeNode* p = Input();
        TreeNode* q = Input();
        bool r = isSameTree(p,q);
        OutputR(r);
        deleteTree(p);
        deleteTree(q);
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c =='y'||c =='Y');
    return 0;
}