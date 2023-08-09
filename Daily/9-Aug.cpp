#include <bits/stdc++.h>
using namespace std;

// to check if we can form pairs till index 'mid'; returns true if no. of pairs is greater than or equal to p
bool check(vector<int> &nums, int mid, int p)
{
    int count = 0;
    int i = 0;

    while (i < nums.size() - 1 && count < p)
    {
        if (mid >= nums[i + 1] - nums[i])
        {
            count += 1;
            i += 2;
        }
        else
        {
            i++;
        }
    }
    return (count >= p);
}
int minimizeMax(vector<int> &nums, int p)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int left = 0, right = nums[n - 1] - nums[0];
    // apply binary search
    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // if we find some mid that can give pairs,then again move in the left to check if we can form pairs in it's left part.
        if (check(nums, mid, p))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int p=2;
    vector<int> nums = {10,1,2,7,1,3};

    int ans = minimizeMax(nums,p);
    cout<<ans<<"\n";
}