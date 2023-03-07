#include <iostream>
#include <string.h>
using namespace std;
int idk(int a,int b){
    int total=0;
    int ten=1;
    int carry=0;
    while(a>0 && b>0){
        int rem1=a%10;
        int rem2=b%10;
        a=a/10;
        b=b/10;
        if((rem1==0 && rem2==0)){
            total=total+carry*ten;
            carry=0;
        }else if((rem1==1 && rem2==1)){
            total=total+carry*ten;
            carry=1;
        }else if(((rem1==1 && rem2==0) || (rem1==0 && rem2==1)) && carry==0){
            total=total+1*ten;
        }else if(((rem1==1 && rem2==0) || (rem1==0 && rem2==1)) && carry==1){
            carry=1;
        }
        else if(carry==1){
            total=total+carry*ten;
            carry=0;
        }
        ten*=10;
    }
    
    while(a>0){
        int rem1=a%10;
        a=a/10;
        if(rem1==1&& carry==0){
            total=total+rem1*ten;
        }else if(rem1==1 && carry==1){
            carry=1;
        }else if(carry==1){
            total=total+1*ten;
            carry=0;
        }
        ten*=10;
    }
    while(b>0){
        int rem1=b%10;
        b=b/10;
        if(rem1==1&& carry==0){
            total=total+rem1*ten;
        }else if(rem1==1 && carry==1){
            carry=1;
        }else if(carry==1){
            total=total+1*ten;
            carry=0;
        }
        ten*=10;
    }
    if(carry==1){
        total=total+carry*ten;
        carry=0;
    }
    return total;
}
int main(){
    int a,b;

    cin>>a>>b;


    cout<<idk(a,b);

   return 0;
}
