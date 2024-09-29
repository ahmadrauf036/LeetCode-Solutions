/*
simply my logic is to implement 
result[i]=(suffix product * prefix product) w.r.t ith element
--> First, store product of prefix of each element in result.
*** prefix = nums[i]*prefix ***
--> Then, find sufix of each element by iterating in decreasing order
and multiply it with result of respected element 
*** suffix = nums[i+1]*sufix ***
*** result[i]=sufix*result[i] ***
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    unordered_map<int,int> umap;
    vector<int> result(nums.size());
    {
        int suffix=1;
        umap[nums[nums.size()-1]]=suffix;
        for(int i=nums.size()-2;i>=0;i--) {
            suffix=nums[i+1]*suffix;
            umap[nums[i]]=suffix;
        }
    }
    {
        int prefix=1;
        result[0]=prefix*umap[nums[0]];
        for(int i=1;i<nums.size();i++) {
            prefix=nums[i-1]*prefix;
            result[i]=prefix*umap[nums[i]];
        }
    }
    return result;

}

int main() {
    vector<int> nums={-1,2,9,6};
    
    vector<int> result=productExceptSelf(nums);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    


}