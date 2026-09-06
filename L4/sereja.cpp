#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int sum1 = 0, sum2 = 0;
    int l = 0, r = n - 1;
    int time = 1;
    while (l <= r)
    {
        if (time & 1)
        {
            if (nums[l] < nums[r])
            {
                sum1 += nums[r];
                r--;
            }
            else
            {
                sum1 += nums[l];
                l++;
            }
        }
        else
        {
            if (nums[l] < nums[r])
            {
                sum2 += nums[r];
                r--;
            }
            else
            {
                sum2 += nums[l];
                l++;
            }
        }
        time++;
    }

    cout << sum1 << ' ' << sum2;
    return 0;
}