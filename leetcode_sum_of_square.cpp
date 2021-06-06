class Solution{
public:
    bool judgeSquareSum(int n) {
        if(n==0 or n==1 or n==2){
        	return true;
        }
        long long int root=sqrt(n);
        long long int s=0;
        long long int e=root;
        while(s<=e){
        	long long int mid=s*s+e*e;
        	if(mid==n){
        		return true;
        	}
        	if(mid<n){
        		s++;
        	}else{
        		e--;
        	}
        }
        return false;
    }
};