#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10
typedef struct {
    char type; // 0=fried chicken, 1=French fries
    int amount; // pieces or weight
    char unit; // 0=piece, 1=gram
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) {
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}
int main(){
    item item1;
    item1.type = '1';
    item1.amount = 2;
    item1.unit = '1';
    
    item item2;
    item2.type = '2';
    item2.amount = 6;
    item2.unit = '2';

    printf("item 1:\n type: %c\n amount: %d\n unit: %c\n",item1.type,item1.amount,item1.unit);
    produce(&item1);
    printf("First: %d, last: %d\n", first, last);
    
    printf("item 2:\n type: %c\n amount: %d\n unit: %c\n",item2.type,item2.amount,item2.unit);
    produce(&item2);
    printf("First: %d, last: %d\n", first, last);
    
    item* consumed = consume();
    printf("Item consumed:\n Type: %c, Amount: %d, Unit: %c\n", consumed->type, consumed->amount, consumed->unit);
    return 0;
}
