#include<stdio.h>
#include<math.h>

int main(){
int a;
printf("enter principal amount\n");
scanf("%d",&a);
float b;
printf("enter a rate of intrest\n");
scanf("%f",&b);
int c;
printf("enter a time in years\n");
scanf("%d",&c);
float ms=a*b*c;
float s=ms/100;



printf("the simple imprest of %d, having rate of intrest %f and time %d is %f",a,b,c,s);
}