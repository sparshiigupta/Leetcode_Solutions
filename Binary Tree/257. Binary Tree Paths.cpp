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
    vector<string> str;
    void preorder(TreeNode *root, string psf)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            string s = to_string(root->val);
            str.push_back(psf + s);
            return;
        }

        string s = to_string(root->val);
        string t = "->";
        preorder(root->left, psf + s + t);
        preorder(root->right, psf + s + t);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
            return str;
        preorder(root, "");
        return str;
    }
};