class Solution {
public:
    int lastStoneWeight(vector<int>& stones){
    	priority_queue<int> pq;
    	for(auto&it:stones){
    		pq.push(it);
    	}
    	while(pq.size()>1){
    		int n1=pq.top();
    		pq.pop();
    		int n2=pq.top();
    		pq.pop();
    		if(n1==n2){
    			continue;
    		}else{
    			int max1=max(n1,n2);
    			int max2=min(n1,n2);
    			max1=max1-max2;
    			pq.push(max1);
    		}
    	}
    	return pq.size()>0?pq.top():0;
    }
};