#include<iostream>
#include<functional>
#include<vector>
#include<limits>
#include<algorithm>
#include<queue>

struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

std::vector<int> input(){
    bool stop = false;
    std::vector<int> v{};
    while(!stop){
        std::cout<<"Введит кол-во элементов для дерева: ";
        int x{};
        std::cin>>x;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"Ввод элемента: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                    i--;
                }
                std::cout<<'\n';
                v.push_back(y);
            }
            stop = true;
        }
    }
    return v;
}

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    if(nums.empty()) return nullptr;
    std::function<TreeNode*(int,int)> build;
    build = [&] (int st, int end) {
        if(st > end) return (TreeNode*)nullptr;
        auto it = std::max_element(nums.begin()+st, nums.begin()+end+1);
        int maxind = std::distance(nums.begin(),it);
        TreeNode* node = new TreeNode(nums[maxind]);
        node->left = build(st, maxind-1);
        node->right = build(maxind+1, end);
        return node;
    };
    TreeNode* root = build(0,nums.size()-1);
    return root;       
}
void output(TreeNode* r){
    if(r == nullptr) return ;
    std::queue<TreeNode*> q;
    q.push(r);
    int level{0};
    while(!q.empty()){
        int sizel = q.size();
        std::cout<<"Уровень "<<level<<" : ";
        for(int i = 0; i < sizel; i++){
            TreeNode* node = q.front();
            q.pop();
            std::cout<<node->val<<" ";
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        std::cout<<'\n';
        level++;
    }
}
void delt(TreeNode* r){
    if( r == nullptr) return ;
    delt(r->left);
    delt(r->right);
    delete r;
}
int main(){
    char c{};
    std::cout<<"Программа по постройке максимального бинарного дерева\n";
    do{
        std::vector<int> nums = input();
        TreeNode* root = constructMaximumBinaryTree(nums);
        output(root);
        delt(root);
        std::cout<<"Продолжит? (y/n): ";
        std::cin >> c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}