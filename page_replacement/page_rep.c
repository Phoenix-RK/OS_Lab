//kiruthya
//page replacement
#include<stdio.h>
int i,j,k,pagecount,nf,n;
int in[25],near[25],least[25],p[25];

void getdata()
{
	printf("\nenter the no of pages:");
	scanf("%d",&n);
	printf("\nenter the ele:");
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	printf("\nenter the frame size:");
	scanf("%d",&nf);
}

void initialize()
{
	pagecount=0;
	for(k=0;k<nf;k++)
		p[k]=9999;
}

void disp()
{
	for(k=0;k<nf;k++)
	{
		if(p[k]!=9999)
			printf(" %d",p[k]);
	}
}

int ishit(int data)
{
	int hit=0;
	for(k=0;k<nf;k++)
	{
		if(p[k]==data)
		{
			hit=1;
			break;
		}

	}
	return hit;
}

void dispcount()
{
	printf("\npagefault=%d",pagecount);
}
void fifo()
{
	initialize();
	for(i=0;i<n;i++)
	{
		if(ishit(in[i])==0)
		{
			for(k=0;k<nf-1;k++)
			{
				p[k]=p[k+1];
			}
			p[k]=in[i];
			pagecount++;
			disp();
		}
		else
			printf("\nno pagefault");
	}
	dispcount();
}



void optimal()
{

	initialize();
	for(i=0;i<n;i++)
	{
		if(ishit(in[i])==0)
		{
			for(j=0;j<nf;j++)
			{
				int pg=p[j];
				int found=0;
				for(k=i;k<n;k++)
				{
					if(pg==in[k])
					{
						near[j]=k;
						found=1;
						break;
					}
					else
						found=0;
				}
				if(!found)
					near[j]=9999;
			}
			int max=-9999;
			int repindex;
			for(j=0;j<nf;j++)
			{
				if(near[j]>max)
				{
					max=near[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pagecount++;
			disp();
		}
		else
			printf("\nno pagefaults");
	}
	dispcount();
}


void lru()
{
	initialize();
	for(i=0;i<n;i++)
	{
		if(ishit(in[i])==0)
		{
			for(j=0;j<nf;j++)
			{
				int pg=p[j];
				int found=0;
				for(k=i-1;k>=0;k--)
				{
					if(pg==in[k])
					{
						least[j]=k;
						found=1;
						break;
					}
					else
						found=0;
				}
				if(!found)
					least[j]=-9999;
			}


			int min=9999;
			int repindex;
			for(j=0;j<nf;j++)
			{
				if(least[j]<min)
				{
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=in[i];
			pagecount++;
			disp();
		}
		else
			printf("\nno pagefaults");
	}
	dispcount();
}


int main()
{
	int choice;
	while(1)
	{
		printf("\nPage Replacement Algorithms\n1.Enter data\n2.FIFO\n3.Optimal\n4.LRU\n5.LFU\n6.Second Chance\n7.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getdata();
				break;
			case 2:
				fifo();
				break;
			case 3:
				optimal();
				break;
			case 4:
				lru();
				break;
		}
	}
}


