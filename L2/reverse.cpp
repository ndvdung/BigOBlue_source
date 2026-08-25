#include <iostream>
#include <algorithm>

using namespace std;

const int nmax = 100004;
int arr[nmax];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (is_sorted(arr, arr + n))
    {
        cout << "yes" << endl
             << "1 1";
        return 0;
    }

    int left = -1, right = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            left = i;
            break;
        }
    }
    for (int i = left; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            right = i;
            break;
        }
    }

    reverse(arr + left, arr + right + 1);
    if (is_sorted(arr, arr + n))
        cout << "yes";
    else
    {
        cout << "no";
        return 0;
    }
    cout << endl;
    cout << left + 1 << " " << right + 1;
}