#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int x;
    cin >> x;
    auto it = lower_bound(v.begin(), v.end(), x);
    int idx = it - v.begin();
    cout << idx << endl;
    return 0;
}