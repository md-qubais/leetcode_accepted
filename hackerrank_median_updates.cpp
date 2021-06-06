#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
void median(vector<char> s,vector<int> arr){
	Maxheap left;
	Minheap right;
	for(int i=0;i<s.length();i++){
		if(s[i]=='r'){

		}else{
			if(left.size()==0){
				left.push(arr[i]);
				cout<<left.top()<<endl;
				continue;
			}
			if(left.size()-right.size()>=2){
				
			}
		}
	}
}