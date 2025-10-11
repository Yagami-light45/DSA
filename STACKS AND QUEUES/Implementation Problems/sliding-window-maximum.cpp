#include<bits/stdc++.h>

using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;              
     //it’s a data structure that allows insertion and deletion from both ends — front and back — in O(1) time
  vector < int > ans;       // store max of each window
  for (int i = 0; i < nums.size(); i++) {

    // Remove index from front if it's outside the current window
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();
    // Remove all elements smaller than current from back
    while (!dq.empty() && nums[dq.back()] < nums[i]){   
        dq.pop_back();
    }
    // Add current element index to deque
    dq.push_back(i);
    // Window is full, add the max (front of deque) to answer
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}