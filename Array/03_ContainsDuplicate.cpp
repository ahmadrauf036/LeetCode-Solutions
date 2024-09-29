/*
Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].

You must write an algorithm that runs in O(n) time and without using the division operation.
Solution:
Using unordered_set, inserting elements in it, if element already exists it will return true.
*/
#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i])!=s.end())
        {
            return true;    
        }
        s.insert(nums[i]);
    }
    return false;
    
    
}
int main()
{
    vector<int> nums={1,2,3,2,4};
    containsDuplicate(nums)?(cout<<"Duplicate exists."<<endl):(cout<<"Duplicate doesn't exists."<<endl);
    return 0;
}