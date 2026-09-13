#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()

{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // solve this test case here

        int curr = 1;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            st.push(v[i]);
            while (!st.empty() && st.top() == curr)
            {
                st.pop();
                curr++;
            }
        }
        cout << (st.empty() ? "yes" : "no") << endl;
    }
}