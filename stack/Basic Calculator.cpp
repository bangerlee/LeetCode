/*
https://leetcode.com/problems/basic-calculator/

Runtime: 8 ms
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> n,ops;
        int sign=1,num=0,res=0;
        for(char c : s){
            if(isdigit(c))
                num=num*10+c-'0';
            else{
                res+=sign*num;
                num=0;
                if(c=='+')
                    sign=1;
                else if(c=='-')
                    sign=-1;
                else if(c=='('){
                    n.push(res);
                    ops.push(sign);
                    res=0;
                    sign=1;
                }
                else if(c==')'&&ops.size()){
                    res=ops.top()*res+n.top();
                    n.pop(),ops.pop();
                }
            }
        }
        res+=sign*num;
        return res;
    }
};
