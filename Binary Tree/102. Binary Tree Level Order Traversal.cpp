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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> traversal;
        if (root == NULL)
        {
            return traversal;
        }

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {

            int qlen = q.size();
            vector<int> row;

            for (int i = 0; i < qlen; i++)
            {

                TreeNode *node = q.front();
                row.push_back(node->val);
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            traversal.push_back(row);
        }

        return traversal;
    }
};