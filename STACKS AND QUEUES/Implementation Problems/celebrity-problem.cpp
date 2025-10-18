#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0, down = n-1;    // Top and Down pointers
 
        while(top < down) { // Traverse for all the people
            
            if(M[top][down] == 1) { //if top knows down , top cant be a celebrity
                top = top + 1;
            }
            
            else if(M[down][top] == 1) { //if down knows top , down cant be a celebrity
                down = down - 1;
            }
            else {
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        
        /* Check if the person pointed 
        by top is celebrity */
        for(int i=0; i < n; i++) {
            if(i == top) continue;
            // Check if it is not a celebrity
            if(M[top][i] == 1 || M[i][top] == 0) {
                return -1;
            }
        }
        // Return the index of celebrity
        return top;
    }
};
// //O (N^2) TIME AND O(2N) SPACE
// class Solution {
// public:
//     // Function to find the index of celebrity (everyonw knows him and he knows no one)
//     int celebrity(vector<vector<int>> &M){
//         // Size of given matrix
//         int n = M.size();           //1 if the x axis person knows the yaxis person
//         vector<int> knowMe(n, 0);  
//         vector<int> Iknow(n, 0);
//         // Traverse on given matrix
//         for(int i=0; i < n; i++) {
//             for(int j=0;j<n;j++){
//                 // If person i knows person j
//                 if(M[i][j] == 1) {
//                     knowMe[j]++;
//                     Iknow[i]++;
//                 }
//             }
//         }
//         // Traverse for all persons to find the celebrity
//         for(int i=0; i < n; i++){
//             // Return the index of celebrity
//             if(knowMe[i] == n-1 && Iknow[i] == 0) {
//                 return i;  
//             }}
//         // Return -1 if no celebrity is found
//         return -1;
//     }
// };

int main() {
    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };
    //here celebrity is 1
    Solution sol; 
    // Function call to find the index of celebrity
    int ans = sol.celebrity(M);
    cout << "The index of celebrity is: " << ans;
    
    return 0;
}