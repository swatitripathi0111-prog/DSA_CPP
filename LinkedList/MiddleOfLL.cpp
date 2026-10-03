#include<iostream>
using namespace std;
class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    next = NULL;
  }
};
class List{
public:
   ListNode* head;
   ListNode* tail;
   List(){
    head = tail = NULL;
   }
   void push_back(int val){
     ListNode* newNode = new ListNode(val);
     if(head == NULL){
        head = tail = newNode;
     }else{
        tail->next = newNode;
        tail = newNode;
     }
   }
   void PrintLL(){
    ListNode* temp = head;
    while(temp != NULL){
     cout<<temp->val<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
    }
    ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;

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
};
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(3);
LL.push_back(4);
LL.push_back(5);
LL.PrintLL();
cout<<"Middle of LL = "<<LL.middleNode(LL.head)->val<<endl;
return 0;
}