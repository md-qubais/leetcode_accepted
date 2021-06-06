// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int e,int s=1){
    	int mid= s + ((e - s) / 2);
    	while(s<=e){
    		mid=s + ((e - s) / 2);
    		if(s==e){
    			break;
    		}
    		if(isBadVersion(mid)){
    			e=mid;
    		}else{
    			s=mid+1;
    		}
    	}
    	return mid;
    }
};