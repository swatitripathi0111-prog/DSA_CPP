#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node* next;
 Node(int val){
  data = val;
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
  void IntersectionOfLL(Node* head1,Node* head2){
  Node* temp1 = head1;
  Node* temp2 = head2;
  int len1 = 0;
  int len2 = 0;
  
  while(temp1 != NULL){
    temp1 = temp1->next;
    len1++;
  }
  while(temp2 != NULL){
    temp2 = temp2->next;
    len2++;
  }
  temp1 = head1;
  temp2 = head2;
  int diff = len1-len2;
  if(diff>0){ //LL1 is larger than ll2
   for(int i=0;i<diff;i++){
    temp1 = temp1->next;
   }
  }else{
    for(int i=0;i<-diff;i++){
    temp2 = temp2->next;
    }
  }
  while(temp1 != NULL && temp2 != NULL){
    if(temp1 == temp2){
    cout<<"The intersection point is "<<temp1->data<<endl;
    break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  }
};
int main(){
Node* newNode = new Node(6);
newNode->next = new Node(7);
//list1
Node* head1 = new Node(4);
head1->next = new Node(5);
head1->next->next = newNode;
//list2
Node* head2 = new Node(1);
head2->next = new Node(2);
head2->next->next = new Node(3);
head2->next->next->next = newNode;
List LL;
LL.IntersectionOfLL(head1,head2);
return 0;
}