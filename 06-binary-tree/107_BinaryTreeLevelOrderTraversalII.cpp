#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<algorithm>
struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

TreeNode* ins(TreeNode* root, int val){
    if(root == nullptr){
        return new TreeNode(val);
    }
    if(val < root->val){
        root->left = ins(root->left,val);
    }else{
        root->right = ins(root->right,val);;
    }
    return root;
}
TreeNode* BST(std::vector<int>& data){
    TreeNode*root = new TreeNode(data[0]);
    for(size_t i = 1; i < data.size();i++){
        int val =data[i];
        root = ins(root, val);
    }
    return root;
}
TreeNode* Input(){
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
std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    //базовый случай
    if(root == nullptr) return std::vector<std::vector<int>> {};
    //создаем очередь посетитель и итоговый список посетителей
    std::queue<TreeNode*> q;
    std::vector<std::vector<int>> res{};
    //добавляем перевого посетителя в очередб
    q.push(root);
    //запускаем обход по дереву пока очередь посетителей не закочнится
    while(!q.empty()){
        int count = q.size();
        std::vector<int> data{};
        for(int i = 0; i < count; i++){
            TreeNode* currnode = q.front();
            q.pop();
            int currdata = currnode->val;
            data.push_back(currdata);
            if(currnode->left) q.push(currnode->left);
            if(currnode->right) q.push(currnode->right);  
        }
        res.push_back(data);
    }
        reverse(res.rbegin(), res.rend());
        return res;
}

void OutPut(std::vector<std::vector<int>>& r){
    std::cout << "Получившийся обход: result = [";
    for(size_t i = 0; i < r.size(); i++){
        if(i > 0) std::cout << ", ";
        std::cout << "[";
        for(size_t j = 0; j < r[i].size(); j++){
            if(j > 0) std::cout << ", ";
            std::cout << r[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}
void Delt(TreeNode* root){
    if(root == nullptr) return ;
    Delt(root->left);
    Delt(root->right);
    delete root;
}
int main(){
    char c{};
    std::cout<<"Программа по обходу дерева в ширину\n";
    do{
        TreeNode* root = Input();
        std::vector<std::vector<int>> r = levelOrderBottom(root);
        OutPut(r);
        Delt(root);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<'\n';
    }while(c == 'y' || c=='Y');
}
