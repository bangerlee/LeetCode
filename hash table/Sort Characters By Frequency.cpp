/*
https://leetcode.com/problems/sort-characters-by-frequency/

*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto& c:s) freq[c]++;
        map<int,string> dupStr;
        for(auto v:freq) dupStr[v.second]+=string(v.second,v.first);
        string res="";
        for(auto it=dupStr.rbegin();it!=dupStr.rend();it++) res+=it->second;
        return res;
    }
};
