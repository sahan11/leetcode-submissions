class MyCircularDeque {
public:

    vector<int> arr;
    int front;
    int rear;
    int n;
    MyCircularDeque(int k) {
        arr.resize(k + 1, 0);
        front = 0;
        rear = 0;
        n = k + 1;
    }

    int incr(int ind) {
        return (ind + 1) % n;
    }
    int decr(int ind) {
        return (ind - 1 + n) % n;
    }
    
    bool insertFront(int value) {
        
        if(decr(front) == rear) return false;
        else {
            front = decr(front);
            arr[front] = value;
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(incr(rear) == front) return false;
        else {
            arr[rear] = value;
            rear = incr(rear);
            return true;
        }
    }
    
    bool deleteFront() {
        if(front == rear) return false;
        front = incr(front);
        return true;
    }
    
    bool deleteLast() {
        if(front == rear) return false;
        rear = decr(rear);
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[decr(rear)];
    }
    
    bool isEmpty() {
        return (front == rear);
    }
    
    bool isFull() {
        cout<<front<<' '<<rear<<'\n';
        return decr(front) == rear;
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