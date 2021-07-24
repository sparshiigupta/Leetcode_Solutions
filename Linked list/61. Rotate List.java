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
    public ListNode rotateRight(ListNode head, int k) {
        
        ListNode curr=head;
        if(head==null)
            return null;
        if(head.next==null)
            return head;
        int n=1;
        while(curr.next!=null)
        {
            n++;
            curr=curr.next;
        }
        if(k%n==0)
            return head;
        k=n-k%n;
        curr.next=head;
        curr=head;
       k--;
        while(k-->0)
        {
            curr=curr.next;
        }
        head= curr.next;
        curr.next=null;
        return head;
        
    }
}