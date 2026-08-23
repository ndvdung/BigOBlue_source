#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string t;
    string res = "";
    cin >> s >> t;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if ((t[i] - s[i]) < 2)
        {
            res += s[i];
        }
        else
        {
            res += char(s[i] + 1);
        }
    }
    if (res == s)
        cout << "No such string";
    else
        cout << res;
}