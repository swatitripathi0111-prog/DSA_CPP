#include<iostream>
using namespace std;
int Factorial(int n){
if(n == 0) return 1;
 return n*Factorial(n-1);
}
void DecreasingOrderNum(int n){
if(n == 0) return ;
cout<<n<<" ";
DecreasingOrderNum(n-1);
} 
void IncreasingOrderNum(int n){
if(n == 0) return;
IncreasingOrderNum(n-1);
cout<<n<<" ";
}
int SumOfN(int n){
if(n == 1) return 1;
return n+SumOfN(n-1);
}
int Fibonacci(int n){
if(n == 0 || n == 1){
    return n;
}
return Fibonacci(n-1)+Fibonacci(n-2); 
}                                             
int main(){
cout<<Factorial(5)<<endl;//120
DecreasingOrderNum(5);//5 4 3 2 1
cout<<endl;
IncreasingOrderNum(5);//1 2 3 4 5
cout<<endl;
cout<<SumOfN(5)<<endl; //15
cout<<Fibonacci(5)<<endl;//5
 return 0;
}