#include<iostream>
using namespace std;
/*int main(){
    int a;
    cout<<"enter the marks"<<endl;
    cin>>a;
    if (a>=90)
    {
        cout<<"a grade"<<endl;
    }
    else if (a>=80&a<90)
    {
        cout<<"b grade"<<endl;
    }
    else if (a>=70&a<80)
    {
        cout<<"c grade"<<endl;
    }
    
}*/
/*
int main(){
    int a;
    cout<<"enter the number"<<endl;
    cin>>a;
    int sum=0;
    

//it is not mandatory to write all conditions in while loop but it is mandatory to write semicolons
    for(int i=1;i<=a;i++)
    {
        sum=sum+i;
        

    }
    cout<<sum;
}*/
/*  * * * * *
    * * * * *
    * * * * *
    */
//patterns
//steps
//observe the row total row=3
//observe coloumn har coloumn me 3* print karne hai
//two loops outter loop is for row and inner loop is for coloumn
//when first row enters in loop we took another nested loop which shows hame row 0 me kya karna hai ...row 0 me 5* print karne hai so 
//for loop coloumn ka lagayenge aur row me 5 * print karenge this is the best logic in the pateerns
int main(){
    //to print solid reactangle of *
    


    



    /*for (int row=0; row < 3; row++)
    {
        for (int col = 0; col<5; col++)
        {
            cout<<"* ";

        }
        cout<<endl;
        
    }*/

//to print hollow rectangle
/*
* * * * *
*       *
* * * * *
*/
//first row and last row me me sare stars
//middle row me first star and then speces and last me star
///most important structure according me
/*
cout<<"enter the rows"<<endl;
int a;
cin>>a;
cout<<"enter the coloumns"<<endl;
int b;
cin>>b;


for (int i=0; i<a; i++)
    {
        if(i==0||i==a-1){

        for (int j = 0; j<b;j++)
        {
           cout<<"* ";
            
           }
        }


        else
        {
            cout<<"* ";
            for (int j=0; j < b-2; j++)
            {
                cout<<"  ";
            }
            cout<<"*";

            
        }
                         cout<<endl;


        
        

        
        
    }
    
    */

    
//to print half pyramid
/*
    for (int i = 0; i<5; i++)
    {
        for (int j = 0; j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
        
    }
    */

//half pyramid
/*cout<<"enter the rows"<<endl;
int a;
cin>>a;

   for (int i = 0; i<a; i++)
    {
        for (int j = 0; j<=a-i;j++)
        {
            cout<<" ";
        }
        
        
        for (int j = 0; j<=i; j++)
        {
            cout<<"*";
            //agar mai cout<<"* " likh du toh full pyramidv print hoga
        }
        cout<<endl;
        
        
    }*/
    
//inverse full pyramid
/*
cout<<"enter the rows"<<endl;
int a;
cin>>a;

   for (int i = 0; i<a; i++)
    {
        for (int j=0; j<=i;j++)
        {
            cout<<" ";
        }
        
        
        for (int j = 0; j<a-i; j++)
        {
            cout<<"* ";
            //agar mai cout<<"* " likh du toh full pyramidv print hoga
        }
        cout<<endl;
        
        
    }*/

/*half pyaramid by numbers
cout<<"enter the rows"<<endl;
int a;
cin>>a;
int count=1;

   for (int i = 0; i<a; i++)
    {
        
        
        for (int j = 0; j<=i; j++)
        {
            cout<<" "<<count<<" ";
            count++;
        }
        cout<<endl;
        
        
    }
    
*/
//full pyramid

// cout<<"enter the rows"<<endl;
// int a;
// cin>>a;

//    for (int i = 0; i<a; i++)
//     {
//         for (int j = 0; j<=a-i;j++)
//         {
//             cout<<" ";
//         }
        
        
//         for (int j = 0; j<=i; j++)
//         {
//             cout<<"* ";
//             //agar mai cout<<"* " likh du toh full pyramidv print hoga
//         }
//         cout<<endl;
        
        
//     }
    //numeric pyramid
/*cout<<"enter the rows"<<endl;
int a;
cin>>a;
int i=0;
int count=i+1;


   for (; i<a; i++)
    {
        for (int j = 0; j<=a-i;j++)
        {
            cout<<" ";
        }
        
        
        for (int j = 0; j<=i; j++,count++)
        {
            cout<<" "<<count;
            
            
            //agar mai cout<<"* " likh du toh full pyramid print hoga
        }
        cout<<endl;
        
        
    }*/

//numeric half pyramid
/*cout<<"enter the rows"<<endl;
int a;
cin>>a;
int i=0;



   for (; i<a; i++)
    {
       
        
        for (int j = 0; j<=i; j++)
        {
            cout<<j+1;
            
            
            //agar mai cout<<"* " likh du toh full pyramid print hoga
        }
        cout<<endl;
        
        
    }
*/
//inverted half pyramid

/*cout<<"enter the rows"<<endl;
int a;
cin>>a;
int i=0;



   for (; i<a; i++)
    {
        
        
        for (int j = 0; j<a-i; j++)
        {
            cout<<j+1;
            
            
            //coloumn ka number+1 print kRWANA HAI YEH HAME ROWS OBSERVE KARNE KE BAAD PATA CHALTA HAI
        }
        cout<<endl;
        
        
    }*/


/*
int n;
if(cin>>n){

    cout<<"ye print ho skta hai"
}*/

/*
if(cout<<"love babaar"){

    cout<<"ye print ho skta hai";
}*/



//solid diamond
/*cout<<"enter the rows"<<endl;
int a;
cin>>a;


   for (int i=0; i<a; i++)
    {
        for (int j = 0; j<=a-i;j++)
        {
            cout<<" ";
        }
        
    
        for (int j= 0; j <=i; j++)
            {
                cout<<"* ";
            }
        
        

        
            cout<<endl;
        



        
        
    }
     for (int i=0; i<a; i++)
    {
        for (int j = 0; j<=i+1;j++)
        {
            cout<<" ";
        }
        
    
        for (int j= 0; j <a-i; j++)
            {
                cout<<"* ";
            }
        
        

        
            cout<<endl;
        



        
        
    }*/

//hollow diamond

/*cout<<"enter the rows"<<endl;
int a;
cin>>a;


   for (int i=0; i<a; i++)
    {
        for (int j = 0; j<=a-i-1;j++)
        {
            cout<<" ";
        }
        
        if(i==0){
        for (int j= 0; j <=i; j++)
            {
                cout<<" *";
            }
        }
        else
        {
            cout<<"* ";
            for (int j=0; j <i; j++)
            {
                cout<<"  ";
            }
            cout<<"*";

            
        }

        
            cout<<endl;   
    }
     
for (int i=0; i<a; i++)
    {
        for (int j = 0; j<=i;j++)
        {
            cout<<" ";
        }
        
        if(i==4){
        for (int j= 0; j <a-i; j++)
            {
                cout<<" *";
            }
        }
        else
        {
            cout<<"* ";
            for (int j=0; j < a-i-1; j++)
            {
                cout<<"  ";
            }
            cout<<"*";

            
        }

        
            cout<<endl;
               
        
    }*/
/* hollow diamond
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row < a; row++)
{
    //spaces
    for (int col = 0; col<a-row-1;col++)
        {
            cout<<" ";
        }
    //stars
    //every row contains 2*row+1 elemennts
    //we can control the coloumns also.....
    for(int col=0;col<=2*row+1;col++){
        if(col==0)
        {
            cout<<"*";
        }
        else if(col==2*row)
        {
            cout<<"*";
        }
    
       else{
        cout<<" ";

       }
        


    }

cout<<endl;
}

for (int row = 0; row < a; row++)
{
    //spaces
    for (int col = 0; col<row;col++)
        {
            cout<<" ";
        }
    //stars
    //every row contains 2*row+1 elemennts
    int x=a-row-1;
    for(int col=0;col<2*x+1;col++){
        if(col==0)
        {
            cout<<"*";
        }
        else if(col==2*x)
        {
            cout<<"*";
        }
    
       else{
        cout<<" ";

       }
        

    }

cout<<endl;



}*/


/*//numeric hollow diamond MIP
1
1 3
1   5
1     7
1 2 3 4 5

cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row <a; row++)
{
    

    
    if(row!=a-1){
    //jitne character hae ek row me daalne hai utne tum for loop ki conditions me daaldo mtlb uska formula
        for (int col = 0; col <=2*row+1 ; col++)
        {
        if (col==0)
        {
        cout<<"1";
        }
       else if (col==2*row)
       {
        cout<<row+1;
       }
       else {
        cout<<" ";

       }
       
       
    }
    
    
    } 



    else if(row==a-1){
        for (int col = 0,count=1; col <=row; col++,count++)
        {
            cout<<count<<" ";
        }
        

    }
    cout<<endl;
}
*/
/*
//FLIPPED SOLID DIAMOND
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row < a; row++)
{
    for (int col= 0; col < a-row; col++)
    {
        cout<<"*";
    }
    
    for(int col=0;col<=2*row-1;col++){
        cout<<" ";
    }
    for (int col= 0; col < a-row; col++)
    {
        cout<<"*";
    }
    cout<<endl;
    

}


for (int row = 0; row < a; row++)
{
    int x=a-row-1;
    for (int col= 0; col <=row; col++)
    {
        cout<<"*";
    }
    
    for(int col=0;col<=2*x-1;col++){
        cout<<" ";
    }
    for (int col= 0; col <=row; col++)
    {
        cout<<"*";
    }
    cout<<endl;
    

}*/

/*//fancy pattern MIP
1
2*2
3*3*3
4*4*4*4
5*5*5*5*5
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row < a; row++)
{
    for (int col= 0; col <row+1; col++)
    {
        cout<<row+1;
        if(col!=row){
            cout<<"*";
        }
        
    }
    cout<<endl;


}
*/
/*
1
121
12321
1234321
123454321
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row < a; row++)
{
    for (int col= 0 ,count=1; col <row+1; col++,count++)
    {
        
        cout<<count;
        
        
    }
    for (int col= 0,count=row+1; col <row; col++,--count)
    {
        
        cout<<count-1;
        
        
    }
    cout<<endl;


}*/
/*
A
ABA
ABCBA
ABCDCBA
ABCDEDCBA
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row = 0; row < a; row++)
{
    for (int col= 0 ,count=1; col <row+1; col++,count=count+1)
    {
        int alph=count;
        char ans=alph+'A'-1;//-1isi liye add kiya kyuki hame A se start karna hai agar -1 nhi add karte toh B se start hota row
        cout<<ans;
        //agar alphabet ko integer ke tarah use karna hai toh pehle ek integer define karo phir us integer me alphabet A add karo aur dusra koi bhi add kar skte ho agar tumne jo alphabet dala hai usise start karna hai toh -1 karo...
        
    }
    for (int col= 0,count=row+1; col <row; col++,--count)
    {
        int alpha=count-1;
        char ch=alpha+'A'-1;
        cout<<ch;
        
        
    }
    cout<<endl;


}
*/

//want to print the full pyramid like
/*          1
         2  3  2
      3  4  5  4  3
   4  5  6  7  6  5  4
5  6  7  8  9  8  7  6  5 

cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    for (int col = 0; col < a-row-1; col++)
    {
        cout<<" ";
    }
    for (int col = 0,count=row+1; col <= row; col++,count++)
    {
        cout<<" "<<count;
    }

    for (int col = 0,count=2*row; col < row; col++,--count)
    {
        cout<<" "<<count;
    }

    cout<<endl;
    
    
}


*/



//HOMEWORK
/*
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    for (int col = 0; col < a; col++)
    {
        cout<<"* ";
    }
    
    cout<<endl;
    
    
}
*/
/*
* * * * *
*       *
*       *
*       *
* * * * *

cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    if(row==0||row==a-1){
    for (int col = 0; col < a; col++)
    {
        cout<<"* ";
    }
    }
    else{
        cout<<"* ";
        for(int col=0;col<a-2;col++){
            cout<<"  ";
        }
        cout<<"*";
       




    }
    cout<<endl;
    
    
}*/

/*
* * * * * *
*       *
*     *
*   *
* *
*

cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    if(row==0){
    for (int col = 0; col < a; col++)
    {
        cout<<"* ";
    }
    }
    else if (row==a-1)
    {
        cout<<"*";
    }
    
    else{
        cout<<"* ";
        
        for(int col=0;col<a-row-2;col++){
            cout<<"  ";
        }
        cout<<"*";
       




    }
    cout<<endl;


}
*/
/*
********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    
    for (int col = 0; col < a-row+3; col++)
    {
        cout<<"*";
    }
    for (int col = 0; col < row+1; col++)
    {
        
        if (col==row)
        {
            cout<<row+1;
        }
        else{
            cout<<row+1<<"*";
        }
        
    }
    for (int col = 0; col < a-row+3; col++)
    {
        cout<<"*";
    }

    
    
    
    cout<<endl;


}

*/
/*
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    
  for(int col=0;col<row+2;col++){
       if(col==0||col==row+1) {
        cout<<"*";
        }
        
       else{
        for (int col = 0,count=1; col< row; col++,count++)
        {
            cout<<count;
        }
         
        // for (int col = 0,count=col-2; col< row-1; col++,--count)
        // {
        //     cout<<col;
        // }
       }
         
    
    
    

  }
    
    
    cout<<endl;


} 
*/
/*
*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *
cout<<"enter the rows"<<endl;
int a;
cin>>a;
for (int row= 0; row<a; row++)
{
    
    for (int col = 0; col <=row; col++)
    {
        cout<<"*";
    }
    for (int col = 0; col<2*a-2*row-2; col++)
    {
        cout<<" ";   
    }
    for (int col = 0; col <=row; col++)
    {
        cout<<"*";
    }

    
    
    
    cout<<endl;


     
   

}
for (int row= 0; row<a; row++)
{
    
    for (int col = 0; col <a-row; col++)
    {
        cout<<"*";
    }
    for (int col = 0; col<2*row; col++)
    {
        cout<<" ";   
    }
    for (int col = 0; col <a-row; col++)
    {
        cout<<"*";
    }

    
    
    
    cout<<endl;


     
   

}

*/
string s="aabaab!bb";
cout<<s.substr(3,1);


}





















    
















