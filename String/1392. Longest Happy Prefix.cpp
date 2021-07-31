class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.size();
        int lps[n];
        lps[0] = 0;

        int i = 0, j = 1;

        while (j < n)
        {
            if (s[i] == s[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else if (i > 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }

        int ans = lps[n - 1];
        return s.substr(0, ans);
    }
};