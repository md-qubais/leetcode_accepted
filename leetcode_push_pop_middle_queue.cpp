class FrontMiddleBackQueue {
public:
    deque<int> left,right;
    FrontMiddleBackQueue(){        
    }

    void pushFront(int val){
        left.push_front(val);
        if(left.size()-right.size()>=2){
            int num=left.back();
            left.pop_back();
            right.push_front(num);
        }
    }
    
    void pushMiddle(int val) {
        if(left.size()==right.size()){
            left.push_back(val);
        }else if(left.size()>right.size()){
            int num=left.back();
            left.pop_back();
            left.push_back(val);
            right.push_front(num);
            if(left.size()-right.size()>=2){
                right.push_front(left.back());
                left.pop_back();
            }else if(right.size()-left.size()>=2){
                left.push_back(right.front());
                right.pop_front();
            }
        }else if(right.size()>left.size()){
            left.push_back(val);
            if(left.size()-right.size()>=2){
                right.push_front(left.back());
                left.pop_back();
            }else if(right.size()-left.size()>=2){
                left.push_back(right.front());
                right.pop_front();
            }
        }
    }
    
    void pushBack(int val) {
        right.push_back(val);
        if(right.size()-left.size()>=2){
            int num=right.front();
            right.pop_front();
            left.push_back(num);
        }
    }
    
    int popFront(){
        if(left.size()==0 and right.size()==0){
            return -1;
        }
        if(left.size()>0 and right.size()==0){
            int num=left.front();
            left.pop_front();
            return num;
        }
        if(right.size()>0 and left.size()==0){
            int num=right.front();
            right.pop_front();
            return num;
        }
        int num=left.front();
        left.pop_front();
        int number=left.size()-right.size();
        if(number>=2){
            right.push_front(left.back());
            left.pop_back();
        }else if(right.size()-left.size()>=2){
            left.push_back(right.front());
            right.pop_front();
        }
        return num;
    }
    
    int popMiddle(){
        if(left.size()==0 and right.size()==0){
            return -1;
        }
        if(right.size()>left.size()){
            int num=right.front();
            right.pop_front();
            return num;
        }
        int num=left.back();
        left.pop_back();
        return num;
    }
    
    int popBack(){
        if(left.size()==0 and right.size()==0){
            return -1;
        }
        if(left.size()>0 and right.size()==0){
            int num=left.back();
            left.pop_back();
            return num;
        }
        if(right.size()>0 and left.size()==0){
            int num=right.back();
            right.pop_back();
            return num;
        }
        int num=right.back();
        right.pop_back();
        if(left.size()-right.size()>=2){
            right.push_front(left.back());
            left.pop_back();
        }else if(right.size()-left.size()>=2){
            left.push_back(right.front());
            right.pop_front();
        }
        return num;
    }
};
