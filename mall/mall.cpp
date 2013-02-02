#include<stdio.h>
int t[1000][1000];
int sum[1000][1000];
int ssum[1000][1000];
int min(int a,int b){return a<b?a:b;}
int main(){
	int w,h;
	int a,b;
	int i,j;
	scanf("%d %d",&w,&h);
	scanf("%d %d",&a,&b);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++)scanf("%d",&t[i][j]);
	}
	for(i=0;i<h;i++){
		int s=0;
		int c=0;
		for(j=0;j<w;j++){
			if(t[i][j]==-1)c++;
			else s+=t[i][j];
			if(j>=a){
				if(t[i][j-a]==-1)c--;
				else s-=t[i][j-a];
			}
			if(j>=a-1){
				if(c>0)sum[i][j-a+1]=-1;
				else sum[i][j-a+1]=s;
			}
		}
	}
	for(i=0;i<w-a+1;i++){
		int s=0;
		int c=0;
		for(j=0;j<h;j++){
			if(sum[j][i]==-1)c++;
			else s+=sum[j][i];
			if(j>=b){
				if(sum[j-b][i]==-1)c--;
				else s-=sum[j-b][i];
			}
			if(j>=b-1){
				if(c>0)ssum[j-b+1][i]=-1;
				else ssum[j-b+1][i]=s;
			}
		}
	}
	int ans=1000000000;
	for(i=0;i<h-b+1;i++){
		for(j=0;j<w-a+1;j++)if(ssum[i][j]!=-1)ans=min(ans,ssum[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
