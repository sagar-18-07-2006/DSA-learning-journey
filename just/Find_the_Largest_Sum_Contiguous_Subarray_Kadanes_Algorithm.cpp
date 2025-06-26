#include<iostream>
#include <vector>
using namespace std;
int slice_adder(int a,int b,vector<int>& l){
    int sum =0;
    for(int i=a;i<=b;i++){
        sum+=l[i];
    }
    return sum;
}
int main (){
    int n;
    cout<<"Enter the size of arraay";
    cin>>n;
    vector <int> a;
    for (int i =0; i<n;i++){
        int l;
        cout<<"enter "<<i+1<<"st element";
        cin>>l;
        a.push_back(l);
    }
    // cout<<(a[3]);
int sum=a[0];
int k,l;
for (int i=0;i<n;i++){
    int currentSum=a[0];
    for (int j=i;j<n;j++){
        // int o=slice_adder(i,j,a);
        // if(sum<o){
        //     sum = o;
        currentSum+=a[j];
        sum=max(sum,currentSum);
        //     k=i; 
        //     l=j;
        // }
    }

}
cout<<k<<"  "<<l;
}
