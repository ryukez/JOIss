#include<stdio.h>
#include<vector>
using namespace std;
int dp[100001];//vを頂点とする木の最大値
int p[100001];
vector<int> e[100000];
int max(int a,int b){return a>b?a:b;}
int main(){
	int n;
	int i,j;
	scanf("%d",&n);
	p[0]=0;
	for(i=1;i<=n;i++){
		int pr;
		scanf("%d %d",&pr,&p[i]);
		e[pr].push_back(i);
	}
	for(i=n;i>=0;i--){
		int res=0;
		for(j=0;j<e[i].size();j++){
			if(dp[e[i][j]]>0)res+=dp[e[i][j]];
		}
		dp[i]=res+p[i];
	}
	int ans=-100000000;
	for(i=0;i<=n;i++){
		if(i==0&&p[0]==0)continue;
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
