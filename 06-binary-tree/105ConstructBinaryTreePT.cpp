#include<iostream>
#include<vector>
#include<limits>
#include<string>

struct TreeNode{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x),left(l),right(r) {};
};

std::vector<int> Input(const std::string& name){
    std::vector<int> out{};
    bool stop = false;
    while(!stop){
        std::cout << "Введите кол-во элементов для " << name << ": ";
        int x{};
        std::cin>>x;
        if(std::cin.fail() || x <= 0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, поробуйте ещё раз\n";
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"Ввод элемента: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, поробуйте ещё раз\n";
                    i--;
                }
                out.push_back(y);
                std::cout<<'\n';
            }
            stop = true;
        }
    }
    return out;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) return nullptr;
    TreeNode* root;
    root = new TreeNode(preorder[0]);
    int indroot = -1;
    for(int i = 0; i < inorder.size();i++){
        if(preorder[0] == inorder[i]){
            indroot = i;
            break;
        }
    }
    if(indroot == -1){
        std::cout<<"Вы ввели не правильный массив\n";
        return nullptr;
    }
    std::vector<int>lind(inorder.begin(), inorder.begin()+indroot);
    std::vector<int>rind(inorder.begin()+indroot+1, inorder.end());
    int lsize = indroot;
    int rsize = rind.size();
    std::vector<int>lpre(preorder.begin()+1, preorder.begin()+lsize+1);
    std::vector<int>rpre(preorder.begin()+lsize+1, preorder.end());
    root->left = buildTree(lpre,lind);
    root->right = buildTree(rpre,rind);
    return root;
}
void Output(TreeNode* r){
    if(r == nullptr) return ;
    std::cout<<r->val<<'\n';
    Output(r->left);
    Output(r->right);
}
void delT(TreeNode* r){
    if(r == nullptr) return ;
    delT(r->left);
    delT(r->right);
    delete r;
}
int main(){
    char c{};
    std::cout<<"Программа по построению первоначального дерева из двух обходов(preorder & inorder)\n";
    do{
        std::vector<int> preorder = Input("preorder");
        std::vector<int> inorder = Input("inorder");
        TreeNode* r = buildTree(preorder,inorder);
        Output(r);
        delT(r);
        std::cout<<"Продеолжит? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y'||c == 'Y');
    return 0;
}