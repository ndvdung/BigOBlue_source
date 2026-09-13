/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        // fast move n
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL) // stop when fast->next == null aka slow->1(3fromlast)->2->last(fast)->null when n=3
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *todelete = slow->next;

        slow->next = slow->next->next;
        delete todelete;
        ListNode *newhead = dummy->next;
        delete dummy;

        return newhead;
    }
};