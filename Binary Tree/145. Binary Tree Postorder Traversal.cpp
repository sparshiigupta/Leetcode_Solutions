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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        stack<int> t;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node)
                t.push(node->val);

            if (node && node->left)
                st.push(node->left);

            if (node && node->right)
                st.push(node->right);
        }
        vector<int> res;
        while (!t.empty())
        {
            res.push_back(t.top());
            t.pop();
        }
        return res;
    }
};