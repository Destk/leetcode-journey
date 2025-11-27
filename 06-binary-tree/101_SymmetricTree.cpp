#include<iostream>
#include<limits>
#include<vector>
#include <functional>  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left1, TreeNode *right1) : val(x), left(left1), right(right1) {}
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
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size();i++){
        int value = data[i];
        root = insert(root, value);
    }
    return root;
}
TreeNode* Input(){
    TreeNode* root;
    do{
    std::cout<<"Сколько элементов в дереве будет: \n";
    int x{};
    std::cin>>x;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЕ РАЗ\n";
    }
    std::vector<int> data{};
    for(int i = 0; i < x; i++){
        std::cout<<"Ввод числа: ";
        int y{};
        std::cin>>y;
        if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЕ РАЗ\n";
        i--;
        }
        data.push_back(y);
        std::cout<<'\n';
        root = BST(data);
    }
    return root;
    }while(std::cin.fail());
}
bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }else if(root->left == nullptr || root->right == nullptr){
            return false;
        }if(root->left->val != root->right->val){
            return false;
        }
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        std::function<bool(TreeNode*, TreeNode*)> Res;
        Res = [&](TreeNode* l, TreeNode* r)->bool{
            if(l == nullptr && r == nullptr){
                return true;
            }else if(l == nullptr || r == nullptr){
                return false;
            }
            bool res_l = Res(l->left, r->right);
            bool res_r = Res(l->right, r->left);
            return res_l && res_r && (l->val == r->val);
        };
        return Res(l,r);
}
void delTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    delTree(root->left);
    delTree(root->right);
    delete root;
}
void Output(bool r){
    if( r == true){
        std::cout<<"Дерево симметрично "<< std::boolalpha<<r<<'\n';
    }else{
        std::cout<<"Дерево не симметрично "<< std::boolalpha<<r<<'\n';
    }
}
int main(){
    char c{};
    std::cout<<"Программа на проверку симметрии дерева\n";
    do{
        TreeNode* root = Input();
        bool r = isSymmetric(root);
        Output(r);
        delTree(root);
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}