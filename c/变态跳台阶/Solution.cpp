#include<iostream>
using namespace std;
class Solution {
	// ����̨��һ��������һ��̨�� ��1�֣�2��̨����2�֣�
	// 3��̨��ʱ�����ܿ����ڵ�2�����1��������������� 1 + 1 +2 = 4
	// 4��̨��ʱ�����ܿ����ڵ�3�����2�����1��������������� 1 + 1 + 2 + 4 = 8 ��
	//����n��̨�׼� 1 + 1 + 2 + 4 + 8 + ..  = 2^(n -1)
public:
    int jumpFloorII(int number) {
    	return 1<<(number-1);
    }
};

int main(){
	cout<< Solution().jumpFloorII(4);
	return 0;
}
