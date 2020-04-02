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
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()==2){
            *num1 = data[0];
            *num2 = data[1];
        }
        int bitRes = 0;
        for(int i=0;i<data.size();i++){
            bitRes^= data[i];
        }
        int index = 0;
        while ((bitRes&1)==0 && index<32)
        {
            bitRes>>=1;
            index++;
        }

        for(int i=0;i<data.size();i++){
            if(((data[i]>>index)&1)==0){
                *num1^=data[i];
            }else{
                *num2^=data[i];
            }
        }
        

    }
};
int main(){
    vector<int> arr = {1,2,1,3,4,5,4,5};
    int* num1 = new int(0);
    int* num2 = new int(0);
    Solution().FindNumsAppearOnce(arr,num1,num2);
    cout<<*num1<<*num2;
    return 0;
}