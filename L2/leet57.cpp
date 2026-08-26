class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // intervals: non overlap, sorted by starting
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        // if end before new in start -> keep pushing
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // out while -> start ovelap -> merge into new -> stop when intervals[i].start > new.end
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // necc cause only checked in[i][1] vs new[0]
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back({newInterval[0], newInterval[1]});

        // push remain
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};