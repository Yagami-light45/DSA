#include <bits/stdc++.h>
using namespace std;

// ---------- Next Greater to the Right ----------
vector<int> nextGreaterRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);   // default -1
    stack<int> st;            // store indexes

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

