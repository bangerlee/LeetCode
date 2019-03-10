/*
https://leetcode.com/problems/evaluate-division/

*/
class Solution {
private:
    double helper(string s1,string s2,double r,unordered_map<string,unordered_map<string,double>>& m,set<string> seen){
        if(!m.count(s1)||seen.count(s1)) return -1;
        seen.insert(s1);
        if(s1==s2) return r;
        auto it=m[s1].begin();
        while(it!=m[s1].end()){
            double res=helper(it->first,s2,(it->second)*r,m,seen);
            if(res!=-1) return res;
            it++;
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string,double>> m;
        for(int i=0;i<equations.size();i++){
            m[equations[i].first].insert(make_pair(equations[i].second,values[i]));             if(values[i]!=0)
                m[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
        }
        vector<double> res(queries.size());
        set<string> seen;
        for(int i=0;i<queries.size();i++){
            res[i]=helper(queries[i].first,queries[i].second,1,m,seen);
        }
        return res;
    }
};
