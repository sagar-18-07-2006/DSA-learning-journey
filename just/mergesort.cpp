#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &num, int start, int end, int mid){
    
}
void mergesort(vector<int> &nums ,int start, int end)
{
    int start = 0;
    auto end = nums.end();
    int mid = start + (end - start) / 2;
    if (start < end)
    {
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);
    }
    merge(nums,start,end,mid)
}