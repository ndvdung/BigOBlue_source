#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTotalBusyTime(vector<pair<int, int>> &intervals)
{
    if (intervals.empty())
        return 0;

    // else
    sort(intervals.begin(), intervals.end());

    // var
    int totalTime = 0;
    int currentStart = intervals[0].first;
    int currentEnd = intervals[0].second;

    // iterate & merge
    for (int i = 1; i < intervals.size(); i++)
    {
        // chong cheo, start new trc khi current end -> gop khoang -> keep start, update end = later end
        if (intervals[i].first <= currentEnd)
        {
            currentEnd = max(currentEnd, intervals[i].second);
        }

        // not duplicate -> update total busy, start new period
        else
        {
            totalTime += currentEnd - currentStart;
            currentStart = intervals[i].first;
            currentEnd = intervals[i].second;
        }
    }
    // out for, du da start new period hay stay o period cuoi thi cung deu con 1 period chua tinh busy
    totalTime += currentEnd - currentStart;
    return totalTime;
}

int main()
{

    vector<std::pair<int, int>> intervals = {
        {19, 21}, // Tương ứng [19:00 -> 21:00]
        {10, 12}, // Tương ứng [10:00 -> 12:00]
        {14, 16}, // Tương ứng [14:00 -> 16:00]
        {15, 17}, // Tương ứng [15:00 -> 17:00]
        {8, 11}   // Tương ứng [08:00 -> 11:00]
    };
    cout << getTotalBusyTime(intervals);
}
