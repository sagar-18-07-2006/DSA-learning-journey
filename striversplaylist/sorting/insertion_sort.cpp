#include<iostream>
using namespace std;
void swap(int&a,int&b){
     int rm=a;
     a=b;
     b=rm;

}
int main(){
    int arr[] ={1,2,4,1,56,1,788,1,5,3,5,9,5,89,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int j=i;
        while(arr[j]<arr[j-1]){
        swap(arr[j],arr[j-1]);
        j--;
        }
    }

     for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
            cout << endl;
        }
    return 0;

}