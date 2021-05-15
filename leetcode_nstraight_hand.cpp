class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize){
    	map<int,int> m;
    	for(auto&it:hand){
    		m[it]++;
    	}
    	int size=0;
    	int n=groupSize;
    	while(m.size()>0){
    		for(auto&it:m){
    			if(m[it.first]==0){
    				m.erase(it.first);
    				continue;
    			}
    			m[it.first]--;
    			size++;
    			if(size==n){
    				groupSize--;
    				break;
    			}
    		}
    		if(size!=n){
    			return false;
    		}
    		if(groupSize==0){
    			break;
    		}
    	}
    	if(groupSize==0){
    		return true;
    	}
    	return false;
    }
};