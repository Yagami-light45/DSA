#include <bits/stdc++.h>
using namespace std;

// ---------- Next Greater to the Right ----------
vector<int> nextGreaterRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);   // default -1
    stack<int> st;            // store indexes

    // Traverse from right to left for next greater element
    for (int i = n-1; i >= 0; i--) {
        // Pop elements while stack top is smaller than current
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        // If stack not empty, top has next greater element
        if (!st.empty()) {
            res[i] = nums[st.top()];
        }
        st.push(i);
    }
    return res;
}

