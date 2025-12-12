#include<iostream>
#include<limits>
#include<vector>
#include<queue>

struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

TreeNode* insert(TreeNode* root, int v){
    if(root == nullptr) return new TreeNode(v);
    if(v < root->val){
        root->left = insert(root->left,v);
    }else{
        root->right = insert(root->right,v);
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode* root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size(); i++){
        int v = data[i];
        root = insert(root, v);
    }
    return root;
}
TreeNode* input(){
    bool stop = false;
    TreeNode* root;
    while(!stop){
        std::cout<<"Введите кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        std::cout<<'\n';
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
        }else{
            std::vector<int> data{};
            for(int i = 0; i < x; i++){
                std::cout<<"Ввод элемента: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте еще раз\n";
                }
                data.push_back(y);
                std::cout<<'\n';
            }
            root = BST(data);
            stop = true;
        }
    }
    return root;
}

std::vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) return {};
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<int> rv{};
    while(!q.empty()){
        int sizelevel =  q.size();
        for(int i = 0; i < sizelevel; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(i == sizelevel - 1){
                rv.push_back(curr->val);
            }
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
    }
    return rv;
}

void output(std::vector<int>& r){
    std::cout<<"Вид справа: ";
    for(size_t i = 0; i < r.size(); i++){
        std::cout<<r[i];
        if(i < r.size() - 1){
            std::cout<<" -> ";
        }
    }
    std::cout<<'\n';
}
void delt(TreeNode* r){
    if(r == nullptr) return ;
    delt(r->left);
    delt(r->right);
    delete r;
}
int main(){
    char c{};
    std::cout<<"Программа на вид бинарного дерева справа\n";
    do{
        TreeNode* root = input();
        std::vector<int> r = rightSideView(root);
        delt(root);
        output(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}