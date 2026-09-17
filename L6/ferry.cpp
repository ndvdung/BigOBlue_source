#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void solve(int n, int t, int m)
{
    queue<pair<int, int>> q_left, q_right;

    for (int i = 0; i < m; i++)
    {
        int arrive;
        string bank;
        cin >> arrive >> bank;
        if (bank == "left")
        {
            q_left.push({i, arrive});
        }
        else
        {
            q_right.push({i, arrive});
        }
    }

    vector<int> res(m, -1);
    int currtime = 0;
    string currside = "left";

    // big while: as long as 1 of 2 side still not empty
    while (!q_left.empty() || !q_right.empty())
    {
        if (currside == "left") // case A: left bank
        {

            // case 1, co xe dang cho o left
            if (!q_left.empty() && q_left.front().second <= currtime)
            {
                int onboard = 0;
                while (!q_left.empty() && q_left.front().second <= currtime)
                { //

                    onboard++;
                    res[q_left.front().first] = currtime + t;
                    q_left.pop();
                    if (onboard == n)
                    {
                        break;
                    }
                }
                // done, cross, next big while
                currtime += t;
                currside = "right";
            }
            // case 2, ko co xe o left, ma co xe dang o right
            else if (!q_right.empty() && q_right.front().second <= currtime)
            {
                currtime += t;
                currside = "right";
                // next big while
            }
            // else, ko co xe dang cho o ben nao ca, jump curr to next front
            else
            {
                int frontleft = (q_left.empty()) ? 1e9 : q_left.front().second;
                int frontright = (q_right.empty()) ? 1e9 : q_right.front().second;
                currtime = min(frontleft, frontright);
            }
        }

        else // case B: right bank
        {
            // case 1, co xe dang cho o right
            if (!q_right.empty() && q_right.front().second <= currtime)
            {
                int onboard = 0;

                while (!q_right.empty() && q_right.front().second <= currtime)
                {
                    onboard++;
                    res[q_right.front().first] = currtime + t;
                    q_right.pop();

                    if (onboard == n)
                    {
                        break;
                    }
                }

                // done, cross
                currtime += t;
                currside = "left";
            }

            // case 2, ko co xe o right, ma co xe dang cho o left
            else if (!q_left.empty() && q_left.front().second <= currtime)
            {
                currtime += t;
                currside = "left";
            }

            // case 3, ko co xe dang cho o ben nao ca
            else
            {
                int frontleft = (q_left.empty()) ? 1e9 : q_left.front().second;
                int frontright = (q_right.empty()) ? 1e9 : q_right.front().second;

                currtime = min(frontleft, frontright);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << res[i] << endl;
    }
}
int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n, t, m;
        cin >> n >> t >> m;
        solve(n, t, m);
        if (i != (c - 1))
            cout << endl;
    }
}