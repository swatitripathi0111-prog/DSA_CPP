#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
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
Node* ReverseBetween(Node* head,int left,int right){
    if(left == right){
        return head;
    }
    Node* temp1 = head;
    Node* temp2 = head;
    Node* prev1 = head;
    Node* prev2 = head;
    int idx1 = 1;
    int idx2 = 1;     

    if(left == 1){
    prev1 = prev2 = NULL;
    }
    if(left > 1){
     for(int i=1;i<=left-2;i++){
        prev1 = prev1->next;
        prev2 = prev2->next;
     }
    }
    while(idx1 != left){
        temp1 = temp1->next;
        idx1++;
    }
    while(idx2 != right){
        temp2 = temp2->next;
        idx2++;
    }
    Node* Curr = temp1;
    Node* After = temp2->next;

    while(Curr != After){
      Node* next = Curr->next;
      Curr->next = prev1;
      prev1 = Curr;
      Curr = next;
    }
    temp1->next = After;
    if(left == 1){
        return prev1;
    }else{
        prev2->next = prev1;
        return head;
    }
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
LL.ReverseBetween(LL.head,2,4);
LL.PrintLL();
return 0;
}