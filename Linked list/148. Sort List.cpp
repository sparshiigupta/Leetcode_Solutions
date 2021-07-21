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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *newList = new ListNode(-1);
        ListNode *newHead = newList;

        while (left && right)
        {
            if (left->val < right->val)
            {
                newHead->next = left;
                left = left->next;
            }
            else
            {
                newHead->next = right;
                right = right->next;
            }
            newHead = newHead->next;
        }

        while (left != NULL)
        {
            newHead->next = left;
            left = left->next;
            newHead = newHead->next;
        }
        while (right != NULL)
        {
            newHead->next = right;
            right = right->next;
            newHead = newHead->next;
        }
        return newList->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        ListNode *newHead = merge(left, right);

        return newHead;
    }
};