#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        vector<int> mp(26, 0);
        for (char ch : p)
        {
            mp[ch]++;
        }

        int count = mp.size(); // Count of unique characters to match
        int min_len = INT_MAX;
        int start = 0, i = 0, j = 0;

        // Sliding window approach
        while (j < s.length())
        {
            // Process the current character in the window
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }

            // Shrink the window from the left if all characters are matched
            while (count == 0)
            {
                if (j - i + 1 < min_len)
                {
                    min_len = j - i + 1;
                    start = i; // Track the starting index of the smallest window
                }

                // Shrink the window from the left by moving i forward
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                    {
                        count++;
                    }
                }
                i++;
            }

            j++;
        }

        return min_len != INT_MAX ? s.substr(start, min_len) : "-1";
    }
};