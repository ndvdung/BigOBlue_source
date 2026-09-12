/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        { // 0 or 1 node -> no cycle poss
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        { // fast -> last -> null thi van step them 1 lan cho fast = null roi out while
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        // out while -> no cycle
        return false;
    }
};