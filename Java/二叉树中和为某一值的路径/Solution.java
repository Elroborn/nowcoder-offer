import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(final int val) {
        this.val = val;

    }

}

public class Solution {

    public ArrayList<ArrayList<Integer>> FindPath(final TreeNode root, final int target) {
        final ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        final ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(root, target, cur, res);
        Collections.sort(res, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(final ArrayList<Integer> o1, final ArrayList<Integer> o2) {
                if (o1.size() < o2.size()) {
                    return 1;
                } else
                    return -1;
            }
        });
        return res;
    }

    private void dfs(final TreeNode root, final int target, final ArrayList<Integer> cur,
            final ArrayList<ArrayList<Integer>> res) {
        if (root == null) {
            return;
        }
        final int val = root.val;
        cur.add(val);
        if (root.left == null && root.right == null && val == target) {
            res.add(new ArrayList<Integer>(cur)); // 一定要注意将cur复制一份，否则后面remove后res也会被修改
        } else {
            dfs(root.left, target - val, cur, res);
            dfs(root.right, target - val, cur, res);
        }
        cur.remove(cur.size() - 1); // 要注意移除
    }

    // private static void tt(final ArrayList<Integer> a) {
    //     a.add(233);
    // }

    public static void main(final String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(1);
        root.right.left = new TreeNode(1);
        final ArrayList<ArrayList<Integer>> res = new Solution().FindPath(root, 3);
        System.out.println(res);
        // ArrayList<Integer> a = new ArrayList<>();
        // tt(a);
        // System.out.println(a);
    }
}