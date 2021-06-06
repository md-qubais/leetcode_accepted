class Solution{
public:
    bool isToeplitzMatrix(vector<vector<int>>&mat){
    	for(int j=0;j<mat[0].size();j++){
    		int i=0;
    		int col=j;
    		int num=mat[i][col];
    		while(i<mat.size() and col<mat[0].size()){
    			if(num!=mat[i++][col++]){
    				return false;
    			}
    		}
    	}
    	for(int i=mat.size()-1;i>0;i--){
    		int j=0;
    		int row=i;
    		int num=mat[row][j];
    		while(row<mat.size() and j<mat[0].size()){
    			if(num!=mat[row++][j++]){
    				return false;
    			}
    		}
    	}
    	return true;
    }
};