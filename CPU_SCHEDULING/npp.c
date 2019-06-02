//kiruthya
//cpu scheduling
//non preemptive priority
#include<stdio.h>
int main()
{
	int at[10],p[10],bt[10],small,temp[10],i,j,n,remain,time;
	int wt=0,tat=0;
	float awt,atat;
	printf("\nenter the no of processes:");
	scanf("%d",&n);
	remain=n;
	for(i=0;i<n;i++)
	{
		printf("\nenter the arr time,burst time,priority:");
		scanf("%d%d%d",&at[i],&bt[i],&p[i]);
	}
	p[9]=11;
	for(time=0;remain!=0;)
	{
		small=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time  && p[i]<p[small] && p[i]>0)
				small=i;
		}
		time+=bt[small];
		remain--;
		printf("\n%d\t%d\t%d",small+1,time-at[small]-bt[small],time-at[small]);


		wt+=time-at[small]-bt[small];
		tat+=time-at[small];
		bt[small]=0;
	}
	awt=wt*1.0/n;
	atat=tat*1.0/n;
	printf("\nawt=%lf\natat=%lf",awt,atat);
}
