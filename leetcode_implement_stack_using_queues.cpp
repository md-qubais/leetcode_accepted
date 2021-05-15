class MyStack {
public:
    deque<int> q;
    MyStack() {
    }
    void push(int x) {
        q.push_back(x);
    }
    int pop() {
        int num=q.back();
        q.pop_back();
        return num;
    }
    int top() {
        return q.back();
    }
    bool empty() {
        return q.empty();
    }
};