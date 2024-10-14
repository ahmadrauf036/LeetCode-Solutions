#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> two_sum(vector<int> nums,int target,int ignore=-1)
{
    
    unordered_map<int,int> m;
    vector<vector<int>> fresult={};
    vector<int> result={};
    for (int i = 0; i < nums.size(); i++)
    {
        if(i!=ignore){
            m[nums[i]]=i;
        }
    }
    for(int i=0;i<nums.size();i++)
    {
        if(ignore!=i){
            auto found=m.find(target-nums[i]);
            if(found!=m.end())
            {
                if(found->second!=i)
                {
                    result.push_back(nums[i]);
                    result.push_back(found->first);
                    result.push_back(target*-1);
                    fresult.push_back(result);
                }
            }
        }
    }
    return fresult;
}

vector<vector<int>> threeSum(vector<int> nums){
    unordered_map<int,int> mp1;
    vector<vector<int>> result={};
    vector<vector<int>> finalResult={};

    for (size_t i = 0; i < nums.size(); i++){
            mp1[i]=nums[i]*(-1);
    }
    for (auto i:mp1){
        result=two_sum(nums,i.second,i.first);
        if(result.empty()){
            continue;
        }
        bool found=0;
        if(!finalResult.empty()){
            for (size_t i = 0; i < finalResult.size(); i++)
            {
                for(size_t j = 0; j < finalResult.size(); j++){
                    sort(result[j].begin(),result[j].end());
                    if(finalResult[i]==result[j]){
                        found=1;
                        continue;
                    }
                    finalResult.push_back(result[j]);
                }
            }
        }
        else{
            for(size_t j = 0; j < finalResult.size(); j++){
                    sort(result[j].begin(),result[j].end());
                    finalResult.push_back(result[j]);
                }
        }
        if(found){
            continue;
        }
    }
    return finalResult;    
    
}

int main(){ 
    vector<int> nums={3,0,-2,-1,1,2};
    vector<vector<int>> result=threeSum(nums);
    
    if(result.empty()){
        cout<<"No such triplet exists.";
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        cout<<"[";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j];
            if(j!=result[i].size()-1)
            {
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
        
    }
    
}