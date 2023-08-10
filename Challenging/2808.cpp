#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int minimumSeconds(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> mp;

    // adding elements to the map
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(i);
    }

    // find the max gap
    int smallestMaxGap = INT_MAX;
    for (auto &[key,pos] : mp)
    {

        // adding 1 more element to handle the circular position
        pos.push_back(pos[0] + n);

        // finding the max gap for current element
        int maxGap = 0;
        for (int i = 1; i < pos.size(); i++)
        {
            maxGap = max(maxGap , (pos[i] - pos[i - 1]));
        }

        // update the smallestMaxGap with current element's information
        smallestMaxGap = min(maxGap, smallestMaxGap);
    }
    int ans = smallestMaxGap / 2;
    return ans;
}
int main()
{
    vector<int> nums = {1,2,1,2};
    cout<<minimumSeconds(nums)<<endl;
}