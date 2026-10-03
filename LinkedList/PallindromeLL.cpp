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
    ListNode* SplitAtMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
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
    ListNode* Reverse(ListNode* head){
     ListNode* Curr = head;
     ListNode* prev = NULL;
     while(Curr != NULL){
        ListNode* next = Curr->next;
        Curr->next = prev;
        prev = Curr;
        Curr = next;
     }
     return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
        return true;
        }
      ListNode* rightHead = SplitAtMiddle(head);
      ListNode* rightHeadRev = Reverse(rightHead);

      ListNode* temp1 = head;
      ListNode* temp2 = rightHeadRev;

      while(temp1 != NULL && temp2 != NULL){
        if(temp1->val != temp2->val){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
      return true;
    }
};  
int main(){
List LL;
LL.push_back(1);
LL.push_back(2);
LL.push_back(2);
LL.push_back(1);
LL.PrintLL();
cout<<LL.isPalindrome(LL.head);
return 0;
}