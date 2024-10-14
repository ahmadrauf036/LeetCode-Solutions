/*
Question:
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order. 
*/
/*
First tried brute-force, in which i was iterating each element and checking if they
are equal to target by adding.

Then used unordered_map(hash data structure),
Simply, the logic is to check if the {target-number} is present in vector or not.

I have made the elements of vector as keys of map (that can be helpful in
unordered_map.find function) and there index as value.. after this we will our target-number in map,
Then if the element is found, its value(that is element's index w.r.t vector) and index of second element
is printed on console.
*/
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void two_sum(vector<int> nums,int target)
{
    
    unordered_map<int,int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]=i;
    }
    for(int i=0;i<nums.size();i++)
    {
        auto found=m.find(target-nums[i]);
        if(found!=m.end())
        {
            if(found->second!=i)
            {
                cout<<"index: "<<endl<<found->second<<" "<<i<<endl;
                return;
            }
        }
    }
}
int main()
{
    vector<int> nums;
    for (int i = 0; i < 5; i++)
    {
        int n=0;
        cout<<"Enter value: ";cin>>n;
        nums.push_back(n);
    }
    two_sum(nums,8);
    return 0;
}