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
    void ReverseLL(){
    Node* Curr = head;
    Node* prev = NULL;
    while(Curr != NULL){
    Node* next = Curr->next;
    Curr->next = prev;
    prev = Curr;
    Curr = next;
    }
    head = prev;
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
LL.ReverseLL();
LL.PrintLL();
return 0;
}
