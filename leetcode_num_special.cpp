class Solution {
public:
    int numSpecial(vector<vector<int>>& mat){
    	vector<int> rows(mat.size(),0);
    	vector<int> cols(mat[0].size(),0);
    	int ans=0;
    	for(int i=0;i<mat.size();i++){
    		for(int j=0;j<mat[i].size();j++){
    			if(mat[i][j]==1){
    				rows[i]++;
    				cols[j]++;
    			}
    		}
    	}
    	for(int i=0;i<mat.size();i++){
    		for(int j=0;j<mat[i].size();j++){
    			if(mat[i][j]==1 and rows[i]==0 and cols[j]==0){
    				ans++;
    			}
    		}
    	}
    	return ans;
    }
};