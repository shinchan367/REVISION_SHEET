#include<bits/stdc++.h>
using namespace std;
int getfirst(int first){
  while(first>=10){
    first/=10;
  }
  return first;
}
int getlast(int last){
return last%10;
}

int unsafepassword(int l,int r){
int count=0;
  for(int i=l;i<=r;i++){
    if(getfirst(i)==getlast(i)){
      count++;
    }
    return count;
}

int main(){
  int l,r;
  cin>>l>>r;
  cout<<unsafepassword(l,r)<<endl;
  return 0;
}
