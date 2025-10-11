#include <bits/stdc++.h>
using namespace std;
//NOT OPTIMAL
//O(3N) TC AND O(4N) SPACE
//Previous Smaller Element
vector<int> previousSmaller(vector<int>& heights) {
    int n = heights.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

//Next Smaller Element
vector<int> nextSmaller(vector<int>& heights) {
    int n = heights.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty()) nse[i] = n;
        else nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

// Function to compute largest rectangle area
long long largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> pse = previousSmaller(heights);
    vector<int> nse = nextSmaller(heights);

    long long maxArea = 0;
    for (int i = 0; i < n; i++) {
        long long width = nse[i] - pse[i] - 1;
        long long area =  heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Driver code
int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
    return 0;
}

// OPTIMAL 
// O(N) TC AND O(2N ) SC

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