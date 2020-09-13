class Solution {

public:
    int helper(TreeNode* root, long &result)
    {
        if(!root)
            return 0;    
        long left = helper(root->left, result);
        long right = helper(root->right, result);
        long temp = 1 + max(left, right);
        long ans = (left + right + 1);
        result = max(result, ans);
        
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(!root)
            return 0; 
        long result = INT_MIN;
        helper(root, result);
        return result-1;
    }
};