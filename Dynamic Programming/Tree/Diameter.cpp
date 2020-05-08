int solve(Node *root, int &res)
{
    if(root == nullptr)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(l,r) + 1;
    int ans = max(temp, (l+r+1));
    res = max(res, ans);

    return temp;
}

int diameter(Node* node)
{
    int res = INT_MIN;
    solve(node, res);
    return res;
}