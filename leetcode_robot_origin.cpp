class Solution {
public:
    bool judgeCircle(string moves){
    	int row=0,col=0;
    	for(int i=0;i<moves.length();i++){
    		if(moves[i]=='U'){
    			row=row-1;
    		}else if(moves[i]=='R'){
    			col=col+1;
    		}else if(moves[i]=='D'){
    			row=row+1;
    		}else if(moves[i]=='L'){
    			col=col-1;
    		}
    	}
    	if(row==0 and col==0){
    		return true;
    	}
    	return false;
    }
};