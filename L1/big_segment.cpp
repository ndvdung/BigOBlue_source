#include <iostream>

using namespace std;

const int nmax = 100002;

int Arr[nmax][2];

int main()
{
    int minl = int(1e9 + 2);
    int maxr = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i][0] >> Arr[i][1];
        if (Arr[i][0] < minl)
            minl = Arr[i][0];
        if (Arr[i][1] > maxr)
            maxr = Arr[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        if (Arr[i][0] == minl && Arr[i][1] == maxr)
        {
            cout << (i + 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}