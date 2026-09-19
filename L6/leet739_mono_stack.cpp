class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        int ptr = -1;
        stack<int> cold; // save index not value
        for (int i = 0; i < n; i++)
        {
            while (!cold.empty() && temperatures[i] > temperatures[cold.top()])
            {
                // save index that is kicked out
                ptr = cold.top();
                res[ptr] = i - ptr;
                cold.pop();
            }
            cold.push(i);
        }
        return res;
    }
};