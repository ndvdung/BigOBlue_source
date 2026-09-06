class NumArray
{
private:
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0); // insert 0 at 0-index
        prefix.resize(n + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        left++;
        right++;
        return (prefix[right] - prefix[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */