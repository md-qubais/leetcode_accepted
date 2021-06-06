#define Minheap priority_queue<int,vector<int>,greater<int>>
class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
    	Minheap pq;
    	int i=0;
    	while(i<k){
    		pq.push(nums[i++]);
    	}
    	while(i<nums.size()){
    		if(nums[i]>pq.top()){
    			pq.pop();
    			pq.push(nums[i]);
    		}
    		i++;
    	}
    	return pq.top();
    }
};