#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;

    int i = 0, j = 0;
    int fr[26] = {0};
    int unq = 0;
    while (j < n)
    {
        fr[s[j] - 'a']++;
        if (fr[s[j] - 'a'] == 1)
        {
            unq++;
        }

        while (unq > k)
        {
            fr[s[i] - 'a']--;

            if (fr[s[i] - 'a'] == 0)
            {
                unq--;
            }
            i++;
        }

        if (unq == k)
        {
            cout << j - i + 1 << endl;
        }

        j++;
    }

    return 0;
}