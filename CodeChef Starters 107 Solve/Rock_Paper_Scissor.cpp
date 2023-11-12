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
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] == 'R')
        {
            if (s2[i] == 'S')
                a++;
            else
                b++;
        }
        else if (s1[i] == 'S')
        {
            if (s2[i] == 'P')
                a++;
            else
                b++;
        }
        else
        {
            if (s2[i] == 'R')
                a++;
            else
                b++;
        }
    }
    // a,b
    if (a > b)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (b - a) / 2 + 1 << endl;
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
