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
    public boolean isValidBST(TreeNode root) {
        ArrayList<Integer> arr1=new ArrayList<Integer>();
        ArrayList<Integer> arr2=new ArrayList<Integer>();
        HashSet<Integer> hs=new HashSet<Integer>();
        solve(arr1,arr2,root);
        Collections.sort(arr2);
        hs.addAll(arr2);
        if(hs.size()!=arr1.size())
            return false;
        return arr1.equals(arr2);
    }
    public void solve(ArrayList<Integer> arr1,ArrayList<Integer> arr2, TreeNode root)
    {
        if(root==null)
            return;
        solve(arr1,arr2,root.left);
        arr1.add(root.val);
        arr2.add(root.val);
        solve(arr1, arr2, root.right);
    }
}