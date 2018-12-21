/*
https://leetcode.com/problems/groups-of-special-equivalent-strings/

Runtime: 8 ms
*/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> sset;
        for(string s : A){
            string even="";
            string odd="";
            for(int i=0;i<s.length();i+=2) even+=s[i];
            for(int i=1;i<s.length();i+=2) odd+=s[i];
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            sset.insert(even+odd);
        }
        return sset.size();
    }
};
