#include<iostream>
using namespace std;
class Node{
public:
  int val;
  Node* next;
  Node(int val){
    this->val = val;
    next = NULL;
  }
};
class List{
public:
   Node* head;
   Node* tail;
   List(){
    head = tail = NULL;
   }
   void push_back(int val){
     Node* newNode = new Node(val);
     if(head == NULL){
        head = tail = newNode;
     }else{
        tail->next = newNode;
        tail = newNode;
     }
   }
   void PrintLL(){
    Node* temp = head;
    while(temp != NULL){
     cout<<temp->val<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
    }
    int Helper(Node* temp,int key){
     if(temp == NULL){
        return -1;
     }
     if(temp->val == key){
        return 0;
     }
     int idx = Helper(temp->next,key);
     if(idx == -1){
        return -1;
     }
     return idx+1;
    }
    int RecSearch(int key){
        return Helper(head,key);
    }
};
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(3);
LL.push_back(4);
LL.push_back(5);
LL.PrintLL();
cout<<LL.RecSearch(4)<<endl;
return 0;
}