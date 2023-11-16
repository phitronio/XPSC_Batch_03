#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
int tree[mx * 3];
void build(int node, int l, int r, int a[])
{
    if (l == r)
    {
        tree[node] = a[r];
        return;
    }
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    build(leftNode, l, mid, a);
    build(rightNode, mid + 1, r, a);
    // value set
    tree[node] = tree[leftNode] + tree[rightNode]; // merge
}
int query(int node, int l, int r, int x, int y)
{
    // puro node bad
    if (r < x || l > y)
        return 0;
    // puro node nibo
    if (l >= x && r <= y)
    {
        return tree[node];
    }
    // majhamajhi obostha. children er upor depend kore
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    return query(leftNode, l, mid, x, y) +
           query(rightNode, mid + 1, r, x, y);
    // merge
}
void update(int node, int l, int r, int idx, int val)
{
    if (idx < l || idx > r)
        return;
    if (l == r && l == idx)
    {
        tree[node] = val;
        return;
    }
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    int mid = (l + r) / 2;
    update(leftNode, l, mid, idx, val);
    update(rightNode, mid + 1, r, idx, val);
    tree[node] = tree[leftNode] + tree[rightNode]; // merge
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1, a); // nlogn
    int q;
    cin >> q;
    while (q--) // qlogn
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            int idx, val;
            cin >> idx >> val;
            idx--;
            update(1, 0, n - 1, idx, val); // logn
            for (int i = 1; i <= 7; i++)
                cout << tree[i] << " ";
            cout << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << query(1, 0, n - 1, x, y) << endl; // logn
        }
    }
    // O(qlogn + nlogn)
    return 0;
}