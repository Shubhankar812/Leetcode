#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                return true;
            }
            // left half
            else if(nums[mid] > nums[low]) {
                if(nums[low] <= target && nums[mid] > target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // right half 
            else if(nums[mid] < nums[low]) {
                if(nums[high] >= target && nums[mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else{
                low += 1;
            }

        }
        return false;
    }
int main()
{
    vector<int> a = {1,0,1,1,1};
    int k=0;

    cout<<search(a,k)<<"\n";
}