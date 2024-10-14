

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int> nums){
    int currProd=1,maxProd=INT_MIN,minProd=1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        currProd*=nums[i];
        minProd*=currProd;
        if(minProd<0){
            if(minProd>maxProd){
                maxProd=minProd;
            }
            currProd=1;

        }
        else if(maxProd<minProd){
            maxProd=currProd;
        }
        if(currProd==0)
        {
            currProd=1;
            minProd=1;
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