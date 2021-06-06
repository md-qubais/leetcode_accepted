class CombinationIterator {
public:
	vector<string> combinations;
	int it;
	void generate_combinations(string s,int length,string temp="",int i=0){
		
		if(i==s.length()){
			if(temp.length()==length){
				combinations.push_back(temp);
			}
			return;
		}
		if(temp.length()==length){
			combinations.push_back(temp);
			return;
		}
		generate_combinations(s,length,temp+s[i],i+1);
		generate_combinations(s,length,temp,i+1);
	}
    CombinationIterator(string characters, int combinationLength){
    	it=0;
    	generate_combinations(characters,combinationLength);
    }
    
    string next(){
    	return combinations[it++];
    }
    
    bool hasNext() {
        if(it==combinations.size()){
        	return false;
        }
        return true;
    }
};
