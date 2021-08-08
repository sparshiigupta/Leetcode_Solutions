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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        List<Integer> arr=new ArrayList<Integer>();
        if(root==null)
            return ans;
        Queue <TreeNode> q=new LinkedList<TreeNode>();
        q.offer(root);
        q.offer(null);
        while(q.size()!=0)
        {
            TreeNode curr=q.poll();
            if(curr==null)
            {
                if(q.size()!=0)
                {
                    q.offer(null);
                    ans.add(arr);
                    arr=new ArrayList<Integer>();
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
        ans.add(arr);
        Collections.reverse(ans);
        return ans;
    }
}