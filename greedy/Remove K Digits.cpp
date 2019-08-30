/*
https://leetcode.com/problems/remove-k-digits/

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int cnt=num.size()-k;
        vector<char> stk;
        if(num.size()==0) return "0";
        stk.push_back(num[0]);
        for(int i=1;i<num.size();i++){
            char c=stk.back();
            while(num[i]<c&&k>0){
                stk.pop_back();
                k--;
                if(stk.empty()) break;
                else c=stk.back();
            }
            stk.push_back(num[i]);
        }
        vector<char> digits(stk.begin(),stk.begin()+cnt);
        int j=0;
        while(j<digits.size()&&digits[j]=='0') j++;
        string res(digits.begin()+j,digits.end());
        if(res.empty()) return "0";
        return res;
    }
};
*/
