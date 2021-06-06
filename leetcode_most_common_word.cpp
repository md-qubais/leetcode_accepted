class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned){
    	paragraph+=" ";
    	vector<string> strings;
    	string temp="";
    	for(int i=0;i<paragraph.length();i++){
            if(paragraph[i]==' ' or paragraph[i]=='!' or paragraph[i]=='?' or paragraph[i]=='\'' or paragraph[i]==',' or paragraph[i]==';' or paragraph[i]=='.'){
    			if(temp.size()>0 ){
    				strings.push_back(temp);
    			}
    			temp="";
    			continue;
    		}
            if(paragraph[i]>='A' and paragraph[i]<='Z'){
                paragraph[i]+=32;
            }
    		temp+=paragraph[i];
    	}
    	unordered_map<string,bool> ban;
    	for(auto&it:banned){
    		ban[it]=true;
    	}
    	unordered_map<string,int> count;
    	for(auto&it:strings){
    		if(!ban[it]){
    			count[it]++;
    		}
    	}
    	int Max=0;
    	string ans="";
    	for(auto&it:count){
    		if(count[it.first]>Max){
    			Max=count[it.first];
    			ans=it.first;
    		}
    	}
    	return ans;
    }
};