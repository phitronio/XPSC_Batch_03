#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i;
    cin >> i;
    int x = 63;
    int mask = 1 << i;
    int newMask = (x ^ mask);
    int finalAns = (n & newMask);
    cout << finalAns << endl;
    return 0;
}