#include <iostream>
#include <vector>

using namespace std;
int cnt[100005]; // full zeros
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int min_len = 1e9;
    int resl = -1, resr = -1;
    int dist = 0;

    int l = 0, r = 0;
    while (dist < k && r < n)
    { // keep adding if distinct < k

        cnt[nums[r]]++;
        if (cnt[nums[r]] == 1)
            dist++; // new detected;
        r++;        // this new r is not inclusive
    }
    // out while -> dist == k // start to remove l or worst case r == n ma dist < k -> chay het mang van chua thoa
    // phai co 1 if dist < k, aka r == n -> otherwise, khi dung cuoi mang thi no chay bay
    if (dist < k)
    {
        cout << -1 << " " << -1;
        return 0;
    }

    while (cnt[nums[l]] > 1)
    {
        cnt[nums[l]]--;
        l++;
    }
    // out while -> first min seg, cnt nums[l] == 1
    resl = l;
    resr = r - 1;

    if (resl == -1 && resr == -1)
        cout << -1 << " " << -1;
    else
        cout << resl + 1 << " " << resr + 1;
    return 0;
}

// optimize shortest
//  while (l < n)
//  {
//      while (dist < k && r < n)
//      { // keep adding if distinct < k

//         cnt[nums[r]]++;
//         if (cnt[nums[r]] == 1)
//             dist++; // new detected;
//         r++;        // this new r is not inclusive
//     }
//     // out while -> dist == k // start to remove l or worst case r == n ma dist < k -> chay het mang van chua thoa
//     // phai co 1 if dist < k, aka r == n -> otherwise, khi dung cuoi mang thi no chay bay
//     if (dist < k)
//     {
//         break;
//     }

//     while (cnt[nums[l]] > 1)
//     {
//         cnt[nums[l]]--;
//         l++;
//     }
//     // out while -> first min seg, cnt nums[l] == 1
//     resl = l;
//     resr = r - 1;
//     // if (r - l < min_len)
//     // {
//     //     min_len = r - l; // cause r++ already
//     //     resl = l;
//     //     resr = r - 1;
//     // }
//     // done, start new
//     // remove l
//     // cnt[nums[l]]--; // = 0
//     // dist--;
//     // l++;
//     break;
// }
