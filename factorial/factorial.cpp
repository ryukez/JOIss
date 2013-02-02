#include<stdio.h>
#include<string.h>
int max(int a,int b){return a>b?a:b;}

int calc(int a,int p){
	int ans=0;
	while(a>0){
		ans+=a;
		a/=p;
	}
	return ans;
}
int main(){
	int n;
	int i,j;
	scanf("%d",&n);
	int m=1;
	for(i=2;i*i<=n;i++){
		int count=0;
		while(n%i==0){
			count++;
			n/=i;
		}
		int res=calc(count,i);
		res=count-(res-count);
		while(calc(res,i)<count)res++;
		m=max(m,res*i);
	}
	m=max(m,n);
	printf("%d\n",m);
}
		
