import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix) {
        int row = matrix.length,col = matrix[0].length;
        ArrayList<Integer> res = new ArrayList<Integer>();
        int circle = ((row>col?col:row) -1)/2 + 1;// 计算圈数(a-1)/2 + 1 有上取整的意思
        for(int c=0;c<circle;c++){
            for(int i=c;i<col-c;i++){res.add(matrix[c][i]);} //从左到右
            for(int j=c+1;j<row-c;j++){res.add(matrix[j][col-c-1]);} //从上到下
            for(int k=col-c-1-1;k>=c&&row-c-1!= c;k--){res.add(matrix[row-c-1][k]);}//从右到左 ，发现如果单行，即row-c-1 = c 时会出现重复，则判断加入row-c-1 != c
            for(int l = row-c-1-1;l>c&&col-c-1 != c;l--){res.add(matrix[l][c]);}//从下到上 ，发现如果单列，即col-c-1 = c，则重复，所以加入判断col-c-1 != c
        }
        return res;
    }
    public static void main(String[] args) {
        int array[][] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
        ArrayList<Integer> res = new Solution().printMatrix(array);
        System.out.println(res);
    }
}