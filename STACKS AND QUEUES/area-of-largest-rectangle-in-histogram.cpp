#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
             int element = st.top();
             st.pop();
             int nse = i;
             int pse = st.empty()?-1:st.top();
             maxArea = max(maxArea , heights[element] * (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxArea = max(maxArea , heights[element] * (nse-pse-1));


        }

        
        return maxArea;
    }
};

// Test case
int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};  // Expected output: 10
    cout << "Largest rectangle area: " << sol.largestRectangleArea(heights) << endl;
    
    // Additional test case
    vector<int> heights2 = {2,4};  // Expected output: 4
    cout << "Largest rectangle area: " << sol.largestRectangleArea(heights2) << endl;
    
    return 0;
}