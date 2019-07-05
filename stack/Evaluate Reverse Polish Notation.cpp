/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i].length()>1||isdigit(tokens[i][0])){
                s.push(stoi(tokens[i]));
            }
            else{
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                if(tokens[i]=="+"){
                    s.push(num1+num2);
                }
                else if(tokens[i]=="-"){
                        s.push(num1-num2);
                }
                else if(tokens[i]=="*"){
                    s.push(num1*num2);
                }
                else{
                    s.push(num1/num2);
                }
            }
        }
        return s.top();
    }
};
