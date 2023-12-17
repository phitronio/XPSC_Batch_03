#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;
class Node
{
public:
    int ans, open, close;
    Node(int a, int o, int c)
    {
        ans = a;
        open = o;
        close = c;
    }
    Node() {}
};
Node tree[mx * 3];
Node merge(Node a, Node b)
{
    int ans = min(a.open, b.close);
    a.open -= ans;
    b.close -= ans;
    Node n(a.ans + b.ans + ans, a.open + b.open, a.close + b.close);
    return n;
}
void build(int node, int l, int r, string &s)
{

    if (l == r)
    {
        if (s[l] == '(')
        {
            tree[node].open = 1;
            tree[node].close = 0;
            tree[node].ans = 0;
        }
        else
        {
            tree[node].close = 1;
            tree[node].open = 0;
            tree[node].ans = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    build(leftNode, l, mid, s);
    build(rightNode, mid + 1, r, s);
    tree[node] = merge(tree[leftNode], tree[rightNode]);
}
Node query(int node, int l, int r, int a, int b)
{
    if (l >= a && r <= b)
    {
        return tree[node];
    }
    if (r < a || l > b)
    {
        return Node(0, 0, 0);
    }
    int mid = (l + r) / 2;
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
    return merge(query(leftNode, l, mid, a, b), query(rightNode, mid + 1, r, a, b));
}
int main()
{
    string s;
    int q;
    cin >> s >> q;
    build(1, 0, s.size() - 1, s);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Node ansNode = query(1, 0, s.size() - 1, a, b);
        cout << ansNode.ans * 2 << endl;
    }
    return 0;
}