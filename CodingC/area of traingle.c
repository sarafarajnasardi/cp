#include<stdio.h>
#include<math.h>

int main(){
int a;
printf("enter a 1st side\n");
scanf("%d",&a);
int b;
printf("enter a 2nd side\n");
scanf("%d",&b);
int c;
printf("enter a 3rd side\n");
scanf("%d",&c);
int ms=a+b+c;
int s=ms/2;
int k=s*(s-a)*(s-b)*(s-c);
float n=pow(k,0.5);


printf("the area  of triangle having 1st side %d, 2nd side %d and 3rd side %d is %f",a,b,c,n);
}