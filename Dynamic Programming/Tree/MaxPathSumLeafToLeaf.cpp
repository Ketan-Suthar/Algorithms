int helper(Node *root, int &result)
{
    if(!root)   return 0;
    if(root->left==nullptr && root->right==nullptr) return root->data; 
    
    int left = helper(root->left, result);
    int right = helper(root->right, result);
    if(root->left==nullptr || root->right==nullptr)
    {
        return (root->left==nullptr) ? (root->data + right) :
            (root->data + left);
    }
    int temp = max(left, right) + root->data;
    int ans = left + right + root->data;
    if(ans > result)
        result = ans;
    // cout<<temp<<'\n';
    return temp;
}

int maxPathSum(Node* root)
{ 
    // code here   
    int result = INT_MIN;
    int temp = helper(root, result);
    return result;
}