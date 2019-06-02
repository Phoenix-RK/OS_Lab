//kiruthya
//cpu scheduling
//preemptive shortest job first
#include<stdio.h>
int main()
{
	int at[10],bt[10],temp[10],i,j,count,n,time,small;
	float awt,atat,wt=0,tat=0,end;
	printf("\nenter the no of processes:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nenter the arrival time and burst time:");
		scanf("%d%d",&at[i],&bt[i]);
		temp[i]=bt[i];
	}
	bt[9]=9999;
	for(time=0;count!=n;time++)
	{
		small=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]<bt[small] &&bt[i]>0)
				small=i;
		}
		bt[small]--;
		if(bt[small]==0)
		{
			count++;
			end=time+1;
			wt+=end-at[small]-temp[small];
			tat+=end-at[small];
		}
	}
	awt=wt/n;
	atat=tat/n;
	printf("\nawt=%lf",awt);
	printf("\natat=%lf",atat);
	return 0;
}
