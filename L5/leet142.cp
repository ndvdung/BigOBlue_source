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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        { // 0 or 1 node -> no cycle poss
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        { // fast -> last -> null thi van step them 1 lan cho fast = null roi out while
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // reset slow
                slow = head;
                // let both run with same speed
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                // slow == fast
                return slow;
            }
        }

        // out while -> no cycle
        return NULL;
    }
};
