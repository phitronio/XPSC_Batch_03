#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1];
            if (a[i] % 2 == 1)
                pre[i]++;
        }
        int ans = 0;
        for (int i = 1; i <= n - k + 1; i++)
        {
            if (pre[i + k - 1] - pre[i - 1] > 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}