#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
int i,n=10;
double y[n];
  time_t t;
  srand(7);
  for(i=1;i<=n;i++){
    y[i-1]=rand()/(double)RAND_MAX;
    printf("%f \n",y[i-1]);
  }
  return 0;
}
