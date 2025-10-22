// number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.
//BRUTE FORCE - iterate over all possible substrings of the given string and check whether
// each one contains all three characters 'a', 'b', and 'c'
// BRUTE - TC  O(N^2) -  SC  O(1)
//OPTIMAL - TC O(N) - SC O(1)
#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s) {   
        int n = s.length();
        vector<int> lastseen(3, -1); // Initialize lastseen map for 'a', 'b', and 'c'
        int res = 0;

        for( int i=0;i<n;i++){
            lastseen[s[i] - 'a'] = i;

            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                int min_index = min({lastseen[0], lastseen[1], lastseen[2]});
                res+=(min_index+1);
            }
        }
        return res;
}
