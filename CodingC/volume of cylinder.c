#include<stdio.h>
#include<math.h>

int main(){
int a;
printf("enter radius\n");
scanf("%d",&a);
float b;
printf("enter hight of cylinder\n");
scanf("%f",&b);
/*int c;
printf("enter a time in years\n");
scanf("%d",&c);*/
int c=pow(a,2);
float ms=3.14*c*b;




printf("the volume of cylinder is %f",ms);
}