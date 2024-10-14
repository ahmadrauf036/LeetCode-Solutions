/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.

Solution:
Applied binary search in a way such that, it will compare the right most element with
the mid element, if the element at the right is greater than the mid element, minimum should be on the
left side from mid, otherwise it should be on right side.
*/

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> nums)
{
    int end=nums.size()-1,st=0;
    while(st!=end)
    {
        int mid=(st+end)/2;
        if(nums[end]>nums[mid])
        {
            end=mid;
        }
        else if(nums[end]<nums[mid])
        {
            st=mid+1;
        }
    }
    return nums[end];
    
}
int main(){
    vector<int> nums={3,4,5,1,2};
    cout<<findMin(nums)<<endl;
    vector<int> nums1={4,5,6,7,0,1,2};
    cout<<findMin(nums1)<<endl;
    vector<int> nums2={11,13,15,17};
    cout<<findMin(nums2)<<endl;   
}