#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> finalResult;
    sort(nums.begin(), nums.end()); 

    for (int i = 0; i < nums.size() - 2; i++) {
        
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int st = i + 1, end = nums.size() - 1;
        while (st < end) {
            int sum = nums[i] + nums[st] + nums[end];
            if (sum == 0) {
                finalResult.push_back({ nums[i], nums[st], nums[end] });
                while (st < end && nums[st] == nums[st + 1]) st++;
                while (st < end && nums[end] == nums[end - 1]) end--;

                st++;
                end--;
            }
            else if (sum < 0) {
                st++;
            }
            else {
                end--;
            }
        }
    }
    return finalResult;
}

int main() {
    vector<int> nums = { 1,2,3,0,-1 };
    vector<vector<int>> result = threeSum(nums);

    if (result.empty()) {
        cout << "No such triplet exists.";
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}