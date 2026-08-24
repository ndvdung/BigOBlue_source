#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minMachines(vector<vector<int>> intervals)
{
    vector<pair<int, int>> events; // time, +-1 machine
    // create events
    for (int i = 0; i < intervals.size(); i++)
    {
        events.push_back({intervals[i][0], 1});  // start -> +1 machine
        events.push_back({intervals[i][1], -1}); // end -> -1 machine
    }

    // chrono sort event
    sort(events.begin(), events.end());

    // cnt
    int currMach = 0;
    int maxMach = -1;

    // iterate thru each event
    for (int i = 0; i < events.size(); i++)
    {
        currMach += events[i].second;

        if (currMach > maxMach)
        {
            maxMach = currMach;
        }
    }
    return maxMach;
}

int main()
{
    vector<vector<int>> intervals = {
        {19, 21}, // Tương ứng [19:00 -> 21:00]
        {10, 12}, // Tương ứng [10:00 -> 12:00]
        {14, 16}, // Tương ứng [14:00 -> 16:00]
        {15, 17}, // Tương ứng [15:00 -> 17:00]
        {8, 11}   // Tương ứng [08:00 -> 11:00]
    };
    cout << minMachines(intervals);
    return 0;
}