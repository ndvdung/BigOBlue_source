#include <iostream>
#include <vector>

using namespace std;

vector<int> books;

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        books.push_back(x);
    }

    int r = 0;
    int curr = 0;
    int maxlen = 0;

    for (int l = 0; l < n; l++)
    {
        while (r < n && (curr + books[r]) <= t)
        {
            curr += books[r];

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        // out while -> cant read nomore

        if (r > l)
        { // normal case -> drop left
            curr -= books[l];
        }
        else
        {        // l catched up l == r but still cannot add books[r] into curr
            r++; // push r
        }
    }

    cout << maxlen;
    // idea;
    //  1. Cố đẩy r sang phải nhiều nhất có thể.
    //  2. Lấy max = r - l.
    //  3. Bỏ books[l] khỏi window nếu nó đang nằm trong window.
    //  4. l tăng.

    // edge:
    //  Phần:

    // else
    // {
    //     r++;
    // }

    // chính là thứ tự động xử lý trường hợp:

    // books[l] > t

    // Ví dụ:

    // t = 5
    // books = [10, 2, 3]

    // Tại:

    // l = 0
    // r = 0
    // curr = 0

    // 10 không nhét được.

    // Window rỗng:

    // [l,r) = [0,0)

    // nên:

    // r == l

    // Ta chỉ đẩy:

    // r → 1

    // chứ không trừ 10 khỏi curr.

    // Sang vòng sau:

    // l = 1
    // r = 1
    // curr = 0

    // hoàn toàn sạch.
}