class Solution {
public:
    bool checkPowersOfThree(int n,int i=0,int asf=0){
    	if(asf==n){
    		return true;
    	}
    	for(int j=i;j<=16;j++){
    		if(checkPowersOfThree(n,j+1,asf+pow(3,j))){
    			return true;
    		}
    	}
    	return false;
    }
};