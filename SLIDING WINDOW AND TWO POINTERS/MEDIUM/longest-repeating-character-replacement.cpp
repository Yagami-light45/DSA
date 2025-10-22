//maximum window with atmost K other letters and rest all same.
//The core logic behind the solution is based on the condition: "length - maxFreq <= 2."
#include<bits/stdc++.h>
using namespace std;
//BRUTE FORCE - GENERATE ALL SUBSTRINGS - O(n^2) TC
int characterReplacement(string s, int k) {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);        // Initialize frequency array for current substring
            int maxFreq = 0;            // Track max frequency character in the current substring
            
            for (int j = i; j < s.length(); j++) {
                freq[s[j]-'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                int windowLength = j - i + 1;
                int replace = windowLength - maxFreq;       // Check how many characters we need to replace
                
                if (replace <= k) { // update answer
                    maxLength = max(maxLength, windowLength);
                }
            }
        }
        
        return maxLength;
    }
    //better approach - two pointers - O(2N) TC -O(26) SC
        int characterReplacement(string s, int k) {
            unordered_map<char, int> freq;  //FREQ MAP
            int left = 0;
            int max_freq = 0;
            int max_len = 0;

            for (int right = 0; right < s.length(); right++) {
                freq[s[right]]++;
                max_freq = max(max_freq, freq[s[right]]);            
                while ((right - left + 1) - max_freq > k) {     // If window is invalid (needs more than k replacements)
                    freq[s[left]]--;        // Decrease frequency of the character at left
                    left++;         // Shrink the window from the left
                }
                max_len = max(max_len, right - left + 1);
            }
            return max_len;
        }

        //optimal O(N)
        int characterReplacement(string s, int k) {
            unordered_map<char, int> freq;  //FREQ MAP
            int left = 0;
            int max_freq = 0;
            int max_len = 0;

            for (int right = 0; right < s.length(); right++) {
                freq[s[right]]++;
                max_freq = max(max_freq, freq[s[right]]);            
                if((right - left + 1) - max_freq > k) {     // If window is invalid (needs more than k replacements)
                    freq[s[left]]--;        // Decrease frequency of the character at left
                    left++;         // Shrink the window from the left
                }
                max_len = max(max_len, right - left + 1);
            }
            return max_len;
        }