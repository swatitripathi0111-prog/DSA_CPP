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
};
void RemoveCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
         cout<<"Cycle Exists\n";
         isCycle = true;
         break;
        }
    }
    if(!isCycle){
    cout<<"Cycle does not Exists\n";
    return;        
    }
    slow = head;
    if(slow == fast){

      while(fast->next != slow){
        fast = fast->next;
      }
      fast->next = NULL;
    }else{

    Node* prev = fast;
    while(slow != fast){
    slow = slow->next;
    prev = fast;
    fast = fast->next;
    }
    prev->next = NULL;
    }
}
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(3);
LL.push_back(4);
LL.tail->next = LL.head;
RemoveCycle(LL.head);
LL.PrintLL();
return 0;
}