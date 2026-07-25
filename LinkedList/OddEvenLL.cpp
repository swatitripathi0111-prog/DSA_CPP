#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node(int val){
    data = val;
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
  Node* SegregateEvenOdd(Node* head){                                                  
  if(head == NULL){
    return head;
  }
  Node* temp = head;
  Node* EvenHead = NULL;
  Node* EvenTail = NULL;
  Node* OddHead = NULL;
  Node* OddTail = NULL;

  while(temp != NULL){
  Node* nextNode = temp->next;
  temp->next = NULL;

  if(temp->data%2 == 0){//even
    if(EvenHead == NULL){
      EvenHead = EvenTail = temp;
    }else{
    EvenTail->next = temp;
    EvenTail = temp;
    }
  }else{//odd
    if(OddHead == NULL){
      OddHead = OddTail = temp;
    }else{
      OddTail->next = temp;
      OddTail = temp;
    }
  }
  temp = nextNode;
  }
  if(EvenHead == NULL){
    return OddHead;
  }
  if(OddHead == NULL){
    return EvenHead;
  }
  EvenTail->next = OddHead;
  return EvenHead;
  }
};
int main(){
List LL;
LL.push_front(6);
LL.push_front(1);
LL.push_front(4);
LL.push_front(5);
LL.push_front(10);
LL.push_front(12);
LL.push_front(8);
LL.printLL();
LL.SegregateEvenOdd(LL.head);
LL.printLL();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
 return 0;
}