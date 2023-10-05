#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(string p, string s)
    {
        // code here
        int k = p.size();
        int frp[26] = {0};
        for (char c : p)
        {
            frp[c - 'a']++;
        }
        int i = 0, j = 0, ans = 0;
        int frs[26] = {0};
        while (j < s.size())
        {
            frs[s[j] - 'a']++;
            if (j >= k - 1)
            {
                bool tmp = true;
                for (int c = 0; c < 26; c++)
                {
                    if (frp[c] != frs[c])
                    {
                        tmp = false;
                        break;
                    }
                }
                if (tmp)
                    ans++;
                frs[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};