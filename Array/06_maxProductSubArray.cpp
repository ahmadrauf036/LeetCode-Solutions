

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currProd = 1, maxProd = INT_MIN, minProd = 1;
    
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(currProd, minProd);
        }
        
        currProd = max(nums[i], currProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        maxProd = max(maxProd, currProd);
        
        if (nums[i] == 0) {
            currProd = 1;
            minProd = 1;
        }
    }
    return maxProd;
}


int main(){
    vector<int> nums1={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxProduct(nums1)<<endl;

    vector<int> nums2={1};
    cout<<maxProduct(nums2)<<endl;

    vector<int> nums3={-3,-1,-1};
    cout<<maxProduct(nums3)<<endl;

    return 0;
}