class Solution{
public:
    bool isPerfectSquare(int num){
    	if(num==1){
    		return true;
    	}
    	long long int s=1;
    	long long int e=num/2;
    	while(s<=e){
    		long long int mid=s+(e-s)/2;
    		if(mid*mid==num){
    			return true;
    		}
    		if(mid*mid<num){
    			s=mid+1;
    		}else{
    			e=mid-1;
    		}
    	}
    	return false;
    }
};