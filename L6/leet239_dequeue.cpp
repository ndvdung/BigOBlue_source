class Solution
{
public:
    queue<int> q;
    dequeue<int> dq;
    vector<int> res;

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        // push k into q, first sliding
        for (int i = 0; i < k; i++)
        {
            push(nums[i]);
        }
        // front of dq is curr max
        getMax();

        for (int i = k; i < nums.size(); i++)
        {
            push(nums[i]);
            pop(nums[i - k]);
            getMax();
        }
        return res;
    }
    void push(int v)
    {
        q.push(v);
        while (!dq.empty() && v > dq.back())
        {
            dq.popback();
        }
        dq.push(v);
    }
    void getMax()
    {
        res.pushback(dq.front());
    }
    void pop(int v)
    {
        if (dq.empty() || q.empty())
            return;
        // if con pop cung la 1 con max -> pop khoi front dequeue
        if (dq.front() == q.front())
            dq.popfront();
        q.popfront();
    }
};