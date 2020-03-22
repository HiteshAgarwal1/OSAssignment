#include<stdio.h>
#include<pthread.h>
int size=7;
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
}
void *average(void *args){
	int *array=(int*)args;
	int sum,i;
	for(i=0;i<size;i++)
		sum+=array[i];
	printf("The average value is %d\n",sum/size);
}
void *minimum(void *args){
	int *array=(int*)args;
	int min=array[0],i;
	for(i=1;i<size;i++){
		if(!(min<array[i]))
			min=array[i];
	}
	printf("The minimun value is %d\n",min);
}
void *maximum(void *args){
	int *array=(int*)args;
	int max=array[0],i;
	for(i=1;i<size;i++){
		if(max<array[i])
			max=array[i];
	}
	printf("The maximum value is %d\n",max);
}
