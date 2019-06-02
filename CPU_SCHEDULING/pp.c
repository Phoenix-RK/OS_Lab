//kiruthya
//cpu scheduling
//preemptive priority
#include<stdio.h>
int main()
{
	int at[10],bt[10],p[10],temp[10],end,count=0,limit,i,j,n,small,time;
	float wt,tat,awt,atat;
	printf("\nenter the no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the arr,burst time and priio:");
		scanf("%d%d%d",&at[i],&bt[i],&p[i]);
		temp[i]=bt[i];
	}
	p[9]=11;
	
	for(time=0;count<n;time++)
	{
		small=9;
		
//		printf("\nhello1");
		for(i=0;i<n;i++){
			//printf("\nmmm");
			if(at[i]<=time && p[i]<p[small] && bt[i]>0)
			{

				small=i;
			}
		}
		bt[small]--;
		if(bt[small]==0)
		{


			count++;
			end=time+1;
			wt+=end-at[small]-temp[small];
			tat+=end-at[small];
		}
//		printf("\nCount: %d", count);


	}
	printf("%f\n%f",wt*1.0/n,tat*1.0/n);



	return 0;

}
