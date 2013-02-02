#include<stdio.h>
#include<vector>
using namespace std;
vector<int> ans;
int bit[101][101];//不明なマスの数
int t[100][100];
int x1[1000];
int y1[1000];
int x2[1000];
int y2[1000];
int num[1000];
bool used[1000];
int w,h;
void add2(int x,int y){
	while(y<=w){
		bit[x][y]++;
		y+=y&-y;
	}
}
int sum2(int x,int y){
	int s=0;
	while(y>0){
		s+=bit[x][y];
		y-=y&-y;
	}
	return s;
}
void add(int x,int y){
	x++;y++;
	while(x<=h){
		add2(x,y);
		x+=x&-x;
	}
}
int sum(int x,int y){
	x++;y++;
	int s=0;
	while(x>0){
		s+=sum2(x,y);
		x-=x&-x;
	}
	return s;
}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int main(){
	int n;
	int i,j;
	scanf("%d %d %d",&n,&w,&h);
	for(i=0;i<=h;i++)for(j=0;j<=w;j++)bit[i][j]=0;
	for(i=0;i<n;i++){
		x1[i]=h;
		y1[i]=w;
		x2[i]=0;
		y2[i]=0;
		num[i]=0;
		used[i]=false;
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			int p;
			scanf("%d",&p);
			t[i][j]=p;
			p--;
			num[p]++;
			x1[p]=min(x1[p],i);
			y1[p]=min(y1[p],j);
			x2[p]=max(x1[p],i);
			y2[p]=max(y2[p],j);	
		}
	}
	while(1){
		for(i=0;i<n;i++){
			if(used[i])continue;
			int p=sum(x2[i],y2[i])-sum(x1[i]-1,y2[i])-sum(x2[i],y1[i]-1)+sum(x1[i]-1,y1[i]-1);
			if(num[i]+p==(x2[i]-x1[i]+1)*(y2[i]-y1[i]+1))break;
		}
		if(i==n)break;
		int p=i;
		used[i]=true;
		ans.push_back(i);
		for(i=x1[i];i<=x2[i];i++){
			for(j=y1[i];j<=y2[i];j++){
				if(t[i][j]==p){
					t[i][j]=-1;
					add(i,j);
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(!used[i])printf("%d ",i+1);
	}
	for(i=ans.size()-1;i>=0;i--){
		printf("%d",ans[i]+1);
		if(i!=0)printf(" ");
	}
	printf("\n");
	return 0;
}
