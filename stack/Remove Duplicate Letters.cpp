/*
https://leetcode.com/problems/remove-duplicate-letters/

Runtime: 4 ms
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vc(256,0);
        vector<bool> visit(256,false);
        string res="0";
        for(char c : s) vc[c]++;
        for(char c : s){
            vc[c]--;
            if(visit[c]) continue;
            while(c<res.back()&&vc[res.back()]){
                visit[res.back()]=false;
                res.pop_back();
            }
            res.push_back(c);
            visit[c]=true;
        }
        return res.substr(1);
    }
};
