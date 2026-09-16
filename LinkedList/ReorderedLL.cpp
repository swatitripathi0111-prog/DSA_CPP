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
   void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
     cout<<temp->val<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
    }
    Node* SplitAtMiddle(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL){
            prev->next = NULL;
        }
        return slow;
    }
    Node* Reverse(Node* head){
     Node* Curr = head;
     Node* prev = NULL;

     while(Curr != NULL){
     Node* next = Curr->next;
     Curr->next = prev;

     prev = Curr;
     Curr = next;
     }
     return prev;
    }
    Node* ReorderedLL(Node* head){
     Node* rightHead = SplitAtMiddle(head);
     Node* rightHeadRev = Reverse(rightHead);

     Node* left = head;
     Node* right = rightHeadRev;
     Node* tail = right;

     while(left != NULL && right != NULL){
       Node* leftnext = left->next;
       Node* rightnext = right->next;

       left->next = right;
       right->next = leftnext;
       tail = right;

       left = leftnext;
       right = rightnext;
     }
     if(right != NULL){
     tail->next = right;
     }
     return head;
    }
};
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(3);
LL.push_back(4);
LL.push_back(5);
LL.PrintLL(LL.head);//1->2->3->4->5->NULL
Node* head = LL.ReorderedLL(LL.head);
LL.PrintLL(head);//1->5->2->4->3->4->5->NULL
 return 0;
}