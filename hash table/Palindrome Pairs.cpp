/*
https://leetcode.com/problems/palindrome-pairs/
*/
class Solution {
private:
    bool ispalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i++]!=s[j--]) return false;
    }
        return true;
}
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> m;
        vector<vector<int>> res;
        if(words.size()<2) return res;
        for(int i=0;i<words.size();i++){
            string tmp=words[i];
            reverse(tmp.begin(),tmp.end());
            m[tmp]=i;
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<=words[i].length();j++){
                string s1=words[i].substr(0,j);
                string s2=words[i].substr(j);
                if(m.count(s1)&&ispalindrome(s2)&&m[s1]!=i)
                    res.push_back(vector<int>{i,m[s1]});
                if(!s1.empty()&&m.count(s2)&&ispalindrome(s1)&&m[s2]!=i)
                    res.push_back(vector<int>{m[s2],i});
            }
        }
        return res;
    }
};
