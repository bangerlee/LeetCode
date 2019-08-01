/*
https://leetcode.com/problems/valid-anagram/

*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(128);
        for(char x:s) v[x-'a']++;
        for(char c:t) v[c-'a']--;
        for(int p:v) if(p!=0) return false;
        return true;
    }
};
