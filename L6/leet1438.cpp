class Solution
{
public:
    queue<int> q;
    deque<int> dq, dqmin; // dq is for max
    vector<int> res;

public:
    // for mỗi r:

    /*1. add nums[r] vào window

    2. nếu window invalid:
           remove từ left
           l++
       lặp tới khi valid trở lại

    3. record length
    */
    int longestSubarray(vector<int> &nums, int limit)
    {
        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            push(nums[r]);

            while (getMax() - getMin() > limit) // window invalid-> remove từ left//
            {
                pop(nums[l]);
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }

    void push(int v)
    {
        q.push(v);

        // decreasing deque -> front = max
        while (!dq.empty() && v > dq.back())
            dq.pop_back();

        dq.push_back(v);

        // increasing deque -> front = min
        while (!dqmin.empty() && v < dqmin.back())
            dqmin.pop_back();

        dqmin.push_back(v);
    }
    int getMax()
    {
        return dq.front();
    }
    int getMin()
    {
        return dqmin.front();
    }
    void pop(int v)
    {
        if (dq.empty() || q.empty() || dqmin.empty())
            return;
        // if con pop cung la 1 con max/min -> pop khoi front dequeue
        if (dq.front() == q.front())
            dq.pop_front();
        if (dqmin.front() == q.front())
            dqmin.pop_front();
        // anyway deu phai pop
        q.pop();
    }
};