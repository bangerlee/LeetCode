/*
https://leetcode.com/problems/exclusive-time-of-functions/
*/
class Solution {
private:
    vector<int> split(string s){
        vector<int> res;
        auto it=s.find(":");
        string tmp=s.substr(it+1,s.length()-it-1);
        res.push_back(stoi(s.substr(0,it)));
        auto itt=tmp.find(":");
        string p=tmp.substr(0,itt);
        if(p=="start") res.push_back(-1);
        else res.push_back(-2);
        res.push_back(stoi(tmp.substr(itt+1,tmp.length()-itt-1)));
        return res;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n,0);
        stack<int> st;
        int pre=0;
        for(string log:logs){
            vector<int> tmp=split(log);
            if(tmp[1]==-1){
                if(!st.empty()) ret[st.top()]+=(tmp[2]-pre);
                st.push(tmp[0]);
                pre=tmp[2];
            }
            else{
                ret[st.top()]+=(tmp[2]-pre+1);
                st.pop();
                pre=tmp[2]+1;
            }
        }
        return ret;
    }
};
