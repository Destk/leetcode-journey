class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return std::vector<std::vector<int>>{};
        
        std::vector<std::vector<int>> Out{};
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            std::vector<int> currentLevel{};
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            Out.push_back(currentLevel);
        }
        
        return Out;  // ← КЛЮЧЕВАЯ СТРОКА!
    }
};
