#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type;
	int amount;
	char unit;
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;
void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	}
item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
void output(item i){
	printf("item : type = %c, amount = %d, unit = %c",i.type,i.amount,i.unit);
	printf("\nlast : %d, first : %d\n\n",last,first);
}
void *threadproduce(item x,item y,item z){
	produce(&x);
	output(x);
	produce(&y);
	output(y);
	produce(&z);
	output(z);
};
void *threadconsume(){
	consume();
	printf("\nConsume : last = %d, first = %d\n\n",last,first);
	consume();
	printf("\nConsume : last = %d, first = %d\n\n",last,first);	
};

int main(){
	item i[3];
	i[0].type='1';
	i[0].amount=2;
	i[0].unit='1';
	i[1].type='1';
	i[1].amount=1;
	i[1].unit='0';
	i[2].type='0';
	i[2].amount=3;
	i[2].unit='1';
	pthread_t tid_produce,tid_consume;
	pthread_create(&tid_produce,NULL,threadproduce(i[0],i[1],i[2]),NULL );
	pthread_create(&tid_consume,NULL,threadconsume(),NULL);		
	pthread_join(tid_consume, NULL);
	return 0;
}
