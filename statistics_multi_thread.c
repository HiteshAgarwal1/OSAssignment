#include<stdio.h>
#include<pthread.h>

int size=7;
int avg_val,min_val,max_val;

void *average(void *args);
void *minimum(void *args);
void *maximum(void *args);

int main(){
	pthread_t avg,min,max;
	int val[7]={90,81,78,95,79,72,85};
	pthread_create(&avg,NULL,average,(void*)val);
	pthread_create(&min,NULL,minimum,(void*)val);
	pthread_create(&max,NULL,maximum,(void*)val);
	pthread_join(avg,NULL);
	pthread_join(min,NULL);
	pthread_join(max,NULL);
	printf("The average value is %d\n",avg_val);
	printf("The minimun value is %d\n",min_val);
	printf("The maximum value is %d\n",max_val);
return 0;
}
void *average(void *args){
	int *array=(int*)args;
	int sum=0,i;
	for(i=0;i<size;i++)
	     sum=sum+array[i];
	avg_val = sum/size;
}
void *minimum(void *args){
	int *array = (int*)args;
	min_val=array[0];
	for(int i=1;i<size;i++){
		if(!(min_val<array[i]))
			min_val=array[i];
	}
	
}
void *maximum(void *args){
	int *array = (int*)args;
	max_val=array[0];
	for(int i=1;i<size;i++){
		if(max_val<array[i])
			max_val=array[i];
	}
}
