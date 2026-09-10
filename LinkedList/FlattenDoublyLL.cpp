#include<iostream>
using namespace std;
class Node{
public:
  int val;
  Node* next;
  Node* child;
  Node* prev;
  Node(int val){
    this->val = val;
    next = child =  NULL;
  }
};
class List{
public:
   Node* head;
   Node* tail;
   List(){
    head = tail = NULL;
   }
    Node* flatten(Node* head) {
    if(head == NULL){
    return head;
    }
    Node* Curr = head;
    while(Curr != NULL){
        if(Curr->child != NULL){
            Node* next = Curr->next;
            Curr->next = flatten(Curr->child);
            Curr->next->prev = Curr;
            Curr->child = NULL;

        while(Curr->next != NULL){
            Curr = Curr->next;
        }
        if(next != NULL){
            Curr->next = next;
            next->prev = Curr;
        }
        }
        Curr = Curr->next;
    }
    return head;
    }
};
int main(){
return 0;
}