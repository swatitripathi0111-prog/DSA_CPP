#include<iostream>
using namespace std;
void TowerOfHanoi(int n,char s,char h,char d){
if(n == 0){
    return;
}
TowerOfHanoi(n-1,s,d,h);
cout<<s<<"->"<<d<<endl;
TowerOfHanoi(n-1,h,s,d);
}
int main(){
TowerOfHanoi(3,'A','B','C');
return 0;
}