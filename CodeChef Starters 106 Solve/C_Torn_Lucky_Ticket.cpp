#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll v[10][10][50] = {0};
    ll lenSum[10][50] = {0};
    vector<string> input;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll sum = 0;
        for (ll j = 0; j < s.size(); j++)
        {
            if (j == s.size() - 1)
            {
                if (s.size() == 5)
                {
                    v[4][1][sum - (s[j] - '0')]++;
                    v[3][2][sum - (s[j] - '0') - (2 * (s[j - 1] - '0'))]++;
                                }
                if (s.size() == 4)
                {
                    v[3][1][sum - (s[j] - '0')]++;
                }
                if (s.size() == 3)
                {
                    v[2][1][sum - (s[j] - '0')]++;
                }
            }
            sum += (s[j] - '0');
        }
        lenSum[s.size()][sum]++;

        input.push_back(s);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        string s = input[i];
        ll sum = 0;
        for (char c : s)
        {
            sum += (c - '0');
        }
        if (s.size() == 1)
        {
            ans += (lenSum[1][sum]);
            ans += (v[2][1][sum]);
            ans += (v[3][2][sum]);
        }
        else if (s.size() == 2)
        {
            ans += (lenSum[2][sum]);
            ans += (v[3][1][sum]);
        }
        else if (s.size() == 3)
        {
            ll nSum = 0;
            for (ll j = 1; j < 3; j++)
            {
                nSum += (s[j] - '0');
            }
            ans += (lenSum[1][nSum - (s[0] - '0')]);
            ans += (lenSum[3][sum]);
            ans += (v[4][1][sum]);
        }
        else if (s.size() == 4)
        {
            ll nSum = 0;
            for (ll j = 1; j < 4; j++)
            {
                nSum += (s[j] - '0');
            }
            ans += (lenSum[4][sum]);
            ans += (lenSum[2][nSum - (s[0] - '0')]);
        }
        else if (s.size() == 5)
        {
            ll nSum = 0, bSum = 0, gSum = 0;
            for (ll j = 0; j < 2; j++)
            {
                bSum += (s[j] - '0');
            }
            for (ll j = 2; j < 5; j++)
            {
                nSum += (s[j] - '0');
            }
            for (ll j = 1; j < 5; j++)
            {
                gSum += (s[j] - '0');
            }
            ans += (lenSum[1][nSum - bSum]);
            ans += (lenSum[3][gSum - (s[0] - '0')]);
            ans += (lenSum[5][sum]);
        }
    }
    cout << ans << endl;
    return 0;
}