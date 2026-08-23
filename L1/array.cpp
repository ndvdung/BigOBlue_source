#include <iostream>

using namespace std;

const int nmax = 100002;

int A[nmax], B[nmax], na[nmax], nb[nmax];

int main()
{
    int size_a, size_b;
    cin >> size_a >> size_b;

    int k, m;
    cin >> k >> m;

    for (int i = 0; i < size_a; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < size_b; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < k; i++)
    {
        na[i] = A[i];
    }
    for (int i = 0; i < m; i++)
    {
        nb[i] = B[size_b - m + i];
    }

    // all na ele < nb ele -> only when max na < min nb
    if (na[k - 1] < nb[0])
        cout << "YES";
    else
        cout << "NO";
}