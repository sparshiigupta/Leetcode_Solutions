/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool Symmetric(TreeNode *l, TreeNode *r)
    {
        if (l == NULL || r == NULL)
            return l == r;
        if (l->val != r->val)
            return false;

        return Symmetric(l->right, r->left) && Symmetric(l->left, r->right);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        if (root->left == NULL && root->right == NULL)
            return 1;
        return Symmetric(root->left, root->right);
    }
};