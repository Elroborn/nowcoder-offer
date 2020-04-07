// 链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46?f=discussion
// 来源：牛客网

// <分析>：
// 解释下代码，设有数组大小为5。
// 对于第一个for循环
// 第一步：b[0] = 1;
// 第二步：b[1] = b[0] * a[0] = a[0]
// 第三步：b[2] = b[1] * a[1] = a[0] * a[1];
// 第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
// 第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
// 然后对于第二个for循环
// 第一步
// temp *= a[4] = a[4]; 
// b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
// 第二步
// temp *= a[3] = a[4] * a[3];
// b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
// 第三步
// temp *= a[2] = a[4] * a[3] * a[2]; 
// b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
// 第四步
// temp *= a[1] = a[4] * a[3] * a[2] * a[1]; 
// b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
// 由此可以看出从b[4]到b[0]均已经得到正确计算。
import java.util.ArrayList;
public class Solution {
    //B[i] = A[0]*..A[i-1]*A[i+1]*..A[n]
    // 如果一次将B[i]计算完，则之前的数据无法重复利用，造成大量乘法
    // 所以先计算A[0]**A[i] 保存，再计算A[i]**A[n]，这样则是叠加，算后面可以利用前面元素
    //从上向下填左下角，从上往下填右上角
    public int[] multiply(int[] A) {
        int[] res = new int[A.length];
        if(A.length==0){
            return res;
        }
        res[0] =1;
        for(int i=1;i<A.length;i++){
            res[i] = res[i-1]*A[i-1];
        }
        int tmp = 1;
        for(int i=A.length-1;i>=0;i--){
            res[i]*=tmp;
            tmp*=A[i];
        }
        return res;
    }
    public static void main(String[] args) {
        int a[] ={2,3,4};
        int[] res = new Solution().multiply(a);
        for(int i=0;i<res.length;i++)
            System.out.println(res[i]);
    }
}