#include<iostream>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length;i++){
            int index = numbers[i]%length;
            if(numbers[index]>length){
                *duplication = numbers[i]%length;
                return true;
            }
            numbers[index]+=length;
        }
        return false;
    }
};
int main(){
    int a[]={2,3,2,1};
    int *b = new int();
    Solution().duplicate(a,4,b);
    cout<<*b;
    return 0;
}