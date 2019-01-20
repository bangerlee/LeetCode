/*
https://leetcode.com/problems/design-hashmap/
*/

/*
C++ using STL vector and STL  list

A small vector is used to keep the keys
A hash function is used
A link list is used to track collisions
*/
struct hashNode {
    std::list<pair<int, int>> _list;

    std::list<pair<int, int>>::iterator myFind(int key) {
        return std::find_if(
                _list.begin(), _list.end(),
                [key](pair<int, int> a) { return (a.first == key); });
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _v = vector<hashNode>(_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = hash(key);
        auto it = _v[k].myFind(key);
        if (it == _v[k]._list.end()) {
            _v[k]._list.push_back(make_pair(key, value));
        } else {
            it->second = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if
     * this map contains no mapping for the key */
    int get(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it == _v[k]._list.end()) {
            return -1;
        } else {
            return it->second;
        }
    }

    /** Removes the mapping of the specified value key if this map
     * contains a mapping for the key */
    void remove(int key) {
        int k = hash(key);
        auto it = _v[k].myFind(key);

        if (it != _v[k]._list.end()) {
            _v[k]._list.erase(it);
        }
    }

    int hash(int key) {
        return key % _size;
    }


    std::vector<hashNode> _v;
    int _size = 100;
};
