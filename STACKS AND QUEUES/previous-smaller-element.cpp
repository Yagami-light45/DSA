#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    // Traverse from left to right
    for(int i = 0; i < n; i++) {
        // Pop elements from stack while they're greater than current
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        // If stack is not empty, top element is the previous smaller
        if(!st.empty()) {
            res[i] = nums[st.top()];
        }
        // Push current index to stack
        st.push(i);
    }
    return res;
}