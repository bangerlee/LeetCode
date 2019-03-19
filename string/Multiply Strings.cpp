/*
https://leetcode.com/problems/multiply-strings/

*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        vector<int> res(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int idx1=i+j,idx2=i+j+1;
                int sum=(num1[i]-'0')*(num2[j]-'0')+res[idx2];
                res[idx1]+=sum/10;
                res[idx2]=sum%10;
            }
        }
        string ans="";
        for(auto x:res) if(!(ans.length()==0&&x==0)) ans+=to_string(x);
        return ans.length()==0?"0":ans;
    }
};
