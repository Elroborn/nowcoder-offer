// ˼·����n��n-1������n�����ұߵ�1ȥ��������
// 1100&1011 = 1000
// ����count++���ɼ�����ж��ٸ�1

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
		 while(n!=0) {
		 	count+=1;
		 	n = n&(n-1);
		 }
		 return count;
     }
};
