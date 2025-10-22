//Max length subarray with atmost 2 unique types of numbers
// NAIVE APPROACH - generate all subarrays put them in set until set.size() <=2
//O(N^2) TC . O(3) SC   


//BETTER APPROACH   O(2N) TC
#include <bits/stdc++.h>
using namespace std;
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int maxFruits = 0;
        int left = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            // Shrink the window if more than 2 types of fruits exist
            while (basket.size() > 2) {
                // Decrease count of fruit at left pointer
                basket[fruits[left]]--;
                // If count becomes zero, remove it from map
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }

    //OPTIMAL APPROACH O(N)
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int lastfruit = -1, secondlastfruit = -1;
        int currcount = 0, lastfruitstreak = 0;     // Count of current window size and the last fruit streak

        for (int fruit : fruits) {
         if (fruit == lastfruit || fruit == secondlastfruit) {   // If current fruit is same as last or second last, increase window
                currcount++;
            } else {
                currcount = lastfruitstreak + 1;     // Reset window size to size of last fruit streak + 1 (current fruit)
            }
            if (fruit == lastfruit) {
                lastfruitstreak++;
            } else {
                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }
            maxlen = max(maxlen, currcount);
        }

        return maxlen;
    }