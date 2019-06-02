//first come first serve - kiruthya
#include<stdio.h>
int main()
{
	int i,j,n,ttat=0,twt=0,temp,arr[10],bur[10],wt[10],tat[10],start[10],finish[10];

	printf("\nEnter the no of processes:");
	scanf("%d",&n);

	printf("\nenter the arrival time and burst time of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i],&bur[i]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i]<arr[j])
			{


				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;

				temp=bur[i];
				bur[i]=bur[j];
				bur[j]=temp;
			}

		}
	}


	for(i=0;i<n;i++)
	{
		if(i==0)
			start[i]=arr[i];
		else
			start[i]=finish[i-1];

		wt[i]=start[i]-arr[i];
		finish[i]=start[i]+bur[i];
		tat[i]=wt[i]+bur[i];
	}
	printf("arr\tbur\twt\ttat\tstart\tfinish\t");
	for(i=0;i<n;i++)
	{
		printf("\n%3d\t%3d\t%3d\t%3d\t%3d\t%3d",arr[i],bur[i],wt[i],tat[i],start[i],finish[i]);
		twt+=wt[i];
		ttat+=tat[i];
	}

	printf("\nttat=%f",(ttat*1.0)/n);
	printf("\ntwt=%f",(twt*1.0)/n);

}
