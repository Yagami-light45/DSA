// Implement the power function pow(x, n)
#include <bits/stdc++.h>
using namespace std;
// double myPow(double x , int n ){         //O(n)

//     if(n == 0){
//         return 1;
//     }
//     if(n<0){
//         return 1/myPow(x,-n);
//     }
//     return x * myPow(x , floor(n/2));
// }
double myPow(double x , int n){     //O(log(n))
    if(n==0){
        return 1;
    }
    if(n<0){
        return 1/myPow(x,-n);
    }
    long long half = myPow(x , n/2);
    if(n%2 == 0){
        return half * half;
    }
    else return half *half * x;
}
int main() {
    
    double x = 2.0;
    int n = 10;

    // Calculate x raised to n
    double result = myPow(x, n);

    // Print the result
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}