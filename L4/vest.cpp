#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> sol(n, 0);
    vector<int> vest(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> sol[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> vest[i];
    }

    vector<pair<int, int>> v;

    int in = 0, im = 0, res = 0;
    while (in < n && im < m)
    {
        // tang ao khi ao qua chat, ao ko the fit min sol
        if (vest[im] < sol[in] - x)
        {
            im++;
        }
        // tang sol khi ao qua rong, ke ca max sol cung ko the fit ao
        else if (sol[in] + y < vest[im])
        {
            in++;
        }
        else // fit -> cout & next both
        {
            res++;
            v.push_back({in + 1, im + 1});

            in++;
            im++;
        }
    }

    cout << res << endl;
    for (pair<int, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
}