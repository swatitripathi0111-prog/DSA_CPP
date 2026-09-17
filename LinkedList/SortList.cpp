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
   void PrintLL(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
     cout<<temp->val<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
    }
    ListNode* SplitAtMiddle(ListNode* head){
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
    ListNode* merge(ListNode* left,ListNode* right){
       ListNode* Dummy = new ListNode(-1);
       ListNode* tail = Dummy;

       ListNode* i = left;
       ListNode* j = right;
       while(i != NULL && j != NULL){
         if(i->val <= j->val){
           tail->next = i;
           tail = i;
           i = i->next;
         }else{
            tail->next = j;
           tail = j;
           j = j->next; 
         }
       }
       while(i != NULL){
         tail->next = i;
           tail = i;
           i = i->next;
       }
       while(j != NULL){
         tail->next = j;
         tail = j;
         j = j->next;
       }
       return Dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
       ListNode* rightHead = SplitAtMiddle(head);
       ListNode* left =  sortList(head);
       ListNode* right = sortList(rightHead);
       return merge(left,right);
    }
};
int main(){
List LL;
LL.push_back(4);
LL.push_back(2);
LL.push_back(1);
LL.push_back(3);
LL.PrintLL(LL.head);
ListNode* head = LL.sortList(LL.head);
LL.PrintLL(head);
return 0;
}