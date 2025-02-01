#include<iostream>
using namespace std;
//function use karte hai jab hame koi code block baar baar use karna hoga
void printname(){
   cout<<"enter the first number"<<endl;
   int n;
   cin>>n;

    for (int i = 0; i < n; i++)
    {
        cout<<"i am sarafaraj"<<endl;
    }
    
}

void printnum(int num){
    cout<<++num<<endl;
    //ye jo num hai woh main function ke a ki copy hai
}


int add(){
    cout<<"enter the first number"<<endl;
   int a;
   cin>>a;
   cout<<"enter the second number"<<endl;
   int b;
   cin>>b;

  // cout<<"the sum is "<<a+b<<endl;   print bhi kar skte hai but acche programme majority me return karna hota hai matlab woh jo
  //main function hai woh khud print karwa dega
int x=a+b;
return x;
}

int sum(int num1,int num2){

    int x=num1+num2;
    return x;



}

int max(int a,int b,int c){

    if(a>b){
        if(a>c){
           // cout<<"a is max";
           return a;
        }
        else{
            // cout<<"c is max";
            return c;
        }
    }
    else if(b>a){
        if(b>c){
           // cout<<"b is max";
            return b;
        }
        else{
           //  cout<<"c is max";
            return c;
           
        }
    }




}


char grades(int marks){

    

    switch(marks/10){

        case 9:return 'A';break;
        case 8:return 'B';break;
        case 7:return 'C';break;
        case 6:return 'D';break;
        default:return 'E';break;






    }




}


int sumofn(int a){

    int sum=0;

    for (int i = 1; i <=a; i++)
    {
        sum=sum+i;
    }
    return sum;




}

//jab kuch return nhi karna hota toh void use karenge jaise kuch print karna hai toh


int main(){

/*printname();//it will print name on n times
printnum(a);//iski copy void printname ke num me copy hogi...pass by value matlb
//BHAI A KI COPY PRINTNUM KE FUNCTION ME CREATE HOGI
 //shows that main funcion successfully executed

cout<<"adress of a is"<<&a<<endl;*/


//add();

  /* cout<<"enter the first number"<<endl;
   int a;
   cin>>a;
   cout<<"enter the second number"<<endl;
   int b;
   cin>>b;
   cout<<"enter the third number"<<endl;
   int c;
   cin>>c;
//sum(a,b);

int x=max(a,b,c);

cout<<x<<endl;*/
/*cout<<"enter the your marks"<<endl;
    int a;
   cin>>a;
char x=grades(a);
cout<<"your grade is"<<x<<endl;
*/
cout<<"enter the first number"<<endl;
   int a;
   cin>>a;

int x=sumofn(a);
cout<<"the sum is: "<<x;



return 0;

}