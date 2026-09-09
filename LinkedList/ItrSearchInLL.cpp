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
  ~Node(){
  if(next != NULL){
    delete next ;
    next = NULL;
  }
}
};
class List{
public:
   Node* head;
   Node* tail;
   List(){
    head = tail = NULL;
   }
   ~List(){
    if(head != NULL){
      delete head;
      head = NULL;
    }
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
   int ItrSearch(int key){
   Node* temp = head;
   int idx = 0;
   while(temp != NULL){
    if(temp->data == key){
    return idx;
    }
    temp = temp->next;
    idx++;
   }
   return -1;
  }
};
int main(){
List LL;
LL.push_front(5);
LL.push_front(4);
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.PrintLL();
cout<<LL.ItrSearch(2)<<endl;//1
cout<<LL.ItrSearch(9)<<endl;//-1
 return 0;
}