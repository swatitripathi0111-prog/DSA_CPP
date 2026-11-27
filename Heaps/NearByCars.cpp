#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car{
public:
   int idx;
   int DisSq;
   Car(int idx,int DisSq){
    this->idx = idx;
    this->DisSq = DisSq;
   }
   bool operator <(const Car &obj) const{//min heap
     return this->DisSq > obj.DisSq;
   }
};
void NearBYCars(vector<pair<int,int>> pos,int k){
    vector<Car> cars;
    for(int i=0;i<pos.size();i++){
      int DisSq = (pos[i].first * pos[i].first)+(pos[i].second * pos[i].second);
      cars.push_back(Car(i,DisSq));
    }
    priority_queue<Car> pq(cars.begin(),cars.end());

    for(int i=0;i<k;i++){
     cout<<"Car"<<pq.top().idx<<endl;
     pq.pop();
    }
}
int main(){
vector<pair<int,int>> pos;
pos.push_back(make_pair(3,3));
pos.push_back(make_pair(5,-1));
pos.push_back(make_pair(-2,4));
int k = 2;
NearBYCars(pos,k);
return 0;
}