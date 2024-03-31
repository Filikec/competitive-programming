#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=0x7fffffff>>1;
typedef struct node1
{
    int u,v,c,bk,next;
    bool flg;
}Edge;
Edge g[50001];int tp=0;
int hd[11001],d[11001],dt[11001],vd[11001],pre[11001],de[11001];
int S,T,N;
long long res[7501],resTaken[2501];
int n;
long long a[2501],b[2501];
void ine(int u,int v,int c)
{
    g[tp].u=u,g[tp].v=v,g[tp].c=c,g[tp].flg=1;
    g[tp].bk=tp+1,g[tp].next=hd[u],hd[u]=tp++;
    g[tp].u=v,g[tp].v=u,g[tp].c=0,g[tp].flg=0;
    g[tp].bk=tp-1,g[tp].next=hd[v],hd[v]=tp++;
}
void SAP(int &maxf)
{
    memset(d,0,sizeof(d));
    memset(vd,0,sizeof(vd));
    memset(dt,0,sizeof(dt));
    memset(pre,0,sizeof(pre));
    memcpy(de,hd,sizeof(hd));
    int i,now;
    vd[0]=N;
    dt[S]=INF;
    i=S;
    while (d[S]<N)
      {
          for (now=de[i];now>=0;now=g[now].next)
            if (g[now].c>0 && d[i]==d[g[now].v]+1)
              break;
          de[i]=now;
          if (now>=0)
            {
               pre[g[now].v]=now,dt[g[now].v]=min(g[now].c,dt[i]);
               i=g[now].v;
               if (i==T)
                 {
                   maxf+=dt[T];
                   for (;i!=S;i=g[pre[i]].u)
                     g[pre[i]].c-=dt[T],g[g[pre[i]].bk].c+=dt[T];
                   dt[S]=INF;
                 }
            }
          else
            {
                 vd[d[i]]--;
                 if (vd[d[i]]==0)break;
                 de[i]=hd[i],d[i]=N;
                 for (now=de[i];now>=0;now=g[now].next)
                   if (g[now].c>0 && d[i]>d[g[now].v]+1)
                     d[i]=d[g[now].v]+1;
                 vd[d[i]]++;
                 if (i!=S)i=g[pre[i]].u;
            }
      }
}
int findIt(long long x)
{
    int left=1,right=3*n,mid;
    while (left<right)
      {
          mid=(left+right)>>1;
          if (res[mid]==x)return mid;
          if (x < res[mid])right=mid-1;
          else left=mid+1;
      }
    return left;
}
void init()
{
    cin>>n;
    for (int i=1;i<=n;i++)
      {
          scanf("%lld%lld",a+i,b+i);
          res[3*i-2]=a[i]+b[i];
          res[3*i-1]=a[i]-b[i];
          res[3*i]=a[i]*b[i];
      }
    S=n+3*n+1, T=n+3*n+2, N=n+3*n+2;
    memset(hd,255,sizeof(hd));
    sort(res+1,res+1+3*n);
    for (int i=1;i<=n;i++)
      {
          ine(S,i,1);
          ine(i,n+findIt(a[i]+b[i]),1);
          ine(i,n+findIt(a[i]-b[i]),1);
          ine(i,n+findIt(a[i]*b[i]),1);
          ine(n+3*i-2,T,1);
          ine(n+3*i-1,T,1);
          ine(n+3*i,T,1);
      }
}

void work()
{
     int maxf=0;
     SAP(maxf);
     if (maxf!=n)puts("impossible");
     else
     {
         for (int i=0;i<tp;i++)
           if (g[i].flg && g[i].u>=1 && g[i].u<=n && g[i].c==0)
             resTaken[g[i].u]=res[g[i].v-n];
         char opt;
         for (int i=1;i<=n;i++)
           {
               if (a[i]+b[i]==resTaken[i])opt='+';
               else if (a[i]-b[i]==resTaken[i])opt='-';
               else opt='*';
               printf("%lld %c %lld = %lld\n", a[i], opt, b[i], resTaken[i]);
           }
     }
}

int main(void)
{
    init();
    work();
    return 0;
}