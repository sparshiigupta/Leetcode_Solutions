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
    public ArrayList<Integer> liste(ListNode head)
    {
        ArrayList<Integer> arr=new ArrayList<Integer>();
        while(head!=null)
        {
            arr.add(head.val);
            head=head.next;
        }
        return arr;
    }
    public int[] nextLargerNodes(ListNode head) {
        Stack <Integer> st=new Stack<Integer>();
        ArrayList<Integer> arr=new ArrayList<Integer>();
        ArrayList<Integer> ans=new ArrayList<Integer>();
        arr=liste(head);
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(st.isEmpty())
                ans.add(0);
            else
            {
                if(st.peek()>arr.get(i))
                    ans.add(st.peek());
                else
                {
                    while(st.size()!=0 && st.peek()<=arr.get(i))
                        st.pop();
                    if(st.size()==0)
                        ans.add(0);
                    else
                        ans.add(st.peek());
                }
            }
            st.push(arr.get(i));
        }
        Collections.reverse(ans);
        Object obj[]=ans.toArray();
        int a[]=new int[ans.size()];
        for(int i=0;i<ans.size();i++)
            a[i]=(int)obj[i];
        return a;
    }
}