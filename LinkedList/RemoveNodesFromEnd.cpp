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
int GetSize(){
  Node* temp = head;
  int sz = 0;
  while(temp != NULL){
    temp = temp->next;
    sz++;
  }
  return sz;
  }
  void RemoveNth(int n){
    int size = GetSize();
    Node* prev = head;
    for(int i=1;i<(size-n);i++){
        prev = prev->next;
    }
    Node* toDel = prev->next;
    cout<<"Going to delete : "<<toDel->val<<endl;
    prev->next = prev->next->next;
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
LL.RemoveNth(2);
LL.PrintLL();
 return 0;
}