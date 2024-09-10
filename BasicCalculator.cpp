#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        long long int ans = 0, curr = 0;
        s += '+';
        char sign = '+';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' and s[i] <= '9')
                curr = curr * 10 + (s[i] - '0');
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (sign == '+')
                    st.push(curr);
                else if (sign == '-')
                    st.push(curr * (-1));
                else if (sign == '*')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num * curr);
                }
                else if (sign == '/')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num / curr);
                }
                sign = s[i];
                curr = 0;
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};