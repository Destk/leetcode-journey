int minDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    
    std::function<int(TreeNode*)> Res;
    Res = [&](TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        if(root->left == nullptr) return Res(root->right) + 1;
        if(root->right == nullptr) return Res(root->left) + 1;
        
        return min(Res(root->left), Res(root->right)) + 1;
    };
    
    return Res(root);
}
