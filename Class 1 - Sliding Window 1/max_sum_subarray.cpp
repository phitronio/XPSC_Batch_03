#include <bits/stdc++.h>
#define forI(i, s, n) for (int i = s; i < n; i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i;
    forI(i, 0, n) cin >> a[i];
    int k;
    cin >> k;

    int j;
    int mx = INT_MIN;
    forI(i, 0, n - k + 1)
    {
        int s = 0;
        forI(j, i, i + k)
        {
            s += a[j];
        }
        mx = max(mx, s);
    }
    cout << mx << endl;
    return 0;
}