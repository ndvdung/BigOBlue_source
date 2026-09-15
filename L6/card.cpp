#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sol(int n)
{
    int x;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    vector<int> res;
    while (q.size() > 1)
    { // at least 2
        // discard 1
        x = q.front();
        q.pop();
        res.push_back(x);
        // move front to back if more than 1
        if (q.size() > 1)
        {
            x = q.front();
            q.pop();
            q.push(x);
        }
    }
    cout << "Discarded cards:";
    if (!res.empty())
        cout << " ";
    int size = res.size();
    for (int i = 0; i < size; i++)
    {
        cout << res[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "Remaining card: " << q.front() << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        sol(n);
        cin >> n;
    }
    return 0;
}