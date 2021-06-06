class Solution{
public:
	unordered_map<int,bool> mark;
	int ans=0;
    int countNumbersWithUniqueDigits(int n,int asf=0,int size=0){
    	if(size>n){
    		return ans;
    	}
    	ans++;
    	for(int i=0;i<=9;i++){
    		if((asf==0 and i==0) or mark[i]){
    			continue;
    		}
    		mark[i]=true;
    		countNumbersWithUniqueDigits(n,asf*10+i,size+1);
    		mark[i]=false;
    	}
    	return ans;
    }
};