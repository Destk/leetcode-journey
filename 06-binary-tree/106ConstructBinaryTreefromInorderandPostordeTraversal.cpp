#include<iostream>
#include<vector>
#include<limits>
#include<functional>
#include<queue>
#include<algorithm>

struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {};
};

std::vector<int> input(){
    bool stop = false;
    std::vector<int> r{};
    while(!stop){
        std::cout<<"Введите кол-во элементов: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"Введите элемент: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                    i--;
                }
                std::cout<<'\n';
                r.push_back(y);
            }
            stop = true;
        }
    }
    return r;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty() && postorder.empty()) return nullptr;
    std::function<TreeNode*(int,int,int,int)> build;
    build = [&] (int il, int ir, int pl, int pr) -> TreeNode* {
        if(il > ir) return nullptr;
        int rootval = postorder[pr];
        TreeNode* node = new TreeNode(rootval);
        auto it = std::find(inorder.begin() +  il, inorder.begin() + ir + 1,rootval);
        int indrv = it - inorder.begin();
        int leftsize = indrv - il;
        node->left = build(il, indrv-1, pl, pl+leftsize-1);
        node->right = build(indrv+1, ir, pl+leftsize, pr-1);
        return node;
    };
    TreeNode* root = build(0, inorder.size()-1, 0, postorder.size()-1);
    return root;
}

void output(TreeNode* r){
    if(r == nullptr) return ;
    int level{0};
    std::queue<TreeNode*> q;
    q.push(r);
    while(!q.empty()){
        int sizelevel = q.size();
        std::cout<<"Уровень "<<level<<" : ";
        for(size_t i = 0; i < sizelevel; i++){
            TreeNode* node = q.front();
            q.pop();
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
    if(r == nullptr) return ;
    delt(r->left);
    delt(r->right);
    delete r;
}
int main(){
    char c{};
    std::cout<<"Программа по построению бинарного дерева по двум обходам inorder && postorder\n";
    do{
        std::cout<<"Inorder\n";
        std::vector<int> inorder = input();
        std::cout<<"Postorder\n";
        std::vector<int> postorder = input();
        TreeNode* root = buildTree(inorder, postorder);
        output(root);
        delt(root);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}