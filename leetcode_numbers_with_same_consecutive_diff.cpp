class Solution{
public:
	void numsSameConsecDiff(int n, int k,int size,vector<int>&ans,int num=0){
    	if(size==n){
    		ans.push_back(num);
    		return;
    	}
    	if(num==0){
    		for(int start=1;start<=9;start++){
    			numsSameConsecDiff(n,k,size+1,ans,start);
    		}
    		return;
    	}
    	for(int start=0;start<=9;start++){
    		int last=num%10;
    		if(abs(last-start)==k){
    			numsSameConsecDiff(n,k,size+1,ans,num*10+start);
    		}
    	}
    }
    vector<int> numsSameConsecDiff(int n, int k){
    	vector<int> ans;
    	numsSameConsecDiff(n,k,0,ans);
    	return ans;
    }
};