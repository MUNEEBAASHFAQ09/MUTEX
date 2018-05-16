#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;
int array[10000];

// summing array function
void* sum_array(void* arg)
{
	int sum=0;
	int start=(int)arg;
	int finish=start+1000;
	for(int i=start;i<finish;i++)
	{
		pthread_mutex_lock(&mut);
		sum=sum+array[i];
		pthread_mutex_unlock(&mut);
	}
	return (void*)sum;
	pthread_exit(NULL);
}
//creating thread function
void * creating_threads()
{
	void *inner_sum[10];
	int sum=0;
	
	//making threads
	pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10;
	
	pthread_create(&thread1,NULL,sum_array,(void*)0);
	pthread_create(&thread2,NULL,sum_array,(void*)1000);
	pthread_create(&thread3,NULL,sum_array,(void*)2000);
	pthread_create(&thread4,NULL,sum_array,(void*)3000);
	pthread_create(&thread5,NULL,sum_array,(void*)4000);
	pthread_create(&thread6,NULL,sum_array,(void*)5000);
	pthread_create(&thread7,NULL,sum_array,(void*)6000);
	pthread_create(&thread8,NULL,sum_array,(void*)7000);
	pthread_create(&thread9,NULL,sum_array,(void*)8000);
	pthread_create(&thread10,NULL,sum_array,(void*)9000);
	
	// joining thread so that they wait for each other
	
	pthread_join(thread1,&inner_sum[0]);
	sum=sum+(int)inner_sum[0];
	
	pthread_join(thread2,&inner_sum[1]);
	sum=sum+(int)inner_sum[1];
	
	pthread_join(thread3,&inner_sum[2]);
	sum=sum+(int)inner_sum[2];
	
    pthread_join(thread4,&inner_sum[3]);
	sum=sum+(int)inner_sum[3];
	
	pthread_join(thread5,&inner_sum[4]);
	sum=sum+(int)inner_sum[4];
	
	pthread_join(thread6,&inner_sum[5]);
	sum=sum+(int)inner_sum[5];
	
	pthread_join(thread7,&inner_sum[6]);
	sum=sum+(int)inner_sum[6];
	
	pthread_join(thread8,&inner_sum[7]);
	sum=sum+(int)inner_sum[7];
	
	pthread_join(thread9,&inner_sum[8]);
	sum=sum+(int)inner_sum[8];
	
	pthread_join(thread10,&inner_sum[9]);
	sum=sum+(int)inner_sum[9];
	
	//returning sum 
	return (void*)sum;
	pthread_exit(NULL);
}

int main()
{
	//initializing array 
	for (int i=0;i<10000;i++)
	{
		array[i]=i;
	}
   // for receiving total sum
     void *total_sum;
	 int total=0;
	pthread_t parent_thread;
	
	//initializing mutex
	
	pthread_mutex_init(&mut,NULL);
	
	//creating parent thread
	pthread_create(&parent_thread,NULL,creating_threads,NULL);
	
	//joining parent thread
	pthread_join(parent_thread,&total_sum);
	
	//get total sum value
	
	 total= (int) total_sum;
	//destroying mutex
	
	pthread_mutex_destroy(&mut);
	//printing total sum of the  array
	
	printf("THE TOTAL SUM IS=%d",total);
	
	return 0;
	
	
	
	
}
