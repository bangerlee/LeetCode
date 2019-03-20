/*
https://leetcode.com/problems/different-ways-to-add-parentheses/

*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0;i<input.length();i++){
            if(input[i]=='+'||input[i]=='*'||input[i]=='-'){
                string p1=input.substr(0,i);
                string p2=input.substr(i+1);
                vector<int> res1=diffWaysToCompute(p1);
                vector<int> res2=diffWaysToCompute(p2);
                for(int l:res1){
                    for(int r:res2){
                        switch(input[i]){
                            case '+': res.push_back(l+r);break;
                            case '-': res.push_back(l-r);break;
                            default: res.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};
