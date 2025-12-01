#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
#include<functional>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r ) : val(x), left(l), right(r) {};
};

void Input(std::vector<int>& nums){
    do{
        std::cout<<"Введите кол-во элементов: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
        }
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
            nums.push_back(y);
        }
        std::sort(nums.begin(),nums.end());
    }while(std::cin.fail());
}
TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    if(nums.empty()) return nullptr;
    int l = 0;
    int r = nums.size()-1;
    std::function<TreeNode*(int, int)> Build;
    Build = [&] (int l, int r) -> TreeNode* {
        if(l > r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Build(l,mid-1);
        root->right = Build(mid+1,r);
        return root;
    };
    return Build(l,r);
}
void Output(TreeNode*root){
    if(root == nullptr) return;
    Output(root->left);
    std::cout<<root->val;
    Output(root->right);
}
void delT(TreeNode*root){
    if(root == nullptr) return;
    delT(root->left);
    delT(root->right);
    delete root;
}
int main(){
    char c{};
    std::cout<<"Программа по постройке сбалансированного бинарного дерева\n";
    do{
        std::vector<int> nums{};
        Input(nums);
        TreeNode* root = sortedArrayToBST(nums);
        Output(root);
        delT(root);
        std::cout<<"\nПродолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c =='Y');
    return 0;
}