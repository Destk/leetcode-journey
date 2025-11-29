#include<iostream>
#include<limits>
#include<functional>
#include<vector>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left1, TreeNode *right1) : val(x), left(left1), right(right1) {}
  };
 
int vvod(){
    std::cout<<"Введите targetSum: ";
    int tmp{};
    std::cin>>tmp;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ошибка ввода, попробуйте еще раз\n";
    }
    std::cout<<'\n';
    return tmp;
}

TreeNode* ins(TreeNode*root, int val){
    if(root == nullptr) return new TreeNode(val);
    if(root->val > val){
        root->left = ins(root->left, val);
    }else{
        root->right = ins(root->right, val);
    }
    return root;
}

TreeNode* BST(std::vector<int>& data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int val = data[i];
        root = ins(root, val);
    }
    return root;
}

TreeNode* Input(){
    TreeNode* root = nullptr;
    do{
    std::cout<<"Введите кол-во элементов в дереве: ";
    int x{};
    std::cin>>x;
        if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ошибка ввода, попробуйте еще раз\n";
    }
    std::cout<<'\n';
    std::vector<int> data{};
    for(int i = 0; i < x; i++){
        int tmp{};
        std::cout<<"Введите элемент: ";
        std::cin>>tmp;
        if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ошибка ввода, попробуйте еще раз\n";
        i--;
    }
    data.push_back(tmp);
    std::cout<<'\n';
    root = BST(data);
    }
}while(std::cin.fail());
    return root;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        int currentSum{};
        std::function<bool(TreeNode*,int)>Res;
        Res = [&,targetSum](TreeNode* root, int currentSum) -> bool{
            if(root == nullptr) return false;
            currentSum += root->val;
            if(root->left == nullptr && root->right == nullptr){
                return currentSum == targetSum;
            }else{
            bool l = Res(root->left, currentSum);
            bool r = Res(root->right, currentSum);
            return r || l;
            }
        };
        return Res(root,currentSum);
    }
void delTree(TreeNode* root){
    if(root == nullptr) return;
    delTree(root->left);
    delTree(root->right);
    delete root;
}

void Output(bool r){
    if( r == true ){
        std::cout<<"Сумма путей совпадает с введеной ,,targetSum,, " <<std::boolalpha<<r << '\n';
    }else{
        std::cout<<"Сумма путей совпадает с введеной ,,targetSum,, " <<std::boolalpha<<r<<'\n';
    }
}
int main(){
    char c{};
    std::cout<<"Это программа по поиску суммы путей\n";
    do{
        TreeNode* root = Input();
        int targetSum = vvod();
        bool r = hasPathSum(root,targetSum);
        Output(r);
        delTree(root);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<"\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}