#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
class MedianFinder {
public:

    Maxheap left;
    Minheap right;
    
    MedianFinder(){
    }

    void addNum(int num){
        if(left.empty()){
            left.push(num);
            return;
        }
        if(left.top()<num) right.push(num);
        else left.push(num);
        int size=(left.size())-(right.size());
        if(size>1){
            right.push(left.top());
            left.pop();
            return;
        }
        size=(right.size())-(left.size());
         if(size>1){
            left.push(right.top());
            right.pop();
            return;
        }
        return;
    }

    double findMedian() {
        if(left.size()==right.size()){
            return ((double)(left.top())+(double)(right.top()))/(double)2;
        }
        if(left.size()>right.size()){
            return (double)(left.top());
        }
        return (double)(right.top());
    }

};
