#include<stdio.h>
#include<vector>
#include<map>
#define to first
#define cost second
#define INF 200000000
using namespace std;
typedef pair<int,int> P;
int x[100];
int y[100];
int d[100][100];//直前がjのiまでの最短距離
vector<P> e[100];
int dis(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
bool sharp(int a,int b,int c){
	int p=dis(a,b);
	int q=dis(a,c);
	int r=dis(b,c);
	return p+q-r>0;
}
int min(int a,int b){return a<b?a:b;}
int main(){
	int n,m;
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
	for(i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		e[a].push_back(P(b,c));
		e[b].push_back(P(a,c));
	}
	for(i=0;i<n;i++)for(j=0;j<n;j++)d[i][j]=INF;
	d[0][0]=0;
	bool update=true;
	while(update){
		update=false;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<e[i].size();k++){
					P ed=e[i][k];
					if(ed.to==j)continue;
					if(!sharp(i,j,ed.to)){
						if(d[ed.to][i]>d[i][j]+ed.cost){
							update=true;
							d[ed.to][i]=d[i][j]+ed.cost;
						}
					}
				}
			}
		}
	}
	int ans=INF;
	for(i=0;i<n;i++)ans=min(ans,d[1][i]);
	if(ans==INF)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
