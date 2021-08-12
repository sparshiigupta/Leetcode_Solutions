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
    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int Maxsum = INT_MIN;
        int i = 1;
        int level = 0;
        while (!q.empty())
        {
            int sum = 0;
            int n = q.size();
            while (n--)
            {
                TreeNode *node = q.front();
                sum += node->val;
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (sum > Maxsum)
            {
                Maxsum = sum;
                level = i;
            }
            i++;
        }
        return level;
    }
};