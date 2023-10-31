#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0, r = INT_MAX, ans;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll s = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] > mid)
            {
                s += (a[i] - mid);
            }
        }
        if (s >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}