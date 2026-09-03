class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        int currentStart = intervals[0][0];
        int currentEnd = intervals[0][1];
        int n = intervals.size();
        int i = 1;
        for (; i < n; i++)
        {
            // if start before currend -> merge, not pushed yet
            if (intervals[i][0] <= currentEnd)
            {
                // ko can update current start vi khi sort no tu sort theo thang dau tien -> luon start sau curr start
                currentEnd = max(currentEnd, intervals[i][1]);
            }
            else
            {
                res.push_back({currentStart, currentEnd});
                currentStart = intervals[i][0];
                currentEnd = intervals[i][1];
            }
        }

        res.push_back({currentStart, currentEnd});
        return res;
    }
};