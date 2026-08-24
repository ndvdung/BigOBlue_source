#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string t;
    cin >> s >> t;
    int len = s.length();
    int i = len - 1;
    while (i >= 0)
    {
        if (s[i] != 'z')
        {
            s[i]++; // incre 1 char = minimum incre
            if (s != t)
            {
                cout << s;
            }
            else
            {
                cout << "No such string";
            }
            return 0;
        }
        if (s[i] == 'z')
        {
            s[i] = 'a';
            i--;
        }
    }
    // out while --> i < 0; all char is 'z'
    cout << "No such string";
}