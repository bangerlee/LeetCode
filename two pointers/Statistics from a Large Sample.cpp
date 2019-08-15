/*
https://leetcode.com/problems/statistics-from-a-large-sample/

*/
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int l=0,r=255,nl=0,nr=0,mn=255,mx=-1,mid1=0,mid2=0,mode=0;
        double avg=0,mid=0;
        while(l<=r){
            while(count[l]==0) l++;
            while(count[r]==0) r--;
            if(nl<nr){
                avg+=count[l]*l;
                nl+=count[l];
                if(count[l]>count[(int)mode]) mode=l;
                mn=min(mn,l);
                mid1=l;
                l++;
            }
            else{
                avg+=count[r]*r;
                nr+=count[r];
                if(count[r]>count[(int)mode]) mode=r;
                mx=max(mx,r);
                mid2=r;
                r--;
            }
        }
        avg/=(nl+nr);
        if(nl<nr) mid=mid2;
        else if(nl>nr) mid=mid1;
        else mid=(double)(mid1+mid2)/2;
        return {mn,mx,avg,mid,mode};
    }
};
