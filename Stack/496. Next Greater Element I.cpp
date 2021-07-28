class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();

            st.push(nums2[i]);
        }

        int m = nums1.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++)
        {

            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            ans[i] = nge[it - nums2.begin()];
        }
        return ans;
    }
};