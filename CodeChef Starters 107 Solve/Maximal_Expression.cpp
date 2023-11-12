/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||         Programming Hero          ||
||-----------------------------------||
*/
#include <bits/stdc++.h>
#define ll long long int
#define pub push_back
#define pob pop_back
#define PI 3.14159265359
#define vll vector<ll>
#define All(X) (X).begin(), (X).end()
#define Unique(X) (X).erase(unique(All(X)), (X).end())
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
#define pi pair<ll, ll>
#define vpair vector<pair<ll, ll>>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define minus cout << -1 << endl
#define MAX 100000
using namespace std;
ll cs = 1;
int f(int x, int n, int k)
{
    return (x % k) * (n - x) % k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << n / 2 << endl;
    }
    else
    {
        int x1 = (n % k) / 2;
        int x2 = (n % k + k) / 2;
        if (f(x1, n, k) > f(x2, n, k))
            cout << x1 << endl;
        else
            cout << x2 << endl;
    }
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
