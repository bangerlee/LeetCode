/*
https://leetcode.com/problems/additive-number/

Runtime: 0 ms
*/
class Solution {
private:
    bool dfs(string& num,int idx,vector<unsigned long long>& v)
    {
        if(idx>=num.length()&&v.size()>2) return true;
        int maxsplit=(num[idx]=='0'?1:19);
        int size=v.size();
        for(int j=1;j<=maxsplit&&j+idx<=num.length();j++){
                string tmp=num.substr(idx,j);
            if(size>=2&&v[size-1]+v[size-2]<stoll(tmp)) return false;
                if((size>=2&&v[size-1]+v[size-2]==stoll(tmp))||size<2){
                    v.push_back(stoll(tmp));
                    if(dfs(num,idx+j,v)) return true;
                    v.pop_back();
            }
        }
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        vector<unsigned long long> v;
        return dfs(num,0,v);
    }
};
