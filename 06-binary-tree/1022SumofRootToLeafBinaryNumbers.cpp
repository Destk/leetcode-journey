#include<iostream>
#include<vector>
#include<limits>
#include<functional>
#include <climits>
#include<queue>

const int NULL_VAL = -1001;

struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {};
    TreeNode(int x,TreeNode* l, TreeNode* r) : val(x), left(l),right(r) {};
};

TreeNode* ins(TreeNode* r, int v){
    if(r == nullptr) return new TreeNode(v);
    if(r->val < v){
        r->right = ins(r->right, v);
    }else{
        r->left = ins(r->left, v);
    }
    return r;
}

TreeNode* BT(std::vector<int>& data){
    if(data.empty()) return nullptr;
    TreeNode* root = new TreeNode(data[0]);
    std::queue<TreeNode*> q{};
    q.push(root);
    size_t i = 1;
    while(!q.empty() && i < data.size()){
        TreeNode* node = q.front();
        q.pop();
        
        if(i < data.size()){
            if(data[i] != NULL_VAL){
                node->left = new TreeNode(data[i]);
                q.push(node->left);
            }
            i++;
        }

        if(i < data.size()){
            if(data[i] != NULL_VAL){
                node->right = new TreeNode(data[i]);
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

TreeNode* inp(){
    bool stop = false;
    TreeNode* root;
    while(!stop){
        std::cout<<"Введите кол-во элементов в дереве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            std::vector<int> data{};
             std::cout << "Введите " << x << " элементов (используйте " << NULL_VAL << " для отсутствующего узла):\n";
            for(int i = 0; i < x ;i++){
                std::cout<<"Ввод элемента: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                }
                data.push_back(y);
            }
            root = BT(data);
            stop = true;
        }
    }
    return root;
}

int inpt(){
    bool stop = false;
    int x{};
    while(!stop){
        std::cout<<"Введите сумму для поиска в дереве: ";
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }else{
            stop = true;
        }
    }
    return x;
}

int sumRootToLeaf(TreeNode* root) {
    if(root == nullptr) return 0;
    
    std::vector<std::string> v{};

    std::function<void(TreeNode*, std::string)> DFS;
    DFS = [&] (TreeNode* node, std::string num){
        if(node == nullptr) return ;
        num+=std::to_string(node->val);;
        if(node->left == nullptr && node->right == nullptr){
            v.push_back(num);
        }
        DFS(node->left, num);
        DFS(node->right, num);
    };

    DFS(root, "");
    
    int total{};
    for(std::string& s : v){
        total += std::stoi(s,nullptr,2);
    }
    return total;
}

void out(int r){
    std::cout<<"суммa двоичных чисел от корня до листа - "<<r<<'\n';
}

void delt(TreeNode* rt){
    if(rt == nullptr) return ;
    delt(rt->left);
    delt(rt->right);
    delete rt;
}

int main(){
    char c{};
    std::cout<<"Программа по сумме двоичных чисел от корня до листа\n";
    do{
        TreeNode* root = inp();
        int r = sumRootToLeaf(root);
        out(r);
        delt(root);
        std::cout<<"Продрлжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}