#include <bits/stdc++.h>
using namespace std;
bool vis[25];
int sum = 0;
int a[25];
int ans;
void back(int n, vector<int> &v, int s1)
{
    int s2 = sum - s1;
    int tmpAns = min(ans, abs(s2 - s1));
    ans = min(ans, tmpAns);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            v.push_back(i);
            back(n, v, s1 + a[i]);
            v.pop_back();
            vis[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    memset(vis, false, sizeof(vis));
    vector<int> v;
    ans = INT_MAX;
    back(n, v, 0);
    cout << ans << "\n";
    return 0;
}