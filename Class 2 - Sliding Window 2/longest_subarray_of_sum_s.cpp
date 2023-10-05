#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s;
    cin >> s;

    int i = 0, j = 0, sum = 0, mx = 0;
    while (j < n)
    {
        sum += a[j];
        while (sum > s)
        {
            sum -= a[i];
            i++;
        }
        if (sum == s)
        {
            mx = max(mx, j - i + 1);
        }
        j++;
    }
    cout << mx << endl;
    return 0;
}