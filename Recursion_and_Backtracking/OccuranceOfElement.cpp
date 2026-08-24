#include<iostream>
using namespace std;
void AllOccuranceOfElement(int *nums,int n,int i,int key){
if(i == n){
 return;
}
if(nums[i] == key){
 cout<<i;
}
AllOccuranceOfElement(nums,n,i+1,key);
}
int main(){
int n = 9;
int nums[9] = {3,2,4,5,6,2,7,2,2};
AllOccuranceOfElement(nums,n,0,2);
 return 0;
}