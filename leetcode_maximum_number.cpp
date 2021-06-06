class Solution{
public:
    int maximum69Number (int num){
    	string number="";
    	number+=to_string(num);
    	int ans=0;
    	stringstream str(number);
    	int n;
    	str>>n;
        ans=max(ans,n);		
    	for(int i=0;i<number.length();i++){
    		if(number[i]=='6'){
    			number[i]='9';
    			stringstream str(number);
    			int n;
    			str>>n;
    			ans=max(ans,n);
    			number[i]='6';
    		}else{
    			number[i]='6';
    			stringstream str(number);
    			int n;
    			str>>n;
    			ans=max(ans,n);
    			number[i]='9';
    		}
    	}
    	return ans;
    }
};