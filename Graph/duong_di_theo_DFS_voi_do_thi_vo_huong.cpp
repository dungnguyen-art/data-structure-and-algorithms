#include <bits/stdc++.h>
using namespace std;

int v, e, nguon, dich;
vector<int> ke[10000];
bool chuaxet[10000];
int truoc[10000];

void DFS(int u,int v)
{
	// if(!chuaxet[v])
	// 	return;
	chuaxet[u] = false;
	for (int i = 0; i < ke[u].size(); i++)
		if (chuaxet[ke[u][i]]){
			truoc[ke[u][i]] = u;
			DFS(ke[u][i],v);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 1001; i++)
			ke[i].clear();
		memset(chuaxet, true, sizeof(chuaxet));
		memset(truoc,0,sizeof(truoc));

		// int v,e,u;
		cin >> v >> e >> nguon >> dich;
		// vector<int>ke[n+1];
		int x, y;
		for (int i = 1; i <= e; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		DFS(nguon,dich);
		int j=dich;
		int b[10000] ={0},k = 0;
		while(truoc[j] != nguon){
			b[k] = truoc[j];
			k++;
			j = truoc[j];
		}
		b[k]=nguon;
		k++;
		for(int i=k-1;i>=0;i--)
			cout<<b[i]<<" ";
		cout<<dich<<endl;
	}
}