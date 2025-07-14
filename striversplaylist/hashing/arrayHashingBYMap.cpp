#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter thee number of Elements in Array :";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cout<<"Enter "<<i+1<<"th Element ";
       cin>>arr[i];
    }
    map<int,int>hash;
     for(int i=0;i<n;i++){
       hash[arr[i]]++;
     }    
    int q;
    cout<<"Enter number of queries you Have:  ";
    cin>>q;
    for (int  i = 0; i <q; i++)
    {   int j;
        cout<<"Enter The Querry: ";
        cin>>j;
        if(i in hash)
    }
    
    
}