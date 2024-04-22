/* Author: Marim Abbas
  Date: 10/02/2023
  Project purpose: recursive and iterative algorithm */

#include <iostream>
using namespace std;

//function prototype for recursive
int S_recur(int n);
//function prototype for iterative
int S_ite(int n);

int main() {
int num=0;
//recursive sequence
cout<<"The first 10 items for the relation T(n) using recursive algorithm: "<<endl;
  
for(int i=1;i<=10;i++)
  cout<<S_recur(i)<<endl;

  //iterative sequence
cout<<"The first 10 items for the relation T(n) using iteriative algorithm: "<<endl;
  
for(int i=1; i<=10;i++)
  cout<<S_ite(i)<<endl;
  

  return 0;
}

//function definition for recursive
int S_recur(int n)
{
  if(n==1)
    return 2;
  else
    return n*S_recur(n-1)+n;
}

//function defintion for interative
int S_ite(int n)
{
  int curValue=2;
    for(int i=2;i<=n;i++)
      {
       curValue=i*curValue+i; 
      }
    return curValue;
  
}
