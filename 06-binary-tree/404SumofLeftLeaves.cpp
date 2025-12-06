int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    
    std::function<int(TreeNode*, bool)> dfs;
    dfs = [&](TreeNode* node, bool isLeft) -> int {
        if (!node) return 0;
        
        if (isLeft && !node->left && !node->right) {
            return node->val;  // Левый лист
        }
        
        return dfs(node->left, true) + dfs(node->right, false);
    };
    
    return dfs(root, false);
}