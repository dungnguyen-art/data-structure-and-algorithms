#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		int a,b;
		vector<int>ke[v+1];
		for(int i=1;i<=e;i++){
			cin>>a>>b;
			ke[a].push_back(b);
		}
		
		for(int i=1;i<=v;i++)
			sort(ke[i].begin(),ke[i].end());
		for(int i=1;i<=v;i++){
			cout<<i<<": ";
			for(int j=0;j<ke[i].size();j++)
				cout<<ke[i][j]<<" ";
			cout<<endl;
		}
	}
}