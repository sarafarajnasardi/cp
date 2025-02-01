#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
// string s;
//     cin>>s;
//       for(i=0;i<=strlen(s);i++) { 
//       /* Here we are performing a check so that only those 
//        * characters gets converted into lowercase that are 
//        * in uppercase. 
//        * ASCII value of A to Z(uppercase chars) ranges from 65 to 92 
//        */ 
//       if(s[i]>=65 && s[i]<=92)
//       {
// 	  s[i]=s[i]+32;
//       }
//    }
    
using namespace std;
int returnVal(char x)
{
    return (int)x - 87;
}
int time1(int arr[],int size,int target){
    int strt=0;
    int end=size-1;
    int mid=(strt+end)/2;
    while (strt<=end)
    {
           int mid=strt+(end-strt)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else {
            strt=mid+1;
        }
       
       
    }
    return -1;}
int time2(int brr[],int size,int target){
    for (int i = 0; i < size; i++)
    {
       if(brr[i]==target){
        return i;
       }
    }
    
    return -1;
}
void mm(int x){
    vector<char>s;
    while(s.size()<4)
    {
       if (x>=3&&x<=28&&s.size()==0)
      {
       int h=x-2;;
       for (int i = 0; i <2 ; i++)
       {
        s.push_back(static_cast<char>(65));
       }
       
      s.push_back(static_cast<char>(64+h));
      break;
     
      }else if (x>=3&&x<=28&&s.size()==1)
      {
        if(x==28){
          s.push_back(static_cast<char>(66));
          s.push_back(static_cast<char>(64+26));
         break;

        }else{
           int h=x-1;;
         for (int i = 0; i <1 ; i++)
          {
           s.push_back(static_cast<char>(65));
         }
       
         s.push_back(static_cast<char>(64+h));
         break;
        }
      }
      else if (x>28&&s.size()==1)
      {
        
           int h=x-26;;
         
           s.push_back(static_cast<char>(64+h));
        
       
         s.push_back(static_cast<char>(64+26));
         break;
        
      }
      else if (x>=1&&x<=26&&s.size()==2){
        s.push_back(x);
      }
       if (x>28&&s.size()==0)
      {
        x=x-26;
         s.push_back(static_cast<char>(64+26));
      }
      
      
       
    }
   string str(s.begin(), s.end());
   sort (str.begin(), str.end());
    transform(str.begin(), str.end(), str.begin(), ::tolower); 
   cout<<str<<endl;

}

int main(){
    /*
    char name[100];
    char ch[50];
    cout<<"enter yor name"<<endl;
    //cin>>name;//we can take whole string as input
    cin.getline(name,50);    //it can read spaces tabs and enters,50 is max length
    cout<<"your name is: "<<name<<endl;//agar name sarafaraj nasardi ho toh only sarafaraj print hoga kyunki cin spaces ko read 
    //kar pata toh hume alag chiz sikhni padhegi
 
   cin>>ch[3];
   cin>>ch[50];
    cout<<ch[3];
    for ( int i = 0; i < 18; i++)
    {
        cout<<"at index "<<i<<"alphabet is "<<name[i];
        cout<<endl;
    }*/
    //length of string
    // char name[50];
    // cout<<"enter yor name"<<endl;
    // cin.getline(name,50);
    // int max;
    // for (int i = 0; i < 50; i++)
    // {
    //     if (int(name[i])==0)
    //     {
    //        max=i;
    //        break;
    //     }
        
    // }
    // cout<<"length of string is "<<max<<endl;
    //reverse a string
    // for (int i = max-1; i>=0; i--)
    // {
    //    cout<<name[i];
    // }
    // int i=0;
    // while (i<50)
    // {
    //     if (name[i]==' ')
    //     {
    //         name[i]='@';
    //     }
    //     i++;
        
    // }
    // cout<<name;
    //pollindrome:the string which is same from both sides ex:'noon'
    // char name[50];
    // cout<<"enter yor name"<<endl;
    // cin.getline(name,50);
    // int max;
    // for (int i = 0; i < 50; i++)
    // {
    //     if (int(name[i])==0)
    //     {
    //        max=i;
    //        break;
    //     }
        
    // }
    // cout<<"length of string is "<<max<<endl;
    // int i=0;
    // int j=max-1;
    // int ans=0;
    // while (i<=j)
    // {
    //     if(name[i]!=name[j]){
    //         ans++;
    //     }
    //     i++;
    //     j--;
    // }
    // if (ans==0)
    // {
    //    cout<<"it's  a pollindrome";
    // }
    // else{
    //     cout<<"it's not a pollindrome";
    // }
    
//lowercase to uppercase

// char name[50];
//     cout<<"enter yor name"<<endl;
//     cin.getline(name,50);
//     int max;
//     for (int i = 0; i < 50; i++)
//     {
//         if (int(name[i])==0)
//         {
//            max=i;
//            break;
//         }
        
//     }
    
//     for (int  i = 0; i < max; i++)
//     {
//         name[i]=name[i]-'a'+'A';
//     }
//     cout<<name;

///STRINGS IT IS A DATATYPE NOT A DATSTRUCTURES

//string create
// string str;
// // cin>>str;
// getline(cin,str);
// cout<<str<<endl;
// cout<<str.length()<<endl ;
// cout<<str.empty()<<endl;
// str.push_back('S');
// cout<<str<<endl;
// str.pop_back();//erase last character of string
// cout<<str<<endl;
 //cout<<str.substr(0, 2)<<"rafaraj"<<endl;
 string a="Sarafaraj";
 string b="l";
 cout<<a.substr(0, 8)<<endl;
// if (a.compare(b)==0)
// {
//     cout<<"a and b are exactly same strings"<<endl;
// }
// else{
//     cout<<"Saba Nasardi"<<endl;
// }
//  cout<<a.find(b)<<endl;;
//  if(a.find(b)==std::string::npos){
//      cout<<"NOT FOUND"<<endl;
//  }
//  else{
//     cout<<"it's found"<<endl; 
// }  
// a.replace(0,7,b);
//  cout<<a<<endl;
a.erase(0,3);
 cout<<a<<endl;
// int arr[5]={1,2,3,4,5};
// int k=1;
// int sum1[5];
// for (int  i = 0; i < 5; i++)
// {
//     int temp=arr[i];
//    if(i<k){
//     sum[i]=arr[5+i-k];
//    }
//    else{
//     sum[i]=arr[i-k];
    
//    }
   
// }
// for (int i = 0; i < k; i++)
// {
//    arr[i]=sum[i];
// }



// for (int i = 0; i < 5; i++)
// {
//     cout<<arr[i];
// }

// int x = s.length();

//         if (x % 2 == 0  && s[1]!=s[x-1] && s[x-2] != s[0]) {
//             int i = 0;
//             int m = (x / 2) - 1;
//             while (i < m) {
//                 if (s[i] != s[x - i - 1]) {
//                     return false;
//                     break;
//                 } else {
//                     i++;
//                 }
//             }
//         } else if(x%2!=0 && s[1]!=s[x-1] && s[x-2] != s[0]){
//             int i = 0;
//             int m = (x / 2) ;
//             while (i < m) {
                
//                 if (s[i] != s[x - i - 1]) {
//                     return false;
//                     break;
//                 } else {
//                     i++;
//                 }
//             }
//         }
//         else if (s[1] == s[x - 1]) {
//                     int i = 1;
//                     int n=x-1;
//                     int m = (n / 2) ;
//                     while (i < m+1) {
//                         if (s[i] != s[x - i]) {
//                             return false;
//                             break;
//                         } else {
//                             i++;
//                         }
//                     }
//                 }
//         else if (s[x-2] == s[0]) {
//                     int i = 0;
//                     int n=x-1;
//                     int m = (n / 2) ;
//                     while (i < m) {
//                         if (s[i] != s[x - i-2]) {
//                             return false;
//                             break;
//                         } else {
//                             i++;
//                         }
//                     }
//                 }




// int sum;
// int a,b;
// cin>>a>>b;
// sum=a+b;
// cout<<sum;

//  vector<int>v{9,9,9};
// int k=v.size();
// int count=0;
//    for(int j=1;j<k;j++){
//         if(v[j]==v[0]){
//             count++;
//         }
//     }

//     if(count>=1){
//         for (int i = 0; i < k; i++)
//         {
//            if(v[i]!=v[0]){
//             cout<<i+1;
//            }   
//         }
        
//     }
//     else if (count==0)
//     {
//         cout<<1;
//     }
    // int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    // int brr[]={0,23,22,21,20,19,18,17,16,15,14,13};
    // vector<string> time{"00:00","23:59","00:00"};
    // vector<int> diff;
    //     int x = time.size();
    //     for (int i = 0; i < x; i++) {
    //         string s = time[i];
    //         int hours = stoi(s.substr(0, 2));
    //         int min = stoi(s.substr(3, 4));
    //         int l;


    //         for (int j = i + 1; j < x; j++) {
    //             string v = time[j];
    //             int hours2 = stoi(v.substr(0, 2));
    //             int min2 = stoi(v.substr(3, 4));
    //             int a=time1(arr,12,hours);
    //             int b=time2(brr,12,hours2);
    //             int c=time1(arr,12,hours2);
    //             int d=time1(brr,12,hours);

    //             if(a!=-1 && b!=-1){
    //                 l=(abs(a-b)*60)+(60-min2)+min;
    //             }
    //             else if(c!=-1 && d!=-1){
    //                 l=(abs(c-d)*60)+(60-min)+min2;
    //             }
    //             else{
    //             if (hours2 >= hours) {
    //                 if(hours2==hours){
    //                     l=abs(min2-min);
    //                 }
                    
    //               else if (hours2==brr[0])
    //               {
    //                  l = (abs(24- hours2)) * 60 + (min - min2);
    //               }
    //               else{
    //                     l = (abs(hours2 - hours)) * 60 + (min2 - min);
    //               }
                   
    //             } else {
    //                  if (hours2==brr[0])
    //               {
    //                   l = (24 - hours) * 60 + (min2 - min);
    //               }
    //               else{
    //                     l = (hours - hours2) * 60 + (min - min2);
    //               }
                        
    //             }
    //             }
    //             diff.push_back(abs(l));
    //         }
    //     }
    //     int min=diff[0];
    //     for (int i = 0; i < diff.size(); i++) {
            
    //         if (diff[i] < min) {
    //             min = diff[i];
    //         }
    //     }
    //     cout<< min;
// vector<int>arr{1,1,2,2,3,4,4,5,5,6,6};
// vector<int>brr;
// int size=11;
// int ans;
// int count;
// for (int i = 0; i < 11; i++)
// {
//     for (int  j = i+1; j < 11; j++)
//     {
//       if (arr[j]==arr[i])
//       {
//         brr.push_back(arr[i]);
//       }
      
//     }
    
    
// }
// cout<<"hello"<<endl;
// int i=0;
// while(i < arr.size())
// {
//     for (int j = 0; j < brr.size();j++ )
//     {
//        if (arr[i]==brr[j])
//        {
//         i++;
//        }
//        else if (j==(brr.size()-1)&&arr[i]!= brr[j])
//        {
//         ans=i;
//        }
//     }
    
// }
// cout<<arr[ans];
// vector<int>nums1{1,3};
// vector<int>nums2{2,4};
//  vector<int>sum;
        
//         int a=nums1.size();
//         int b=nums2.size();
        
//         for (int i = 0; i <a ; i++)
//         {
//            sum.push_back(nums1[i]);
//         }
//         for (int i = 0; i < b ; i++)
//         {
//             sum.push_back(nums2[i]);
//         }
//          sort(sum.begin(), sum.end());
//         for (int i = 0; i < (a+b); i++)
//         {
//             cout<<sum[i]<<endl;
//         }
        
        
       
//         int x=sum.size();
//        double mid;
//         if(x%2==0){
//             int m=(x/2)-1;
//             double x=sum[m];
//             double y=sum[m+1];
//              mid=(x+y)/2;
            

//         }else{
//             int m=x/2;
//              mid=(sum[m]);
//         }
//         cout<<mid;
}
        

bool pal(string k,string a,string b){
        int l=k.length();
        
        for(int i=0;i<l;i++){
            
            if(k[i]!=k[l-i-1]){
                return false;
            }
            
        }
        return true;


    }
 bool dil(string m){
        int x=m.length();
        for(int i=0;i<x;i++){
            for(int j=i+1;j<x;j++){
                if(m[i]==m[j]){
                    return true;
                }
            }
        }
        return false;
        
    }
    int size(string x){
        int l=x.length();
        return l;
    }
    bool vowel(char m){
        char x[]={'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < 10; i++)
        {
           if(m==x[i]){
                return true;
           }
        }
        return false;
        
    }
  //  int main() {
    //     string s="sarafaraj";
    //     string a,b;
    //     vector<string>m;
    //     int x=s.length();
    //     for(int i=0;i<x;i++){
            
    //         for(int j=1;j<=(x-i);j++){
    //            m.push_back(s.substr(i,j));
    //         }
           
            
    //     }
    //     int h=m.size();
    //     for(int j=0;j<h;j++){
    //           cout<<m[j]<<endl;
    //         }

    //     int count=0;
     
    //   for(int i=0;i<h;i++){
    //       if(pal(m[i],a,b)){
    //           count++;
    //       }
    //   }
    //   cout<< count;
    // string s="aabaab!bb";
    //    int x=s.length();
    //     vector<string>ans;
    //     for(int i=0;i<x;i++){
    //         for(int j=1;j<=(x-i);j++){
    //             ans.push_back(s.substr(i,j));
    //         }
    //     }
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         cout<<ans[i]<<endl;
    //     }
    //    int m=ans.size();
    //    int k=0;
    //     while(k<m){
    //       if(dil(ans[k])){
    //          ans.erase(remove(ans.begin(),ans.end(),ans[k]),ans.end());
    //          m--;
    //       }else{
    //           k++;
    //       }
    //     }
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         cout<<ans[i]<<endl;
    //     }
        
    //     int count=0;
    //     for(int i=0;i<ans.size();i++){
    //         int h=ans[i].length();
    //         if(h>count){
    //             count=h;
    //         }
    //     }
    //     return count;

// string s="saraf&dkam";
// map<char,int>x;
// for (int i = 1; i < 27; i++)
// {
//     char m='a';
//     x[m]=i;
//     m++;

// string s = "abcd_f";
//      int i = 0;
//         int j = s.length() - 1;
//         while (i <= j) {
//             int m = returnVal(s[i]);
//             int n = returnVal(s[j]);
//             if (m >= 10 && n >= 10) {
//               swap(s[i],s[j]);
//                 i++;
//                 j--;
//             } else if (m >= 10 && n < 10) {
//                 j--;
//             } else if (m < 10 && n >= 10) {
//                 i++;
//             }
//         }
//         cout<<s;
// }
// cout<<x[5];

//  string s="senta";
//  int x=s.length();
//  int i=0;
//  int j=x-1;
//  while (i<=j)
//  {
    
   
//     if (vowel(s[i])&&vowel(s[j]))
//     {
//        swap(s[i],s[j]);
//        i++;
//        j--;
//     }else if (vowel(s[j]))
//     {
//        i++;
//     }else{
//         j--;
//     }
    
    
//  }
//  cout<<s;
// string s="aaab";
//  int x = s.length();
//         int i = 0;
//         while (i < x) {
//             if (i > 0 && s[i] == s[i - 1]) {
//                 for (int j = i + 1; j < x; j++) {
//                     if (s[i] != s[j]) {
//                         swap(s[i], s[j]);
//                         i++;
//                         break;
//                     }
//                 }
//             } else {
//                 i++;
//             }
//         }
//         for (int i = 0; i < x; i++) {
//             if(s[i]==s[i+1]){
//                 string o="x";
//                 cout<< o;
//             }
//         }
//         cout<< s;

//cout<<s;
// int a;
// cin>>a;
// int i=0;
// int mint=0;
// while (i<a)
// {
//    int x;
//    cin>>x;
//    mm(x);
//    i++;
   
   

// }
//   int myInt = 67;  // ASCII value of 'A'
//     char myChar = static_cast<char>(myInt);

//     cout << "Method 1 Output: " << myChar << std::endl;

//     return 0;
 //   }
