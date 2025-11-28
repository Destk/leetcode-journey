#include<iostream>
#include<vector>
#include<limits>
#include<functional>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

TreeNode* ins(TreeNode* roott, int val){
    if (roott == nullptr) return new TreeNode(val); 
    if(roott->val > val){
        roott->left = ins(roott->left, val);
    }else if(roott->val < val){
        roott->right = ins(roott->right,val);
    }
    return roott;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode* roott = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int val = data[i];
        ins(roott, val);
    }
    return roott;
}
TreeNode* Input(){
    std::vector<int> data{};
    do{
        int x{};
        std::cout<<"Кол-во элементов в дереве: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё\n";
        }
        std::cout<<"\n";
        for(int i = 0; i < x; i++){
            int tmp{};
            std::cout<<"Вводите элементы: ";
            std::cin>>tmp;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте ещё\n";
                i--;
            }
            data.push_back(tmp);
            std::cout<<'\n';
        }
    }while(std::cin.fail());
    TreeNode* root = BST(data);
    return root;
}
std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> num{};
    if(root == nullptr){
        return{};
    }
    std::function<void(TreeNode*)> Res;
    Res = [&](TreeNode* root){
        if(root == nullptr) return ;
        Res(root->left);
        num.push_back(root->val);
        Res(root->right);
    };
    Res(root);
    return num;    
}

void delT(TreeNode* root){
    if(root == nullptr) return ;
    delT(root->left);
    delT(root->right);
    delete root;
}

void Output(std::vector<int>& res){
    std::cout<<"Вывод: ";
    for(size_t i = 0; i < res.size();i++){
        std::cout<<res[i] << " ";
    }
    std::cout<<'\n';
}
int main(){
    char c{};
    std::cout<<"Это программа по обходу бинарного дерева в прямом порядке\n";
    do{
        TreeNode* root = Input();
        std::vector<int> res = inorderTraversal(root);
        Output(res);
        delT(root);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}