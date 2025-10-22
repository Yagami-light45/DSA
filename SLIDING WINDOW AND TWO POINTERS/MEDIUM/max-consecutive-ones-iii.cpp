// return the maximum number of consecutive 1's in the array if you can flip at most k 0's
//CAN ALSO BE SAID AS longest subarray with atmost k zeroes.
#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {     //BRUTE FORCE
    int maxLen = 0;                              //O(n^2) time

    for (int i = 0; i < nums.size(); i++) {
        int zeros = 0;

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 0) {
                zeros++;
            }

            // If number of zeros exceeds k, break this subarray
            if (zeros > k) {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
//BETTER SOLN - O(2N) AND O(1)
int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {             // If current element is zero, increment zero counter
                zeros++;
            }           // If number of zeros exceeds k, shrink the window from left
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;             // Move the left pointer forward
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    //Optimal O(N ) AND O(1)
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zerocount = 0;
        int maxlen = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }
            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }

