/*
https://leetcode.com/problems/dota2-senate/

*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int n=senate.length();
        for(int i=0;i<n;i++)
            senate[i]=='R'?q1.push(i):q2.push(i);
        while(!q1.empty()&&!q2.empty()){
            int ridx=q1.front();q1.pop();
            int didx=q2.front();q2.pop();
            ridx<didx?q1.push(ridx+n):q2.push(didx+n);
        }
        return q1.size()>q2.size()?"Radiant":"Dire";
    }
};
