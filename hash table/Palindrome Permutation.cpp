/*
https://leetcode.com/problems/palindrome-permutation/

*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> m;
        for(char x:s) m[x]++;
        bool f=true;
        auto it=m.begin();
        while(it!=m.end()){
            if(it->second%2!=0&&f==false) return false;
            if(it->second%2!=0) f=false;
            it++;
        }
        return true;
    }
};
