/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        if(root==null)
            return ans;
        List<Integer> arr=new ArrayList<Integer>();
        Queue <TreeNode> q=new LinkedList<TreeNode>();
        q.offer(root);
        q.offer(null);
        int c=1;
        while(q.size()!=0)
        {
            TreeNode curr=q.poll();
            if(curr==null)
            {
                if(q.size()!=0)
                {
                    if(c%2==0)
                        Collections.reverse(arr);
                    ans.add(arr);
                    arr=new ArrayList<Integer>();
                    q.offer(null);
                    c++;
                }
            }
            else
            {
                if(curr.left!=null)
                    q.offer(curr.left);
                if(curr.right!=null)
                    q.offer(curr.right);
                arr.add(curr.val);
            }
        }
        if(c%2==0)
            Collections.reverse(arr);
        ans.add(arr);
        return ans;
    }
}