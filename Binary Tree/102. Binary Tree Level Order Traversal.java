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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        Queue <TreeNode> q=new LinkedList<TreeNode>();
        if(root==null)
            return ans;
        q.offer(root);
        q.offer(null);
        List<Integer> arr=new ArrayList<Integer>();
        while(q.size()!=0)
        {
            TreeNode curr=q.poll();
            if(curr==null)
            {
                if(q.size()!=0)
                {
                    ans.add(arr);
                    arr=new ArrayList<Integer>();
                    q.offer(null);
                }
            }
            else
            {
                if(curr.left!=null)
                    q.offer(curr.left);
                if(curr.right!=null)
                    q.offer(curr.right);
                arr.add(curr.val);
                //System.out.println(curr.val);
            }
        }
        ans.add(arr);
        return ans;
            
    }
}