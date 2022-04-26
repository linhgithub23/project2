
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    //check if all digits are even
    while(n!=0){
        m=n%10;
        if(m%2==0){
            n=n/10;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
}