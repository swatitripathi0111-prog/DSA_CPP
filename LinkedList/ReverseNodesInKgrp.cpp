#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node(int val){
    this->data = val;
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
   void push_front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
    head = tail = newNode;
    }else{
     newNode->next = head;
     head = newNode; 
    }
   }
    void printLL(){
   Node* temp = head;
   while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
   }
   cout<<"NULL\n";
  }
  int GetSize(){
  int sz = 0;
  Node* temp = head;
  while(temp != NULL){
    temp = temp->next;
    sz++;
  }
  return sz;
  }
  Node* reverseKGroup(Node* head, int k){
 Node* Curr = head;
 Node* prev = NULL;
 Node* temp = head;
 Node* ptr = NULL;
int n = GetSize()/k;


 for(int i=0;i<n;i++){
    int idx = 1;
    Node* startGrp = Curr;
    while(idx != k){
    temp = temp->next;
    idx++;
    }
    if(idx == k){
     Node* nextGrp = temp->next;

     while(Curr != nextGrp){
      Node* next = Curr->next;
      Curr->next = prev;
      prev = Curr;
      Curr = next;
     }
     startGrp->next = nextGrp;

     if(ptr == NULL){
       head = prev;
     }else{
       ptr->next = prev;
     }
     ptr = startGrp;
     prev = NULL;
     temp = Curr;
    }
 }
 return head;
}  
};
int main(){
List LL;
LL.push_front(4);
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.printLL();
Node* result = LL.reverseKGroup(LL.head,2);
Node* temp = result;
while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
}
   cout<<"NULL\n";
 return 0;
}