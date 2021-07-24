class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        int lb[n], rb[n];

        stack<int> st1;
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();

            if (st1.empty())
                lb[i] = -1;
            else
                lb[i] = st1.top();

            st1.push(i);
        }

        stack<int> st2;
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();

            if (st2.empty())
                rb[i] = n;
            else
                rb[i] = st2.top();

            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int area = (rb[i] - lb[i] - 1) * heights[i];
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};