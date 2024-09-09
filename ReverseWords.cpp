#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;
            string word = "";
            while (i < s.length() and s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            st.push(word);
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (!st.empty())
                res += ' ';
        }
        return res;
    }
};