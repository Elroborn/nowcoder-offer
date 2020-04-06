#include<iostream>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        n&&(n+=Sum_Solution(n-1));
        return n;
    }
};
int main(){
    cout<<Solution().Sum_Solution(5);
    return 0;
}