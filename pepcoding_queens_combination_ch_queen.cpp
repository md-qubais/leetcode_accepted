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
bool chess[1000][1000];
void queen_combination_ch_queen(int n,int asf=0,int rows=0,int cols=0){
	if(asf==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(chess[i][j]){
					cout<<"q\t";
				}else{
					cout<<"-\t";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int j=cols;j<n;j++){
		chess[rows][j]=true;
		queen_combination_ch_queen(n,asf+1,rows,j+1);
		chess[rows][j]=false;
	}
	for(int i=rows+1;i<n;i++){
		for(int j=0;j<n;j++){
			chess[i][j]=true;
			queen_combination_ch_queen(n,asf+1,i,j+1);
			chess[i][j]=false;
		}
	}
}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	queen_combination_ch_queen(n);
	return 0;
}