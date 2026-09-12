#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> req(n, 0);
    vector<int> prep(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> prep[i];
    }

    int in = 0, im = 0, res = 0;
    while (in < n && im < m)
    {
        // tang prep khi da qua de so vs req
        if (prep[im] < req[in])
        {
            im++;
        }

        else // fit -> cout & next both
        {
            res++;
            in++;
            im++;
        }
    }

    cout << n - res;
}