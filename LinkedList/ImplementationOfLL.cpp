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
      cout<<temp->data<<"->";
      temp = temp->next;
    }
    cout<<"NULL\n";
   }
   void InsertNodeInMiddle(int val,int pos){
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i=0;i<pos-1;i++){
      if(temp == NULL){
        cout<<"INVALID POSITION\n";
        return;
      }
      temp = temp->next;
    }
    //temp is now at pos-1;
    newNode->next = temp->next;
    temp->next = newNode;
   }
   void pop_front(){
    if(head == NULL){
      cout<<"LL is empty";
      return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
   }
  void pop_back(){
  Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  temp->next = NULL;
  delete tail;
  tail = temp;
  } 
};
int main(){
List LL;
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.push_back(4);
LL.push_back(5);
LL.PrintLL();//1->2->3->4->5->NULL
LL.InsertNodeInMiddle(100,2);
LL.PrintLL();//1->2->100->3->4->5->NULL
LL.pop_front();
LL.PrintLL();//2->100->3->4->5->NULL
LL.pop_back();
LL.PrintLL();//2->100->3->4->NULL
 return 0;
}