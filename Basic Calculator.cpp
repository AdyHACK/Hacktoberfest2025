#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, num = 0, sign = 1;
        
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num*10 + (c - '0');
            } else if (c == '+') {
                res += sign*num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign*num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign*num;
                num = 0;
                res *= st.top(); st.pop(); // sign
                res += st.top(); st.pop(); // prev res
            }
        }
        return res + sign*num;
    }
};

int main() {
    Solution sol;
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)"); // Output: 23
}
