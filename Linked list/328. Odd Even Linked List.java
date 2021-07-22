/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd=new ListNode(0);
        ListNode temp_odd=odd;
        ListNode even=new ListNode(0);
        ListNode temp_even=even;
        int c=1;
        while(head!=null)
        {
            if(c%2==1)
            {
                odd.next=head;
                odd=odd.next;
                c++;
            }
            else
            {
                even.next=head;
                even=even.next;
                c++;
            }
            head=head.next;
        }
        odd.next=temp_even.next;
        even.next=null;
        return temp_odd.next;
        
    }
}