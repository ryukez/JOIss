#include<stdio.h>
int m;
int num[10000];
int pow(int a,int p){
	int ans=1;
	int k=a;
	while(p>0){
		if(p&1)ans=(ans*k)%m;
		k=(k*k)%m;
		p/=2;
	}
	return ans;
}
int main(){
	int n;
	int i,j;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=0;i<m;i++)num[i]=0;
	for(i=0;i<m;i++)num[pow(i,n)]++;
	int ans=0;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			ans+=num[i]*num[j]*num[(i+j)%m];
		}
	}
	printf("%d\n",ans);
	return 0;
}
