class Solution {
public:
    int totalMoney(int n){
    	int sum=0;
    	int monday=1;
    	int add=monday;
    	for(int i=1;i<=n;i++){
    		sum+=add;
    		add++;
    		if(i%7==0){
    			monday++;
    			add=monday;
    		}
    	}
    	return sum;
    }
};