/*
https://leetcode.com/problems/my-calendar-iii/

*/
class MyCalendarThree {
private:
    map<int,int> books;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        books[start]++;
        books[end]--;
        int res=0,ongoing=0;
        for(auto x:books){
            res=max(res,ongoing+=x.second);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
