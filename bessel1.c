#include<stdio.h>
#include<stdlib.h>

double x;
double y;
int a; 

int(fact(int n)){
  if (n==1){return 1;}
  else {
    return n*fact(n-1);
  }
}

/*double (bess(int m)){
  y_0 = ((x/2)^(2*m+a))*(-1)/(fact(m)*fact(m+a));
  if(m=0){return y_0;}
  else {
    return bess(m)+bess(m-1);
  }
*/

int main(){
  int f = fact(5);
      printf("5 factorial is %d\n", f);
      return 0;
  }
