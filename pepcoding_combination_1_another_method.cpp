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
void print_combination(char *ch,int n,int num,int k,int i=0){
	if(num>k){
		for(int i=0;i<n;i++){
			cout<<ch[i];
		}
		cout<<endl;
		return;
	}
	for(int box=i;box<n;box++){
		if(ch[box]=='-'){
			ch[box]='i';
			print_combination(ch,n,num+1,k,box+1);
			ch[box]='-';
		}
	}
}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int k;
	cin>>k;
	char ch[n];
	for(int i=0;i<n;i++){
		ch[i]='-';
	}
	print_combination(ch,n,1,k);
	return 0;
}