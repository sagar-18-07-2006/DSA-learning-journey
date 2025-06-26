#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int Find_Duplicate_NUmmber(vector<int>& b){
  for (int i = 0; i <b.size() ; i++)
    {   
       int j=  count(b.begin(),b.end(),i) ;
         if(j==2){
           return i;
            break;
         }
    }
}
int main (){
    int n;
    cout<<"Enter the size of a List: ";
    cin>>n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {   int j;
        cout<<"Enter "<<i+1<<" number: ";
        cin>>j;
        nums.push_back(j);
    }
  
    cout<<"the duplicate is "<<Find_Duplicate_NUmmber(nums);
}