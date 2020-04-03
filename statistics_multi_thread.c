#include<stdio.h>
#include<pthread.h>

int size;
int avg_val,min_val,max_val;

pthread_t avg,min,max;

void *average(void *args);
void *minimum(void *args);
void *maximum(void *args);

int main(){
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	int val[size];
	printf("Enter %d elements (i.e. N1 N2 ...): ", size);
	for(int i=0; i<size; i++)
		scanf("%d",&val[i]);

	pthread_create(&avg,NULL,average,(void*)val);
	pthread_join(avg,NULL);
	printf("The average value is %d\n",avg_val);

	pthread_create(&min,NULL,minimum,(void*)val);
	pthread_join(min,NULL);
	printf("The minimun value is %d\n",min_val);

	pthread_create(&max,NULL,maximum,(void*)val);
	pthread_join(max,NULL);
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
