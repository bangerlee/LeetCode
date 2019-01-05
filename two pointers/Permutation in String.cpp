/*
https://leetcode.com/problems/permutation-in-string/

Runtime: 76 ms
*/
class Solution {
private:
    bool allzero(map<char,int> m){
        for(auto it:m){
            if(it.second>0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> counter;
        for(char a:s1) counter[a]++;
        int i=0;
        for(int j=0;j<s2.length();j++){
            counter[s2[j]]--;
            if(j-i>=s1.length()-1){
                if(allzero(counter)) return true;
                counter[s2[i]]++;
                i++;
            }
        }
        return false;
    }
};
