#include<stdio.h>
#include<pthread.h>
int size=7;
void *average(void *args);
//void *minimum(void args);
//void *maximum(void args);
int main(){
	pthread_t avg,min,max;
	int val[7]={90,81,78,95,79,72,85};
	pthread_create(&avg,NULL,average,(void*)val);
	pthread_join(avg,NULL);	
}
void *average(void *args){
	int *array=(int*)args;
	int sum,i;
	for(i=0;i<size;i++)
		sum+=array[i];
	printf("The average value is %d",sum/size);
}
