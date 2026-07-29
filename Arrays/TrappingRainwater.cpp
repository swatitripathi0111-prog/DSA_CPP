#include<iostream>
using namespace std;
int MaxWaterTrapped(int *height,int n){
    int LeftMax[20000],RightMax[20000];
    LeftMax[0] = height[0];
    RightMax[n-1] = height[n-1];
    for(int i=1;i<n;i++){
    LeftMax[i] = max(LeftMax[i-1],height[i-1]);
    }
    for(int i=n-2;i>=0;i--){
    RightMax[i] = max(RightMax[i+1],RightMax[i+1]);
    }
    int MaxWater = 0;
    for(int i=0;i<n;i++){
     int CurrWater = min(LeftMax[i],RightMax[i])-height[i];
     if(CurrWater > 0){
      MaxWater += CurrWater;
     }
    }
    return MaxWater;
}
int main(){
int Height[7] = {4,2,0,6,3,2,5};
cout<<MaxWaterTrapped(Height,7); 
 return 0;
}