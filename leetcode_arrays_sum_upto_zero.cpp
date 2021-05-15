class Solution {
public:
    vector<int> sumZero(int n){
    	deque<int> q;
    	if(n%2!=0){
    		q.push_back(0);
    	}
    	int i=1;
    	while(q.size()<n){
    		q.push_back(i);
    		q.push_front(-i);
    		i++;
    	}
    	vector<int> ans;
    	while(!q.empty()){
    		ans.push_back(q.front());
    		q.pop_front();
    	}
    	return ans;
    }
};