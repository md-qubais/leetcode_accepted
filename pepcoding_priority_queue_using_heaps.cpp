#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

class PriorityQueue{
public:
	int idx;
	int curr_size=0;
	vector<int> arr;
	
	PriorityQueue(){
		arr.resize(10000);
		arr[0]=-1;
		idx=1;
	}
	
	void add(int n){
		curr_size++;
		int i=idx;
		arr[i]=n;
		while(i>1){
			if(arr[i]<arr[i/2]){
				swap(arr[i],arr[i/2]);
				i=i/2;
				continue;
			}
			break;
		}
		idx++;
	}
	
	int peek(){
		if(curr_size==0){
			cout<<"Underflow"<<endl;
			return -1;
		}
		return arr[1];
	}
	
	int size(){
		return curr_size;
	}
	
	void down_heapify(int parent,int idx){
		int min_idx=parent;
		if(parent*2<idx and arr[min_idx]>arr[parent*2]){
			min_idx=min_idx*2;
		}
		if(parent*2+1<idx and arr[min_idx]>arr[parent*2+1]){
			min_idx=parent*2+1;
		}
		if(min_idx!=parent){
			swap(arr[min_idx],arr[parent]);
			down_heapify(min_idx,idx);
		}
	}

	int pop(){
		if(curr_size==0){
			cout<<"Underflow"<<endl;
			return -1;
		}
		int num=arr[1];
		idx--;
		swap(arr[1],arr[idx]);
		curr_size--;
		down_heapify(1,idx);
		return num; 
	}
};

int32_t main(){
	qubais_judge;
	IOS;
	PriorityQueue pq;
	while(true){
		string s;
		cin>>s;
		if(s=="quit"){
			break;
		}
		if(s=="add"){
			int n;
			cin>>n;
			pq.add(n);
			continue;
		}
		if(s=="peek"){
			int n=pq.peek();
			if(n==-1){
				continue;
			}
			cout<<n<<endl;
			continue;
		}
		if(s=="remove"){
			int n=pq.pop();
			if(n==-1){
				continue;
			}
			cout<<n<<endl;
			continue;
		}
		if(s=="size"){
			cout<<pq.size()<<endl;
			continue;
		}
	}
	return 0;
}