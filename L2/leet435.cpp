class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                if (a[1] != b[1]) return a[1] < b[1];
                else return a[0] < b[0]; });

        res.push_back(intervals[0]);

        int currentEnd = intervals[0][1];

        int i = 1;
        while (i < n)
        {
            if (intervals[i][0] >= currentEnd)
            {
                res.push_back(intervals[i]);
                currentEnd = intervals[i][1];
                i++;
            }
            else
            {
                i++; // pass
            }
        }
        return n - res.size();
    }
};