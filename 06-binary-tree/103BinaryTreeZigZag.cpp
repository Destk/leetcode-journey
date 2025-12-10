#include<iostream>
#include<vector>
#include<limits>
#include<queue>

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
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr) return  std::vector<std::vector<int>>{};
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<std::vector<int>> res{};
    bool ltor{true};
    while(!q.empty()){
        int currsize = q.size();
        std::vector<int> curr{};
        for(int i = 0; i < currsize; i++){
            TreeNode* node = q.front();
            if(ltor){
                curr.push_back(node->val);
            }else{
                curr.insert(curr.begin(), node->val);
            }
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(curr);
        ltor = !ltor;
    }
    return res;  
}
void del(TreeNode* r){
    if(r == nullptr) return ;
    del(r->left);
    del(r->right);
    delete r;
}
void Output(std::vector<std::vector<int>> r){
    for(size_t i = 0; i < r.size();i++){
        std::cout<<"Уровень "<<i<<": ";
        for(size_t y = 0; y < r[i].size();  y++){
            std::cout<<r[i][y]<<' ';
        }
        std::cout<<"\n";
    }
}
int main(){
    char c{};
    std::cout<<"Программу по обходу бинарного дерева путём зиг-зага\n";
    do{
        TreeNode* root = Input();
        std::vector<std::vector<int>> r = zigzagLevelOrder(root);
        Output(r);
        del(root);
        std::cout<<"Продолжить? (y/n)";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\n";
    }while(c == 'y' || c == 'Y');
    return 0;
}
