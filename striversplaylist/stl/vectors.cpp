#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> val ;
    for (int i = 0; i < 4; i++)
    {   
        int j;
       cout<<"Enter the "<<i+1<<"th number "<<endl;;
       cin>>j;
       val.push_back(j);
    }
    val.insert(val.begin(),6,25);
    for (int i:val){
        cout<<i<<endl;
    }
    
}