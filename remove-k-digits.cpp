#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack <char> st;
        
        for (int i = 0; i < n; i++) {
            // If the current digit is smaller than the top of the stack, pop the stack
            // to ensure the number formed is the smallest possible.
            while (!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        // If k digits still need to be removed, pop from the stack.
        while (k > 0) {
            st.pop();
            k--;
        }
        // If the stack is empty, it means the number is 0.
        if (st.empty()) return "0";
        string res = "";
        // Construct the result from the stack.
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        // Remove leading zeros.
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        // Reverse the result string to get the correct number.
        reverse(res.begin(), res.end());
        // If the result is empty, return "0" to handle the case where all digits are removed.
        if (res.empty()) return "0";

        return res;
    }
};