#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll i, j;
        cin >> i >> j;
        cout << max({n * (m - j), n * (j - 1), m * (i - 1), m * (n - i)}) << endl;
    }
    return 0;
}