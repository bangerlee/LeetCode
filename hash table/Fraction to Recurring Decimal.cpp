/*
https://leetcode.com/problems/fraction-to-recurring-decimal/

*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string res="";
        if(numerator<0^denominator<0) res+="-";
        long num=abs((long)numerator);
        long deno=abs((long)denominator);
        res+=to_string(num/deno);
        if(num%deno==0) return res;
        res+=".";
        unordered_map<int,int> map;
        for(long r=num%deno;r;r%=deno){
            if(map.count(r)){
                res.insert(map[r],1,'(');
                res+=")";
                break;
            }
            map[r]=res.size();
            r*=10;
            res+=to_string(r/deno);
        }
        return res;
    }
};
