#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int mask = 1 << x;
    if ((n & mask) == 0)
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return 0;
}
