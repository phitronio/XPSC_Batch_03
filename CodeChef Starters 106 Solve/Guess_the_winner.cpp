#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1 && n != 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}