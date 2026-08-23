#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t;

    cin >> t;
    n--;

    int curr = t;
    if (curr > 15)
    {
        cout << 15;
        return 0;
    }

    // curr == first t

    while (n--)
    {
        cin >> t;
        if (t - curr > 15)
        {
            cout << curr + 15;
            return 0;
        }
        curr = t;
    }
    cout << min(curr + 15, 90);
}