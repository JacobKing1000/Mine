#include<stdio.h>
int main(){
  float a,b,r;
  printf("Enter the value of r: ");
  scanf("%f",&r);
  a=3.14*r*r;
  b=2*3.14*r;
  printf("\nArea of circle is:%f",a);
  printf("\nCirumfarence of circle is:%f",b);
  return 0;
}