#include <bits/stdc++.h>
using namespace std;
double getDistance(int ax, int ay, int bx, int by)
{
    return sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
}
bool isInside(int ax, int ay, int px, int py, double r)
{
    double d = getDistance(ax, ay, px, py);
    return (r - d) > 1e-15;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int px, py;
        cin >> px >> py;
        int ax, ay;
        cin >> ax >> ay;
        int bx, by;
        cin >> bx >> by;
        double l = 0.0, r = INT_MAX * 1.0, ans;
        // a <= b  -> (b-a) > 1e-15
        // a == b -> fabs(a-b) < 1e-15

        while ((r - l) > 1e-15) // l<=r
        {
            double radius = l + (r - l) / 2;
            if (isInside(ax, ay, 0, 0, radius) && isInside(ax, ay, px, py, radius))
            {
                ans = radius;
                r = radius;
            }
            else if (isInside(bx, by, 0, 0, radius) && isInside(bx, by, px, py, radius))
            {
                ans = radius;
                r = radius;
            }
            else if (isInside(ax, ay, 0, 0, radius) && isInside(bx, by, px, py, radius) && ((2 * radius) - getDistance(ax, ay, bx, by)) > 1e-15)
            {
                ans = radius;
                r = radius;
            }
            else if (isInside(bx, by, 0, 0, radius) && isInside(ax, ay, px, py, radius) && ((2 * radius) - getDistance(ax, ay, bx, by)) > 1e-15)
            {
                ans = radius;
                r = radius;
            }
            else
            {
                l = radius;
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}