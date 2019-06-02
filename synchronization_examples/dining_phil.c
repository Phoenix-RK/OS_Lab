//kiruthya
//semaphores
//dining philosopher
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 5
#define THINKING 2
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N
#define HUNGRY 1
#define EATING 0 
sem_t mutex,s[N];
int state[N];
int phil[]={0,1,2,3,4};
void test(int phnum)
{
	if(state[phnum]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
	{
		state[phnum]=EATING;
		sleep(2);
		printf("\nphil %d is eating ",phnum+1);
		sem_post(&s[phnum]);

	}
}

void take_fork(int phnum)
{

	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("\nphil %d is hungry",phnum+1);
	test(phnum);
	sem_post(&mutex);
	sem_post(&s[phnum]);
	sleep(1);
}

void put_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("\nphilosopher %d is thinking ",phnum+1);
	printf("\n phil %dputs fork %d and %d down",phnum+1,LEFT+1,phnum+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void *philosopher(void* num)
{
	while(1)
	{
		int *i=num;
		sleep(1);
		take_fork(*i);
		sleep(0);
		put_fork(*i);
	}

}
int main()
{

	int i;
	pthread_t thread_id[N];
	sem_init(&mutex,0,1);
	for(i=0;i<N;i++)
	{
		sem_init(&s[i],0,0);

	}
	for(i=0;i<N;i++)
	{
		pthread_create(&thread_id[i],NULL,philosopher,&phil[i]);
		printf("\nphil %d is thinking",i+1);
	}

	for(i=0;i<N;i++)
	{
		pthread_join(thread_id[i],NULL);
	}

	return 0;
}
