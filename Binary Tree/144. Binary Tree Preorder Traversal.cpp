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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> st;

        st.push(root);
        TreeNode *cur = root;
        while (!st.empty())
        {
            while (cur)
            {
                ans.push_back(cur->val);

                if (cur->right)
                    st.push(cur->right);
                cur = cur->left;
            }
            if (!st.empty())
            {
                cur = st.top();
                st.pop();
            }
        }

        return ans;
    }
};