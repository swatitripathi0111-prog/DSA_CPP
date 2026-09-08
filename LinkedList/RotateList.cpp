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
    Node* temp = head;
    int sz = 0;
    while(temp != NULL){
     temp = temp->next;
     sz++;
    }
    return sz;
  }
  Node* rotateRight(Node* head, int k){
  int size = GetSize();
  if(k == 0 || head == NULL || k == size || size == 1 || k%size == 0){
    return head;
  }
  if(size < k){
    while(size < k){
    k = k-size;
    }
  }
  Node* prev = head;
  for(int i=1;i<(size-k);i++){
    prev = prev->next;
  }
  Node* temp1 = prev->next;
  Node* temp2 = prev->next;

   for(int i=1;i<k;i++){
    temp2 = temp2->next;
   }
   prev->next = NULL;
   temp2->next = head;
   return temp1;
  }
};
int main(){
List LL;
LL.push_front(5);
LL.push_front(4);
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.printLL();
Node* result = LL.rotateRight(LL.head,2);//output : [4,5,1,2,3]
Node* temp = result;
while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
   }
   cout<<"NULL\n";
return 0;
}