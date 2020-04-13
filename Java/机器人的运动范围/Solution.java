public class Solution {
    public int movingCount(int threshold, int rows, int cols)
    {
        boolean flag[] = new boolean[rows*cols];
        return dfs(0, 0, flag, threshold, rows, cols);
        
    }
    public int dfs(int i,int j,boolean[]flag,int threshold,int rows,int cols){
        int index = i*cols +j;
        if(i<0||i>=rows||j<0||j>=cols||flag[index]==true||getNUm(i)+getNUm(j)>threshold){
            return 0;
        }
        flag[index] = true;
        return 1+dfs(i-1, j, flag, threshold, rows, cols) +
        dfs(i+1, j, flag, threshold, rows, cols)+
        dfs(i, j-1, flag, threshold, rows, cols)+
        dfs(i, j+1, flag, threshold, rows, cols);

    }
    public int getNUm(int i){
        int sum = 0;
        do{
            sum+=i%10;
        }while((i=i/10)>0);
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().movingCount(1, 2, 2));
    }
}