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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head; // rabbit

        // khi fast->last->null thi van vao while va step 2 step toi null -> next while stop because now fast = null
        while (fast != NULL && fast->next != NULL)
        { //
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};