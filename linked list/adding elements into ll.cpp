#include<bits/sdc++.h>
using namespace std;
struct *node(){
int data;
node*next;
  node(int value){
    data=value;
    next=NULL:
  }
};
void addnode(node*&head,int value){
if(head==NULL){
head=new node(value);
}
else{
node*temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=new node;
}
}
void display(node*head){
node*temp=head;
while(temp->next!=NULL){
cout<<temp->val;
temp=temp->next
  }
cout<<"NULL";
}

int main(){
node*head=NULL;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int value;
    cin>>value;
    addnode(head,value);
    cout<<"linkedlist";
    display(head);
  return 0;
}
