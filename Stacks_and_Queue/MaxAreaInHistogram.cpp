#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int MaxAreaHistogram(vector<int> height){
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    //calculate next smaller left;
    s.push(0);
    nsl[0] = -1;
    for(int i=1;i<n;i++){
        int Curr = height[i];
      while(!s.empty() && Curr <= height[s.top()]){
        s.pop();
      }
      if(s.empty()){
        nsl[i] = -1;
      }else{
        nsl[i] = s.top();
      }
      s.push(i);
    }
    while(!s.empty()){
     s.pop();
    }
    //calculate next smaller right
    s.push(n-1);
    nsr[n-1] = n;
    for(int i = n-2;i>=0;i--){
    int Curr = height[i];
     while(!s.empty() && Curr <= height[s.top()]){
        s.pop();
     }
     if(s.empty()){
     nsr[i] = n;
     }else{
        nsr[i] = s.top();
     }
     s.push(i);
    }
    int MaxArea = 0;
    for(int i=0;i<n;i++){
    int CurrArea = height[i] * (nsr[i]-nsl[i]-1);
    MaxArea = max(CurrArea,MaxArea);
    }
    return MaxArea;
}
int main(){
vector<int> height = {2,1,5,6,2,3};
cout<<"Max Area = "<<MaxAreaHistogram(height)<<endl;
 return 0;
}