//kiruthya
//cpu scheduling
//non preemptive shortest job first
#include<stdio.h>
int main()
{
	int at[10],bt[10],temp[10],remain,n,time=0,i,j,small;
	float wt=0,tat=0,avwt,avtat;
	printf("\nenter the no of processess:");
	scanf("%d",&n);
	remain=n;
	for(i=0;i<n;i++)
	{
		printf("\nenter the arrival time and burst time:");
		scanf("%d%d",&at[i],&bt[i]);
		temp[i]=bt[i];
	}
	bt[9]=9999;
	printf("\nprocess\twt\ttat");
	for(time=0;remain!=0;)
	{
		small=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]< bt[small] && bt[i]>0)
			{
				small=i;
			}
		}
		remain--;
		time+=bt[small];

		printf("\n%d\t%d\t%d",small+1,time-at[small]-bt[small],time-at[small]);
		wt+=time-at[small]-bt[small];
		tat+=time-at[small];
		bt[small]=0;
	}
	avwt=wt/n;
	avtat=tat/n;
	printf("\nawt=%lf",avwt);
	printf("\natat=%lf",avtat);
}
