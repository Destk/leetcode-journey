#include<iostream>
#include<vector>
#include<limits>
#include<functional>
#include <climits>
#include<queue>

struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {};
    TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l),right(r) {};
};

void input(std::vector<int>& v){
    bool stop = false;
    while(!stop){
        std::cout<<"Введите кол-во элементов в preorder: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            std::cout<<'\n';
            for(int i = 0; i < x; i++){
                std::cout<<"Введите элемент массива: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                    i--;
                }
                v.push_back(y);
                std::cout<<'\n';
            }
            stop = true;
        }
    }
}

TreeNode* bstFromPreorder(std::vector<int>& preorder) {
    std::function<TreeNode*(int, int)> build;
    build = [&] (int start, int end) -> TreeNode* {
        if (start >= end) return nullptr;
        TreeNode* node;
        int root = preorder[start];
        node = new TreeNode(root);
        int indr = start+1;
        while(indr < end && preorder[indr] < root){
            indr++;
        }
        node->left = build(start+1,indr);
        node->right = build(indr,end);
        return node;
    };
    return build(0, preorder.size());        
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

void delt(TreeNode* rt){
    if(rt == nullptr) return ;
    delt(rt->left);
    delt(rt->right);
    delete rt;
}
int main(){
    char c{};
    std::cout<<"Программа по постройке БДП из обхода preorder(root | left | right)\n";
    do{
        std::vector<int> preorder{};
        input(preorder);
        TreeNode* root = bstFromPreorder(preorder);
        output(root);
        std::cout<<"Продрлжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}