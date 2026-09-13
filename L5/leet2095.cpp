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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL; // list has 0 or 1;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = head; // rabbit

        // case 1 odd: fast->null thi fast dg o dung last
        // case 2 even:  khi fast->last->null thi van vao while va step 2 step toi null -> next while stop because now fast = null
        while (fast != NULL && fast->next != NULL)
        { //
            slow = slow->next;
            fast = fast->next->next;
        }
        // because of dummy, slow is right in front of middle;
        ListNode *todelete = slow->next;

        slow->next = slow->next->next;
        delete todelete;
        return head;
    }
};