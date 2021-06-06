class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    FrontMiddleBackQueue() {        
    }
    
    void pushFront(int val){
        left.push_front(val);
        if(left.size()-right.size()>=2){
            right.push_front(left.back());
            left.pop_back();
        }
    }
    
    void pushMiddle(int val) {
    }
    
    void pushBack(int val) {
        right.push_back(val);
        if(right.size()-left.size()>=2){
            left.push_back(right.front());
            right.pop_front();
        }
    }
    
    int popFront(){
    
    }
    
    int popMiddle(){
        
    }
    
    int popBack(){

    }
};
