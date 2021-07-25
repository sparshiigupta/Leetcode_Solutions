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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummyLeft = new ListNode(-1);
        ListNode *dummyRight = new ListNode(-1);

        ListNode *left = dummyLeft;
        ListNode *right = dummyRight;

        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->val < x)
            {
                left->next = temp;
                left = left->next;
            }
            else if (temp->val >= x)
            {
                right->next = temp;
                right = right->next;
            }
            temp = temp->next;
        }

        left->next = dummyRight->next;
        right->next = NULL;

        return dummyLeft->next;
    }
};