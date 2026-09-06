class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (pref[i - 1] == (pref[n] - pref[i]))
            {
                return i - 1;
            }
        }
        return -1;
    }
};