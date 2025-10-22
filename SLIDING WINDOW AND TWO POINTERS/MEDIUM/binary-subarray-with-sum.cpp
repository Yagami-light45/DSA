#include <bits/stdc++.h>
using namespace std;

//Brute force - O(N^2) TC - O(1) SC - Generate all subarrays and check every subarray's sum
//Better - O(N) TC - O(N) SC prefix sum technique- 
int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;     // Hashmap to store prefix sum frequencies
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;      // Add base case: prefix sum 0 has frequency 1
        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {      // If (sum - goal) exists in map, add its frequency to count
                count += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;      // Increment frequency of current prefix sum
        }

        return count;
    }

//Optimal - O(N) TC - O(1) SC- The subarrays with sum exactly goal are the ones included in atMost(goal) but not in atMost(goal - 1)
int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Return difference between subarrays with sum at most goal and at most (goal - 1)
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
int atMost(vector<int>& nums, int k) {
    int left = 0;
    int sum = 0;
    int count = 0;
    for (int right = 0; right < nums.size(); right++) { // Add current element to sum
        sum += nums[right];
        // Shrink the window from the left if sum exceeds k
        while (sum > k) {
            sum -= nums[left];
            left++;
        }
        // Add the number of valid subarrays ending at right
        count += (right - left + 1);
    }

    return count;
}
