/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Solution:
Applying kadane's algorithm, whenever the current sum is negative, it will be  
*/


#include<iostream>
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Solution:
Applying kadane's algorithm, whenever the current sum is negative, it will be  
*/

#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int> nums){
    int currSum=0,maxSum=INT_MIN;
    for (size_t i = 0; i < nums.size(); i++)
    {
        currSum+=nums[i];
        if(maxSum<currSum){
            maxSum=currSum;
        }
        if(currSum<0)
        {
            currSum=0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> nums1={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums1)<<endl;

    vector<int> nums2={1};
    cout<<maxSubArray(nums2)<<endl;

    vector<int> nums3={5,4,-1,7,8};
    cout<<maxSubArray(nums3)<<endl;

    return 0;
}