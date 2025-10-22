// An array is called nice if and only if it contains k odd numbers
// We can't directly count subarrays with exactly K odd numbers using one pass of sliding window. But we can count how many subarrays have at most K odd numbers. If we do this for both K and K-1, then the difference gives us the number of subarrays that have exactly K odd numbers. This works because: countExactlyK = countAtMost(K) - countAtMost(K - 1).

#include <bits/stdc++.h>
using namespace std;

int countAtMost(vector<int>& nums, int k) {
        int left = 0, res = 0;
        for (int right = 0; right < nums.size(); right++) {
              if (nums[right] % 2 != 0)      k--;      // If current number is odd, reduce k
               
            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    }
    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
