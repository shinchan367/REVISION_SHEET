#include<bits/stdc++.h>
using namespace std;
class stack{
int size;
int *arr;
int top;
public:
  stack(){
    size=1000;
    arr=new int[size];
    top=-1;
  }
void push(int x){
  top++;
  arr[top]=x;
}
int pop(){
  int x=arr[top];
  top--;
  return x;
}
int Top(){
  return arr[top];
}
int size(){
  return top+1;
}
  
