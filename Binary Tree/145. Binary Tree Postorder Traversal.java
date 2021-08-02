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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> arr=new ArrayList<Integer>();
        solve(arr, root);
        return arr;
    }
    void solve(List<Integer> arr, TreeNode root)
    {
        if(root==null)
            return;
        solve(arr,root.left);
        solve(arr,root.right);
        arr.add(root.val);
    }
}