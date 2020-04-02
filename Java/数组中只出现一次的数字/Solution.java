//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
// 链接：https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811?f=discussion
// 来源：牛客网
// 首先：位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
// 当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，最后剩下的就是落单的数，因为成对儿出现的都抵消了。
// 依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还是先异或，剩下的数字肯定是A、B异或的结果，
// 这个结果的二进制中的1，表现的是A和B的不同的位。我们就取第一个1所在的位数，假设是第3位，接着把原数组分成两组，
// 分组标准是第3位是否为1。如此，相同的数肯定在一个组，因为相同数字所有位都相同，
// 而不同的数，肯定不在一组。然后把这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。
public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {
        if(array.length==2){
            num1[0] = array[0];
            num2[0] = array[1];
            return ;
        }
        int bitRes = 0;
        for(int i=0;i<array.length;i++){
            bitRes = (bitRes^array[i]); //因为相同的数异或为0，所以最终bitRes里面是两个不同数A、B的异或结果
        }
        // 在异或时，不同为1，所以找到bitRes中为1的位置，即代表了A、B不同的位数
        int index = 0;
        while((bitRes&1)==0 && index<32){ // 1其实是00001，所以如果（bitRes&1==0）代表最后一位不是1，所以右移，直到为1
            bitRes>>=1;
            index ++;
        }
        // 之后分为两组，一组是index位为1的，一组是不为1的，所以最后相同的肯定在同一组，而不同的则会被分到两组（因为index为1的位置代表AB不同）
        // 而每组各自做异或，最后剩下的就是A和B
        for(int i=0;i<array.length;i++){
            if(((array[i]>>index)&1)==0){ //>>index即把第index位放到末尾，这样就能和1&了，判断这个位是0还是1
                num1[0] ^=array[i]; //异或到最后就是那两个不同的数
            }else{
                num2[0] ^=array[i]; //异或到最后就是那两个不同的数
            }
        }
    }
    public static void main(String[] args) {
        int a[] = {1,2,1,3,4,5,4,5};
        int num1[]={0};
        int num2[]={0};
        new Solution().FindNumsAppearOnce(a, num1, num2);
        System.out.println(num1[0]);
        System.out.println(num2[0]);
    }
}