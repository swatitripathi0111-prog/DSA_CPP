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
    bool DetectCycle(Node* root){

    }
};
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
        cout<<"Cycle exists\n";
        return true;
        }
    }
    cout<<"Cycle does not exists\n";
    return false;
}
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(3);
LL.push_back(4);
LL.tail->next = LL.head;
isCycle(LL.head);
return 0;
}