#include <iostream>
#include<vector>
using namespace std;
void merge(int arr[],int start,int mid , int end){
    vector<int> temp;
    int i =start;
    int j =mid+1;
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;

        }
    }
    while(i<= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int i= start;i<=end ;i++){
        arr[i]=temp[i-start];

    }
    
}
void mergesort(int arr[], int start, int end)
{
    int mid = start + ((end - start) / 2);
    if (start < end)
    {
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
    }
    merge(arr ,start,mid,end);
}
int main()
{
    int n;
    cout << "enter the size of array  ";
    cin >> n;
    int arr[n];
    cout << "Enter the values for the array \n";
    for (int i = 0; i < n; i++)
    {
        cout << "enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }
    mergesort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i] <<endl;
        
    }
    
}