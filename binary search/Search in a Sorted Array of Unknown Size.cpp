/*
https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/

*/
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int hi=1;
        while(reader.get(hi)<target) hi<<=1;
        int lo=hi>>1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(reader.get(mid)<target) lo=mid+1;
            else if(reader.get(mid)>target) hi=mid-1;
            else return mid;
        }
        return -1;
    }
};
