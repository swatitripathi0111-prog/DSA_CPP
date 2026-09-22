#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int timeRequiredToBuy(vector<int>& tickets, int k){
    queue<int> q;
    int n = tickets.size();
    for(int i=0;i<n;i++){
    q.push(i);
    }
    int time = 0;
    while(tickets[k] > 0){
     int person = q.front();
     q.pop();
     
     tickets[person]--;
     time++;
     if(tickets[person] > 0){
      q.push(person);
     }
    }
    return time;
}
int main(){
vector<int> tickets = {2,3,2};
int k = 2;
cout<<"Time needed to buy tickets = "<<timeRequiredToBuy(tickets,k)<<endl;
 return 0;
}