/*
https://leetcode.com/problems/design-circular-deque/
*/
class MyCircularDeque {
private:
    vector<int> buffer;
    int len,front,rear;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        buffer.resize(k);
        len=0,front=k-1,rear=0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        buffer[front]=value;
        front=(front-1+buffer.size())%buffer.size();
        len++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        buffer[rear]=value;
        rear=(rear+1)%buffer.size();
        len++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%buffer.size();
        len--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear-1+buffer.size())%buffer.size();
        len--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(!isEmpty()) return buffer[(front+1)%buffer.size()];
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(!isEmpty()) return buffer[(rear-1+buffer.size())%buffer.size()];
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return len==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len==buffer.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
