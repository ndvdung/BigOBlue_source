#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int x;
        cin >> x;
        if (x == 1)
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }

    int count = 0;
    int a = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
            count++;
    }
    if (count == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}