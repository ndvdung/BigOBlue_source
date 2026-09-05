#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 7; // size of og array a

    vector<int> a = {0, 10, 20, 15, 30, 25, 40, 10}; // size = 8 -> caused added 0 at 0 index

    // declare prefix array, size n + 1 = 8 = size(a) after add 0, all 0 value
    vector<int> P(n + 1, 0); //(size, value)
    for (int i = 1; i <= n; i++)
    {
        P[i] = P[i - 1] + a[i]; // at P[1] = P[0] + a[1]
    }

    // print p
    for (int n : P)
    {
        cout << n << " ";
    }

    // og inquiry
    int L = 2, R = 5;
    L++;
    R++; // add 0 for both a and P
    cout << endl;

    cout << P[R] - P[L - 1]; // even if og L = 0 -> now L = 1
}