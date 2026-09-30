#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
vector<int> A = {4,1,8,7};
vector<int> B = {2,3,6,5};
sort(A.begin(),A.end());
sort(B.begin(),B.end());
int AbsDiff = 0;
for(int i=0;i<A.size();i++){
    AbsDiff += abs(A[i]-B[i]);
}
cout<<"Min Absolute Difference = "<<AbsDiff<<endl;
return 0;
}