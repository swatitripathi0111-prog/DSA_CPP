#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
public:
  int idx;
  int Deadline;
  int profit;
  Job(int idx,int Deadline,int profit){
    this->idx = idx;
    this->Deadline = Deadline;
    this->profit = profit;
  }
};
int MaxProfit(vector<pair<int,int>> pairs){
    int n = pairs.size();
    vector<Job> jobs;
    for(int i=0;i<n;i++){
     jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job&b){
        return a.profit > b.profit;
    });
    int profit = jobs[0].profit;
    int SafeDeadline = 2;
    cout<<"selecting jobs"<<jobs[0].idx<<endl;
    for(int i=1;i<n;i++){
     if(jobs[i].Deadline >= SafeDeadline){
     cout<<"selecting jobs"<<jobs[i].idx<<endl;
     profit += jobs[i].profit;
     SafeDeadline++;
     }
    }
    return profit;
}
int main(){
int n = 4;
vector<pair<int,int>> jobs(n,make_pair(0,0));
jobs[0] = make_pair(4,20);
jobs[1] = make_pair(1,10);
jobs[2] = make_pair(1,40);
jobs[3] = make_pair(1,30);
cout<<"Maximum profit from jobs = "<<MaxProfit(jobs)<<endl;
return 0;
}