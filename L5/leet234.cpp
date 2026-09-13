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
    bool isPalindrome(ListNode *head)
    {
        // step 1, find middle node by slow
        ListNode *slow = head;
        ListNode *fast = head; // rabbit

        // khi fast->last->null thi van vao while va step 2 step toi null -> next while stop because now fast = null
        while (fast != NULL && fast->next != NULL)
        { //
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is poiting at the middle, or the start of middle half (for even case)

        // step 2, reverse from slow -> end;
        ListNode *prev = slow;
        ListNode *curr = slow->next;

        // let prev(slow now) point next to null;

        prev->next = NULL;
        while (curr != NULL)
        { // stop when curr == null and prev is at the last node of og list
            ListNode *tosave = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tosave;
        }

        // step 3: prev is at the start of second half (p1-> p2; p2->null; )
        ListNode *p1 = head;
        ListNode *p2 = prev;
        while (p2 != NULL)
        { // must check, cause for even case when p2->next == null we still need the comparison
            if (p1->val != p2->val)
                return false;
            // else
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};