#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);   // default -1
    stack<int> st;            // store indexes

    for (int i = 0; i < n; i++) {
        // While current element is smaller than the element at top index
        while (!st.empty() && nums[i] < nums[st.top()]) {
            res[st.top()] = nums[i]; // current element is NSE for that index
            st.pop();
        }
        st.push(i); // push index
    }
    return res;
}
