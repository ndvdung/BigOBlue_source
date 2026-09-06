class Solution
{
private:
    vector<int> pref;
    int res = 0;
    map<int, int> mp;

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        pref.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        for (int i = 0; i <= n; i++)
        {
            if (mp[pref[i] - k])
                res += mp[pref[i] - k]; // neu cai tong pref - k ton tai x lan -> tao duoc x subarray lan
            mp[pref[i]]++;
        }
        return res;
    }
};