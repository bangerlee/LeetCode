/*
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

*/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        if(data.size()<3) return 0;
        int num=0;
        for(auto& a:data)
            if(a==1) num++;
        int begin=0,end=0,cnt=0,imax=0;
        while(end<data.size()){
            while(end<data.size()&&end-begin<num)
                if(data[end++]==1) cnt++;
            imax=max(cnt,imax);
            if(end==data.size()) break;
            if(data[begin++]==1) cnt--;
        }
        return num-imax;
    }
};
