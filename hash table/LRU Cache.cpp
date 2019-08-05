/*
https://leetcode.com/problems/lru-cache/

*/
class LRUCache {
private:
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        l.splice(l.begin(),l,m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]->second=value;
            l.splice(l.begin(),l,m[key]);
            return;
        }
        if(l.size()==capacity){
            pair<int,int> tmp=l.back();
            m.erase(tmp.first);
            l.pop_back();
        }
        l.emplace_front(key,value);
        m[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
