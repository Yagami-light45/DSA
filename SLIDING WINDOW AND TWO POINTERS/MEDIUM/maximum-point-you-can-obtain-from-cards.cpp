#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();   
        int total = 0;      // Calculate initial sum by picking first k cards from front
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }
   
        int maxPoints = total;  // Store current max score

        for (int i = 0; i < k; ++i) {        // Move the window of k from front to back k times
            total -= cardPoints[k - 1 - i]; // Subtract card from front
            
            total += cardPoints[n - 1 - i];     // Add card from back

            maxPoints = max(maxPoints, total);       // Update max score if needed
        }

        return maxPoints;
    }