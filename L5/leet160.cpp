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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        // step 1: let 2 pointer run same speed, 1will touch last first;
        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa->next != NULL && pb->next != NULL)
        { // stop when 1 reach last
            pa = pa->next;
            pb = pb->next;
        }

        // count diff in length of 2 branch
        int diff = 0;

        // diff is the length diff -> 2 new ptr at 2 head, let the longer one move first

        if (pa->next == NULL)
        { // b is longer
            while (pb->next != NULL)
            {
                diff++;
                pb = pb->next;
            }
            ListNode *qa = headA;
            ListNode *qb = headB;
            while (diff--)
            {
                qb = qb->next;
            }
            // last step let qa, qb move , where they meet is the intersection
            while (qa != NULL && qb != NULL)
            {
                if (qa == qb)
                {
                    return qa;
                }
                qa = qa->next;
                qb = qb->next;
            }
            return NULL; // no intersect
        }
        else
        { // a is longer
            while (pa->next != NULL)
            {
                diff++;
                pa = pa->next;
            }
            ListNode *qa = headA;
            ListNode *qb = headB;
            while (diff--)
            {
                qa = qa->next;
            }
            // last step let qa, qb move , where they meet is the intersection
            while (qa != NULL && qb != NULL)
            {
                if (qa == qb)
                {
                    return qa;
                }
                qa = qa->next;
                qb = qb->next;
            }
            return NULL; // no intersect
        }
    }
};