#include<iostream>
#include<vector>
using namespace std;
int Pow(int x,int n){//x^n
if(n == 0){
    return 1;
}
int HalfPow = Pow(x,n/2);
int HalfPowSquare = HalfPow * HalfPow;
if(n%2 != 0){
    return x*HalfPowSquare;
}
return HalfPowSquare;
}
int main(){
cout<<Pow(2,10)<<endl ;
 return 0;
} 