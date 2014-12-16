#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double x = 5.; 
int n;
extern double bessel(double x, int n); 

int main(){
  for (n = 0; n<10; n++){
    printf("%lf %lf\n", x, bessel(x,n));
  }
  return 0;
} 

double bessel(double x, int n){
  //nth term of a bessel func sequence
  if (n == 0 & x == 0) return 1;
  if (n != 0 & x == 0) return 0;
  if (n == 0) return sin(x)/x;
  if (n == 1) return sin(x)/(x*x) - cos(x)/x;
  return ((2*(n-1)+1)*bessel(n-1,x) - x*bessel(n-2,x))/x;
}
