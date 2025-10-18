#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int back = 0;
        int front = 0;
        int ans = 0;
        vector<int> mpp(256, -1);

        while (front < n) {
            // if this character was seen inside the current window
            if (mpp[s[front]] >= back) {
                back = mpp[s[front]] + 1;
            }

            // update last index of this character
            mpp[s[front]] = front;

            // calculate window length
            int len = front - back + 1;
            ans = max(ans, len);

            front++;
        }

        return ans;
    }
};
