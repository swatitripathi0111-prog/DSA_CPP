#include<iostream>
#include<list>
using namespace std;
void PrintLL(list<int> ll){
    list<int> :: iterator itr;
    for(itr = ll.begin();itr != ll.end();itr++){
     cout<<(*itr)<<"->";
    }
    cout<<"NULL\n";
}
int main(){
list<int> ll;
ll.push_front(2);
ll.push_front(1);
ll.push_back(3);
ll.push_back(4);
PrintLL(ll);//1->2->3->4->NULL
cout<<"Size = "<<ll.size()<<endl;
cout<<"head = "<<ll.front()<<endl;
cout<<"tail = "<<ll.back()<<endl;
ll.pop_back();
PrintLL(ll);//1->2->3->NULL
ll.pop_front();
PrintLL(ll);//2->3->NULL
 return 0;
}