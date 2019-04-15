/*
https://leetcode.com/problems/ip-to-cidr/

*/
class Solution {
private:
    int ipToInt(string& ip){
        stringstream ss(ip);
        int a,b,c,d;
        char ch;
        ss >> a >> ch >> b >> ch >> c >> ch >> d;
        return (a<<24)|(b<<16)|(c<<8)|d;
    }
    int getEndZero(int ip){
        if(ip==0) return sizeof(int);
        int count=0;
        while((ip&0x1)==0){
            count++;
            ip>>=1;
        }
        return count;
    }
    void deal(vector<string>& res,int& startIP,int& n){
        int endZero=getEndZero(startIP);
        int covered=1<<endZero;
        while(covered>n) covered>>=1,endZero--;
        string tmp=to_string((startIP>>24)&0xFF)+"."+to_string((startIP>>16)&0xFF)+"."+to_string((startIP>>8)&0xFF)+"."+to_string(startIP&0xFF)+"/"+to_string(32-endZero);
        res.push_back(tmp);
        n-=covered;
        startIP+=covered;
    }
public:
    vector<string> ipToCIDR(string ip, int n) {
        int startIP=ipToInt(ip);
        vector<string> res;
        while(n) deal(res,startIP,n);
        return res;
    }
};
