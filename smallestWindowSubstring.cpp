#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int count = 0;
        vector<int> arr(26, 0);
        for(int i = 0; i < p.size(); i++){
            if(arr[p[i]-'a'] == 0)
                count++;
            arr[p[i]-'a']++;
        }
        int len = INT_MAX;
        int i = 0, j = 0;
        string ans = "";
        int start = -1;
        while(j < s.length()){
            arr[s[j]-'a']--;
            if(arr[s[j]-'a'] == 0){
                count--;
            }
            while(count == 0){
                if(len > j - i + 1){
                    len = j - i + 1;
                    start = i;
                }
                arr[s[i]-'a']++;
                if(arr[s[i]-'a'] == 1){
                    count++;
                }
                i++;
            }
            j++;
        }
        return len != INT_MAX ? s.substr(start, len) : "-1";
    }
};
