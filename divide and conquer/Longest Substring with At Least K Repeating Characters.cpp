/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

*/
class Solution {
private:
    int helper(int l,int r,string& s,int k){
        vector<int> v(26,0);
        for(int i=l;i<=r;i++) v[s[i]-'a']++;
        bool pass=true,flag=false;
        for(int i=0;i<26;i++){
            if(v[i]>0) flag=true;
            if(v[i]>0&&v[i]<k){
                pass=false;
            }
        }
        if(!flag) return 0;
        if(pass&&flag) return r-l+1;
        
        int q=l,res=0;
        for(int j=l;j<=r;j++){
            if(v[s[j]-'a']>0&&v[s[j]-'a']<k){
                res=max(res,helper(q,j-1,s,k));
                q=j+1;
            }
        }
        return max(res,helper(q,r,s,k));
    }
public:
    int longestSubstring(string s, int k) {
        int n=s.length()-1;
        return helper(0,n,s,k);
    }
};
