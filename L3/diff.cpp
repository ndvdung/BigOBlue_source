#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // og size
    int n = 7;

    // declare vector a with 0-index, i.e., size n+ 1
    vector<int> a = {0, 10, 20, 15, 30, 25, 40, 10};

    // declare D array with size of n + 2, including 2 zeros at begin and end
    vector<int> D(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {                           // same as prefix cause og index is now 1-> n
        D[i] = a[i] - a[i - 1]; // D[1] = a[1] - a[0] but a[0] is 0 by us adding
    }
    // update inquiry
    int L = 2, R = 4, val = 5;
    L++;
    R++; // cause index is pushed fw 1 unit

    D[L] += val;
    D[R + 1] -= val; // last index might be n, now coudl be n+1 -> reason why D has size of n+2

    // recover a
    vector<int> a_new(n + 1, 0); // size of n+1
    for (int i = 1; i <= n; i++)
    {
        a_new[i] = a_new[i - 1] + D[i]; // a_new 0 is 0-> a_new[1] is 0 + D[1]
        cout << a_new[i] << " ";
    }
    return 0;
}