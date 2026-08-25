#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int nmax = 100002;
double capa[2 * nmax + 1];

int main()
{
    int n;
    double w;
    cin >> n >> w;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> capa[i];
    }

    sort(capa, capa + 2 * n);

    double mingirl = 1e9 + 2, minboy = 1e9 + 2;
    for (int i = 0; i < n; i++)
    {
        if (capa[i] < mingirl)
            mingirl = capa[i];
    }
    for (int i = n; i < 2 * n; i++)
    {
        if (capa[i] < minboy)
            minboy = capa[i];
    }
    // cout << mingirl << " " << minboy;

    double min1 = min(mingirl, minboy / 2);
    double min2 = min1 * n + 2 * min1 * n;
    double res = min({min2, w});
    cout << fixed << setprecision(10) << res;
}