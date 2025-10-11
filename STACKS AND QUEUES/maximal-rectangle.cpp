#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Find Previous Smaller Element (index of smaller bar on left)
    vector<int> previousSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top(); // -1 if none smaller
            st.push(i);
        }
        return pse;
    }

    // Find Next Smaller Element (index of smaller bar on right)
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top(); // n if none smaller
            st.push(i);
        }
        return nse;
    }

    // Compute largest rectangle area in a histogram
    long long largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = previousSmaller(heights);
        vector<int> nse = nextSmaller(heights);

        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long width = nse[i] - pse[i] - 1; // bars included between smaller ones
            long long area = 1LL * heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // Find maximal rectangle of 1s in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            // Build histogram for current row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1; // increase height
                else
                    heights[j] = 0;  // reset if 0 found
            }

            // Find largest area for this histogram
            int area = largestRectangleArea(heights);
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};
