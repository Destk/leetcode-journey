bool isBalanced(TreeNode* root) {
    function<int(TreeNode*)> check = [&](TreeNode* node) -> int {
        if (node == nullptr) return 0;
        
        int l = check(node->left);    // рекурсивный вызов ЛЯМБДЫ
        int r = check(node->right);   // рекурсивный вызов ЛЯМБДЫ
        
        if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    };
    
    return check(root) != -1;
}
