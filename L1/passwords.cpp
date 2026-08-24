#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> pass;

int main()
{
    int n, k;
    cin >> n >> k;
    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        pass.push_back(str);
    }
    string pw;
    cin >> pw;
    int min = 0, max = 0;
    int cnt = 0;
    // lambda
    sort(pass.begin(), pass.end(), [](string a, string b)
         { return a.length() < b.length(); });

    for (int i = 0; i < n; i++)
    {
        if (pass[i].length() < pw.length())
        {
            min++;
        }
        else if (pass[i].length() == pw.length())
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    // break when length = pass length

    max = min; // count amount

    min = min + (min / k) * 5;
    cout << min + 1;

    max += cnt;
    max--; // adjust for the correct
    max = max + (max / k) * 5;
    cout << " " << max + 1;
}
