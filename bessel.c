#include<stdio.h>
#include<stdlib.h>

double x = 5.; 
int n;
//#define x 5.345

double bessel(double x, int n); 

int main(){
  //  int n = 0;
  //  printf("%lf\t%d\n",x,n);
  for (n = 0; n<10; n++){
    printf("%lf %lf", x, bessel(x,n));
  }
  return 0;
} 

double bessel(double x, int n){
  //nth term of a bessel func sequence
  //if (0==n) return 0;
  //if (1==n) return 1;
  return ((2*(n-1)+1)*bessel(n-1) - x*bessel(n-2))/x;
}
