#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int index = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            int j = 0;
            if (haystack[i] == needle[j])
            {
                index = i;
                i++, j++;
                while (i < haystack.size() and j < needle.size() and haystack[i] == needle[j])
                {
                    i++, j++;
                }
                if (j == needle.size())
                    return index;
                else
                {
                    i = index;
                    index = -1;
                }
            }
        }
        return index;
    }
};