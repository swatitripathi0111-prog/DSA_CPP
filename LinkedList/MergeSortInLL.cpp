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
     cout<<temp->data<<"->";
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
    Node* Merge(Node* left,Node* right){
        List ans;
        Node* i = left;
        Node* j = right;

        while(i != NULL && j != NULL){
            if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
            }else{
            ans.push_back(j->data);
            j = j->next;
            }
        }
        while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
        }
        while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
        }
      return ans.head;
    }
    Node* MergeSort(Node* head){
     if(head == NULL || head->next == NULL){
        return head;
     }
     Node* rightHead = SplitAtMiddle(head);
     Node* left = MergeSort(head);
     Node* right = MergeSort(rightHead);
     return Merge(left,right);
    }
};
int main(){
List LL;
LL.push_back(5);
LL.push_back(4);
LL.push_back(3);
LL.push_back(2);
LL.push_back(1);
LL.PrintLL(LL.head);//5->4->3->2->1->NULL
Node* head = LL.MergeSort(LL.head); 
LL.PrintLL(head);//1->2->3->4->5->NULL
 return 0;
}