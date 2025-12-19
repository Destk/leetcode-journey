TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
    std::function<TreeNode*(TreeNode*, TreeNode*, TreeNode* )> DFS;
    DFS = [&] (TreeNode* root, TreeNode* p, TreeNode* q) -> TreeNode* {
        if (root == nullptr) return nullptr;
        TreeNode* left;
        TreeNode* right;
        if(root == p || root == q) return root;
        left = DFS(root->left,p,q);
        right = DFS(root->right,p,q);        
        if(left != nullptr && right != nullptr) return root;
        if(left != nullptr) return left;
        if(right != nullptr) return right;
        return nullptr;
    };
    return DFS(root,p,q);
}
