/******************************************************************************
* Sample solution for the Bridging signals problem in NWERC'03
* Author: Andreas Bj�rklund
******************************************************************************/
#include <stdio.h>

#define MAX_NBR (40010)
#define MAX_LOG (16)

static int dyn[MAX_NBR];

int main(void)
{
	int i,j,n,m,d,largest,step,pos;
    scanf("%d",&m);
    largest=0;
    dyn[0]=0;
    for (j=0;j<m;j++)
    {
        scanf("%d",&d);
        // Binary search:
        pos=1<<MAX_LOG;
        step=1<<(MAX_LOG-1);
        while (step)
        {
            if (pos>largest || dyn[pos]>d) pos-=step; else pos+=step;
            step>>=1;
        }
        if (pos>largest || dyn[pos]>d) pos--;
        dyn[++pos]=d;
        if (pos>largest) largest++;
    }
    printf("%d<<\n",largest);
			
	return 0;
}