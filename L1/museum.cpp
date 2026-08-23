#include <iostream>

using namespace std;

int main()
{
    char curr = 'a';
    char c;
    int ans = 0;
    while (cin >> c && c != EOF)
    {
        ans += min(abs(c - curr), 26 - abs(c - curr));
        curr = c;
    }
    cout << ans;
}