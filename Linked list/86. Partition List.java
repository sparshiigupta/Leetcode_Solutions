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
    public ListNode partition(ListNode head, int x) {
        ListNode temp_s=new ListNode(0);
        ListNode temp_h=new ListNode(0);
        ListNode small=temp_s;
        ListNode high=temp_h;
        
        while(head!=null)
        {
            if (head.val<x)
            {
                small.next=head;
                small=small.next;
            }
            else
            {
                high.next=head;
                high=high.next;
            }
            head=head.next;
        }
        small.next=temp_h.next;
        high.next=null;
        return temp_s.next;
    }
}