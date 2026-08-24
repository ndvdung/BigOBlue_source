#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> schedule;

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
            schedule.push_back({currentStart, currentEnd});
            totalTime += currentEnd - currentStart;
            currentStart = intervals[i].first;
            currentEnd = intervals[i].second;
        }
    }
    // out for, du da start new period hay stay o period cuoi thi cung deu con 1 period chua tinh busy
    schedule.push_back({currentStart, currentEnd});
    totalTime += currentEnd - currentStart;
    return totalTime;
}

vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval)
{
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // push cac interval truoc new interval ko bi chong cheo
    // if interval[i] end truoc khi new start thi cu tiep tuc push
    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    // out while -> chong cheo -> current end > new start -> gop
    // gop cho den khi interval.start > new.end la out => if interval.start <= new.end thi van tiep tuc gop
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        // gop
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // out while -> newInterval la cai da gop xong
    result.push_back(newInterval);

    // finally, push remaining
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
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
    cout << getTotalBusyTime(intervals) << endl;

    for (vector<int> s : schedule)
    {
        cout << s[0] << " " << s[1] << endl;
    }
    cout << endl;

    vector<int> newInterval = {11, 15};

    vector<vector<int>> res = insertInterval(schedule, newInterval);

    for (vector<int> s : res)
    {
        cout << s[0] << " " << s[1] << endl;
    }
    cout << endl;
    return 0;
}
