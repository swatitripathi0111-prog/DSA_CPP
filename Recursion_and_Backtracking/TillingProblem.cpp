#include<iostream>
using namespace std;
int TillingProblem(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return TillingProblem(n-1) + TillingProblem(n-2);
}
int main(){
cout<<TillingProblem(4)<<endl;
 return 0;
}