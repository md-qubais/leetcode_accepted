class SnapshotArray {
public:
	unordered_map<int,list<pair<int,int>>> arr;
	int snap_c;
    SnapshotArray(int length) {
    	snap_c=0;
    }
    void set(int index, int val) {
    	arr[index].push_front({snap_c,val});
    }
    int snap() {
    	snap_c++;
    	return snap_c-1;
    }
    
    int get(int index, int snap_id){
    	int ans=0;
    	for(auto&it:arr[index]){
    		if(it.first==snap_id){
    			return it.second;
    		}
    	}
    	return ans;
    }
};
