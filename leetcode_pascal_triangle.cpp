class Solution {
public:
    vector<int> getRow(int k){
    	k=k+1;
    	k--;
    	int num=k;
    	vector<vector<int>> ans;
    	vector<int> temp;
    	temp.push_back(1);
    	ans.push_back(temp);
    	while(k--){
    		vector<int> temp1=ans[ans.size()-1];
    		vector<int> temp2;
    		temp2.push_back(temp1[0]);
    		for(int i=0;i<temp1.size()-1;i++){
    			temp2.push_back(temp1[i]+temp1[i+1]);
    		}
    		temp2.push_back(temp1[temp1.size()-1]);
    		ans.push_back(temp2);
    	}
    	return ans[num];
    }
};
