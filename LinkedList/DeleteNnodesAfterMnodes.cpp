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
  void DeleteNode(Node* head,int n,int m){
  Node* Curr = head;
  while(Curr != NULL){
  //skip m-1 nodes
  for(int i=1;i<m && Curr != NULL;i++){
   Curr = Curr->next;
  }
  if(Curr == NULL){
    return;
  }
  //Delete N node
  Node* temp = Curr->next;
  for(int i=1;i<=n && temp != NULL;i++){
    Node* nextNode = temp->next;
    delete temp;
    temp = nextNode;
  }
  //reconnect
  Curr->next = temp;
  //next cycle
  Curr = temp;
  }
  }
};
int main(){
List LL;
LL.push_front(8);
LL.push_front(7);
LL.push_front(6);
LL.push_front(5);
LL.push_front(4);
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.printLL();
LL.DeleteNode(LL.head,2,2);
LL.printLL();
 return 0;
}