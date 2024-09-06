#include <bits/stdc++.h>
using namespace std;

void countDuplicates(string &s)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < s.length() - 1; i++)
    {
        mp[s[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > 1)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
}

int main()
{
    string s = "test string";
    countDuplicates(s);
}