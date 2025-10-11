#include <bits/stdc++.h>
using namespace std;
    //Basically previous greater element
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);       // to store final answer
    stack<int> st;             // stores indices of days

    for (int i = 0; i < n; i++) {
        // Pop all smaller or equal prices from stack
        while (!st.empty() && prices[st.top()] <= prices[i])
            st.pop();

        // If stack empty → no greater element on left
        // else → difference between current index and top index
        span[i] = st.empty() ? (i + 1) : (i - st.top());

        // Push current day's index
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpan(prices);

    cout << "Stock Span: ";
    for (int s : span) cout << s << " ";
    return 0;
}
