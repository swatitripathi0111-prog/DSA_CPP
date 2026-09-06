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
    Node* addTwoNumbers(Node* l1, Node* l2) {
       Node* temp1 = l1;
       Node* temp2 = l2;
       int carry = 0;
       int result = 0;
       List resultList;
       while(temp1 != NULL && temp2 != NULL){
        int sum = temp1->val + temp2->val + carry;
        result = sum%10;
        carry = sum/10;
        resultList.push_back(result);
        temp1 = temp1->next;
        temp2 = temp2->next;
       } 
       if(temp2 == NULL){
        while(temp1 != NULL){
        int sum = temp1->val + carry;
        result = sum%10;
        carry = sum/10;
        resultList.push_back(result);
        temp1 = temp1->next;
        }
       }else{
        while(temp2 != NULL){
        int sum = temp2->val + carry;
        result = sum%10;
        carry = sum/10;
        resultList.push_back(result);
        temp2 = temp2->next;
        }
       }
       if(carry != 0){
        resultList.push_back(carry);
       }
       return resultList.head;
    }
};
int main(){
List LL1;
LL1.push_back(2);
LL1.push_back(4);
LL1.push_back(3);
LL1.PrintLL();
List LL2;
LL2.push_back(5);
LL2.push_back(6);
LL2.push_back(4);
LL2.PrintLL();
Node* result = LL1.addTwoNumbers(LL1.head,LL2.head);
Node* temp = result;
while(temp != NULL){
     cout<<temp->val<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
 return 0;
}