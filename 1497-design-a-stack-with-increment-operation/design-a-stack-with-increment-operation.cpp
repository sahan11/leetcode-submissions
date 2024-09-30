class CustomStack {
public:

    vector<int> arr;
    int n;
    int top;

    CustomStack(int maxSize) {
        n = maxSize;
        arr.resize(n, 0);    
        top = -1;
    }
    
    void push(int x) {
        if(top == n - 1) return;
        else arr[++top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        else return arr[top--];
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < k && i <= top;i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */