#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> chores;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int h = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        chores.push_back(h);
    }
    sort(chores.begin(), chores.end(), greater<int>());

    cout << chores[a - 1] - chores[a];
}