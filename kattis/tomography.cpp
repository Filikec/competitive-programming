#include<bits/stdc++.h>
#define maxn 3000000 
using namespace std;
 
struct Edge
{
   int to,w,next;
}edge[maxn];
 
int n,m,s,t;
int head[maxn],gap[maxn],h[maxn],cur[maxn];
 
int cnt=0;
 
void add(int a,int b,int c)
{
   edge[cnt].w=c;
   edge[cnt].to=b;
   edge[cnt].next=head[a];
   head[a]=cnt++;
}
 
int  isap(int x,int fr)
{
    if(x==t)
       return fr;
    int rest=0;
    for(int i=cur[x];~i;i=edge[i].next)
    {
	    int j=edge[i].to;
	    if(h[j]+1==h[x]&&edge[i].w)//!
	     {
		    int f=isap(j,min(edge[i].w,fr-rest));
		    edge[i].w-=f;
		    edge[i^1].w+=f;
		    rest+=f;
		    if(rest==fr)  return fr;
		    if(edge[i].w) cur[x]=i;
		 }
	}
	--gap[h[x]];
	if(!gap[h[x]]) h[s]=n+2;//！ 
	h [x] ++; gap [h [x]] ++; // carry out the label
	cur[x]=head[x];
	return rest; 
}

int R[1000],C[1000];

int main(){
    int m,n;

    memset (head,-1,sizeof (head));

    cin >> m >> n;


    int sum = 0;

    set<pair<int,int>> org;
    for (int i=0;i<m;i++) cin >> R[i], add(0,1+i,R[i]), sum += R[i], org.insert({0,1+i});
    for (int i=0;i<n;i++) cin >> C[i], add(m+1+i,m+n+1,C[i]), sum += C[i], org.insert({m+1+i,m+n+1});

    for (int i=1;i<=m;i++){
        for (int j=m+1;j<m+n+1;j++){
            add(i,j,1);
        }
    }
    
    cout << isap(0,m+n+1) << '\n';
    
    for (auto a : g.adj){
      for (auto e : a){
        if (org.count({e.src,e.dst}))
        if (e.cap-e.flow){
          cout << "No\n";
          return 0;
        }
      }
    }
    cout << "Yes\n";

}