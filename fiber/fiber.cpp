#include<stdio.h>
#include<vector>
using namespace std;
bool used[10000];
vector<int> e[10000];
void dfs(int v){
	used[v]=true;
	for(int i=0;i<e[v].size();i++){
		if(!used[e[v][i]])dfs(e[v][i]);
	}
}
int main(){
	int n,m;
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(i=0;i<n;i++)used[i]=false;
	int ans=0;
	for(i=0;i<n;i++){
		if(!used[i]){
			ans++;
			dfs(i);
		}
	}
	printf("%d\n",ans-1);
}
