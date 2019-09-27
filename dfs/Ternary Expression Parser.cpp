/*
https://leetcode.com/problems/ternary-expression-parser/

*/
class Solution {
public:
    string parseTernary(string expression) {
        if(expression.length()==1) return expression;
        int i=1,count=1;
        while(count!=0){
            char c=expression[++i];
            count+=c=='?'?1:c==':'?-1:0;
        }
        return expression[0]=='T'?parseTernary(expression.substr(2,i-2)):parseTernary(expression.substr(i+1));
    }
};
