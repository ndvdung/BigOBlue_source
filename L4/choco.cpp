#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> choc(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> choc[i];
    }

    int a = 0, b = 0;
    int timea = 0, timeb = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (timea <= timeb)
        { // same -> prior a, even l == r
            timea += choc[l];
            a++;
            l++;
        }
        else
        { // l == r but time b < time a
            timeb += choc[r];
            b++;
            r--;
        }
    }

    cout << a << ' ' << b;
}
