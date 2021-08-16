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
    void leafEle(TreeNode *root, vector<int> &root1)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            root1.push_back(root->val);

        leafEle(root->left, root1);
        leafEle(root->right, root1);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> tree1, tree2;
        leafEle(root1, tree1);
        leafEle(root2, tree2);

        return tree1 == tree2;
    }
};