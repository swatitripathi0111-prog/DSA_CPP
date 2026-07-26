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
  void PrintLL(){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL\n";
  }
  Node* MergeKsortedLL(Node* head1,Node* head2){
  if(head1 == NULL) return head2;
  if(head2 == NULL) return head1;

  Node* i = head1;
  Node* j = head2;
  Node* Dummy = new Node(-1);
  Node* tail = Dummy;

  while(i != NULL && j != NULL){
    if(i->data <= j->data){
    tail->next = i;
    tail = i;
    i = i->next;
    }else{
      tail->next = j;
      tail = j;
      j = j->next;
    }
  }
  while(i != NULL){
    tail->next = i;
    tail = i;
    i = i->next; 
  }
  while(j != NULL){
     tail->next = j;
      tail = j;
      j = j->next;
  }
  return Dummy->next;
}
};
int main(){
List l[3];
List obj;
//L0 : 1->3->NULL
l[0].push_front(3);
l[0].push_front(1);
l[0].PrintLL();
//L1 : 6->8->NULL
l[1].push_front(8);
l[1].push_front(6);
l[1].PrintLL();
//L2 :9->10->NULL
l[2].push_front(10);
l[2].push_front(9);
l[2].PrintLL();
Node* result = l[0].head;
for(int i=1;i<3;i++){//k=3
  result = obj.MergeKsortedLL(result,l[i].head);
}
while(result != NULL){
  cout<<result->data<<"->";
  result = result->next;
}
cout<<"NULL\n";
 return 0;
}