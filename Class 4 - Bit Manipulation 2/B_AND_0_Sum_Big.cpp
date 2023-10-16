#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 1;
        while (k--)
        {
            ans = ((ans % mod) * (n % mod)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}