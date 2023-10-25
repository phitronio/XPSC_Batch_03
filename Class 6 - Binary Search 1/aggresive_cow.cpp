#include <bits/stdc++.h>
using namespace std;
bool isValid(int dif, int a[], int n, int c)
{
    int cnt = 1;
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[last]) >= dif)
        {
            cnt++;
            last = i;
        }
    }
    return cnt >= c;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int l = 0;
        int r = INT_MAX;
        int ans;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValid(mid, a, n, c))
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
    }
    return 0;
}