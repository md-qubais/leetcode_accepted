#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
class Median{
public:
	Maxheap left;
	Minheap right;
	Median(){
	}
	void add(int val){
		if(left.empty()){
			left.push(val);
			return;
		}
		if(!right.empty() and val>right.top()){
			right.push(val);
		}
		else{
			left.push(val);
		}
		if(left.size()-right.size()==2){
			right.push(left.top());
			left.pop();
			return;
		}
		if(right.size()-left.size()==2){
			left.push(right.top());
			right.pop();
			return;
		}
	}
	double peek(){
		if(left.size()==right.size()){
			return ((double)left.top()+(double)right.top())/(double)2;
		}else if(left.size()>right.size()){
			return (double)left.top();
		}
		return (double)right.top();
	}
};

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    	Median m;
    	int i=0,j=0;
    	while(i<nums1.size() and j<nums2.size()){
    		if(nums1[i]<nums2[j]){
    			m.add(nums1[i++]);
    		}else{
    			m.add(nums2[j++]);
    		}
    	}
    	while(i<nums1.size()){
    		m.add(nums1[i++]);
    	}
    	while(j<nums2.size()){
    		m.add(nums2[j++]);
    	}
    	return m.peek();
    }
};
