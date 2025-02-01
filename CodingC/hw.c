
/*#include<stdio.h>
//#include<conio.h>

int main()
{
    int n;
    printf("the size of array :") ;
    scanf("%d", &n) ;

    int arr[n];
    for(int i=0;i<n;i++) {
    printf("the elements of arrays are:") ;
    scanf("%d",&arr[i]) ;
    }

    int item;
     printf("enter element at the beginning:") ;
     scanf("%d", &item) ;
     n++;
     for(int i=n;i>1;i--) {
     arr[i-1]=arr[i-2];
     }
     arr[0]=item;
     printf("the elemnts are\n");
     for(int i=0;i<n;i++) {
     printf("%d", arr[i]) ;
     }
     
    return 0;
}*/
/*
#include<stdio.h>
#include<conio.h>
#include<math.h>


int main()
{
    int n;
    printf("the size of array :") ;
    scanf("%d", &n) ;

     int arr[n];
    for(int i=0;i<n;i++) {
    printf("the elements of arrays are:") ;
    scanf("%d",&arr[i]) ;
    }

int x=0;
int y=pow(2,16);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<y){
            y=arr[i];
        }
         if(arr[i]>x){
            x=arr[i];
        }
    }
printf("min is %d max is %d",y,x);
int j;
int num;
for (j = 0; j < n; j++)
{
    if(arr[j]==y){
       arr[j]=x;\
       num=j;
    }
}

for (int i = 0; i < n; i++)
{
    if(i==num){
        arr[i]=x;
    }
    else if(arr[i]==x){
        arr[i]=y;
    }
}



 printf("the elemnts are\n");
for (int i = 0; i < n; i++)
{
    printf("%d,", arr[i]) ;
}

    
     
    return 0;
}
#include<stdio.h>
#include<conio.h>
void main(){
int num1, num2 ;
void swap(int *,int *) ; // function declaration
num1 = 10 ;
num2 = 20 ;
printf("\nBefore swap: num1 = %d, num2 = %d", num1, num2) ;
swap(&num1, &num2) ; // calling function
printf("\nAfter swap: num1 = %d, num2 = %d", num1, num2);
getch() ;
}
void swap(int *a, int *b) // called function
{
int temp ;
temp = *a ;
*a = *b ;
*b = temp ;
}*/

#include<stdio.h>
#include<conio.h>
int i=4;
void f(){
    i++;
}
void x(){
    static int i=4;
    if (i)
    {
        printf("%d ",i);
        i--;
        x();
    }
    
}
int main()
{
    // int i=5;
    // i++;
    // f();
    // f();
    // printf("%d",i);
    // char n='A';
    // switch (n)
    // {
    // case 'A':
    //     printf("hi");
    //     break;
    // case 65:
    //     printf("hello");
    // default:
    //     printf("my");
    // // }
    //  int i=4.9;
    // switch (i)//i=0;if i-- then i-- wil be 1
    // {
    // case 0:
    // case 5:
    //     printf("hi");
    //     break;
    // case 4://case expression can't be a variable except const variables
    //     printf("hello");
    // default:
    //     printf("my");
    // }

    // int x=printf("hello brother");
    // printf("%d",x);
    // switch (printf("hellobhai"))//i=0;if i-- then i-- wil be 1
    // {
    // case 0:
    // case 1:
    //     printf("hi");
    //     break;
    // case 2://case expression can't be a variable except const variables
    //     printf("hello");
    // default:
    //     printf("my");
    // }

    // int k=30;
    // printf("%d %d %d",k<=30,k=40,k==30);//start from right to left  
    //                   //      0,k=40,1
    // int i;
    // for (i = 0; i <6; i++);
    // {
    //     printf("%d",i);
    // }

    // int i=0;
    // label:
    //      {
    //         if (i<10)
    //         {
    //             i++;
    //             printf("%d\n",i);
    //             goto label;
    //         }
            
    //      }


    // float a=1.475;
    // double b=1.475;
    // if(a==b){
    //     printf("equal");
    // }else
    // {
    //     printf("not equal");
    // }
    
    // int i;
    // printf("%d\n",scanf("%d",&i));
    // int l;
    // int x=scanf("%d",&l);
    // printf("%d",x);

    // int n=2;
    // int k=3;
    // switch (n)
    // {
    // int k=5;
    //     case 1:
    //         printf("%d\n",++k);
        
    //     case 2:
    //         printf("%d\n",++k);
        
    //     default:
    //         printf("%d\n",(k+++1));
    // }

    // int a;
    // if(a!=0){
    //     // int a=10;
    //     // printf("%d\n",a);
    //     a=7;
    // }
    // printf("%d",a);
//     int x,y,z,a;
//     y=2;
//    // if (x=y%2)//if we don't take paranthesis first statement only take as statement of if
//     if (x=y%2)if(x==0)z=2;a=2;
//     printf("%d %d %d %d",x,y,z,a);

    // int a,b;
    // a=(3+2,b=a,12);
    // printf("%d %d",a,b);

    // int a=5;
    // a=++a + ++a;
    // printf("%d",a);

    // char x=120;
    // while (++x>10)
    // {
    //     printf("%d ",x);
    // }

    // int a=35,b=15,c=25,d,e;
    // d=a>c>b;//left to right
    // e=c-b >a <=d;//left to right
    // printf("%d %d",d,e);

    // if (!!7)
    //     printf("true");
    // else
    // printf("false");
    // printf("hi");
    
    // int x;
    // x=4%5==4%2+3;
    // printf("%d",x);
    
    // char sport[]="cricket";
    // int x=1,y;
    // y=x++ + ++x;
    // printf("%c",sport[++y]);

    // char *str="geeks";
    // printf("%c",*((str--+2)+1)-3);

    // int i=100;
    // int *ip1,*ip2;
    //  ip1=&i;
    //  ip2=++ip1;
    //  --ip1;
    //  --ip1;
    //  printf("%d",ip2-ip1);
    // x();
    // int i;
    // i=10+010+0x20;
    // printf("%d",i);
}

#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    return 0;
}


//queue

#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}


