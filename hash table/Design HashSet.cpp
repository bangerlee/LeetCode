/*
https://leetcode.com/problems/design-hashset/

*/
class MyHashSet {
private:
    bitset<1000001> bs;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    void add(int key) {
        bs.set(key);
    }
    
    void remove(int key) {
        bs.reset(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bs.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
