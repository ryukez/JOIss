#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<char,int> P;
string s;
long long fact[20];
long long calc(int p,map<char,int> c){
	long long ans=fact[s.size()-p-2];
	map<char,int>::iterator it;
	for(it=c.begin();it!=c.end();it++){
		P pr=*it;
		if(pr.second==0)continue;
		ans/=fact[pr.second-1];
	}
	return ans;
}
long long dfs(int p,map<char,int> c){
	if(p==s.size()-1)return 1;
	long long res=0;
	map<char,int>::iterator it;
	for(it=c.begin();it!=c.end();it++){
		P pr=*it;
		if(pr.first>=s[p]||pr.second==0)continue;
		c[pr.first]--;
		res+=calc(p,c);
		c[pr.first]++;
	}
	c[s[p]]--;
	return res+dfs(p+1,c);
}
int main(){
	fact[0]=1;
	for(int i=1;i<20;i++)fact[i]=fact[i-1]*(i+1);
	cin >> s;
	map<char,int> c;
	for(int i=0;i<s.size();i++)c[s[i]]++;
	printf("%lld\n",dfs(0,c));
	return 0;
}
