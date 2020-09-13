class Solution {
public:
    
    int solve(TreeNode* root,int &res)
    {
        if(!root)
            return 0;
        
        int left =solve(root->left,res);
        int right =solve(root->right,res);
        
        int temp = max(max(left, right)+root->val,root->val);
        
        int ans = max(left + right + root->val,temp);
        
        res=max(res,ans);
        
        return temp;
        
    }
    
    int maxPathSum(TreeNode* root) 
    {
        
        int res=INT_MIN;
        
        int s = solve(root,res);
        
        return res;
        
    }
};