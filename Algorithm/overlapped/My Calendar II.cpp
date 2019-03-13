/*
https://leetcode.com/problems/my-calendar-ii/

*/
class MyCalendar {
private:
    vector<pair<int,int>> v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:v)
            if(max(start,x.first)<min(end,x.second)) return false;
        v.push_back({start,end});
        return true;
    }
};

class MyCalendarTwo {
private:
    vector<pair<int,int>> books;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        MyCalendar bookfirst;
        for(auto x:books){
            if(max(start,x.first)<min(end,x.second)){
                pair<int,int> overlapped={max(start,x.first),min(end,x.second)};
                if(!bookfirst.book(overlapped.first,overlapped.second)) return false;
            }
        }
        books.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
