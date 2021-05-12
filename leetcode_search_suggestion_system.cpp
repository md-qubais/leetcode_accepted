class node{
public:
	char ch;
	vector<string> arr;
	map<char,node*> childs;
	node(char ch){
		this->ch=ch;
	}
};
class trie{
public:
	
	node*root;
	
	trie(){
		root=new node('\0');
	}

	void insert(string s){
		node*temp=root;
		for(int i=0;i<s.length();i++){
			if(temp->childs.count(s[i])!=0){
				//it exists;
				temp=temp->childs[s[i]];
				if(temp->arr.size()<3) temp->arr.push_back(s);
			}else{
				temp->childs[s[i]]=new node(s[i]);
				temp=temp->childs[s[i]];
				if(temp->arr.size()<3) temp->arr.push_back(s);
			}
		}
	}

	void search(string s,vector<vector<string>>&ans){
		node*temp=root;
		for(int i=0;i<s.length();i++){
			if(temp->childs.count(s[i])!=0){
				temp=temp->childs[s[i]];
				ans[i]=(temp->arr);
			}else{
				break;
			}
		}
	}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
    	trie t;
    	sort(begin(products),end(products));
    	vector<vector<string>> ans(searchWord.length());
    	for(auto&it:products){
    		t.insert(it);
    	}
    	t.search(searchWord,ans);
    	return ans;
    }
};