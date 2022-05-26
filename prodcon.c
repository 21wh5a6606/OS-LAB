#include<stdio.h>
#include<stdlib.h>
int full = 0,empty = 5,mutex = 1,x =0;
int wait(int s)
{
s--;
return s;
}

int signal(int s)
{
s++;
return s;
}
void producer(){
mutex = wait(mutex);
full = signal(full);
empty = wait(empty);
x++;
printf("producer produces the item %d",x);
mutex = signal(mutex);
}
void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
printf("consumer consumes item %d",x);
x--;
mutex = signal(mutex);
}
int main(){
int ch;
printf("1.producer\n 2.consumer\n 3.exit\n");
while(1){
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch){
case 1: if(mutex == 1 && (empty != 0))
		producer();
		else
		printf("buffer is full");
		break;
case 2:if(mutex == 1 && (full != 0))
		consumer();
		else
		printf("buffer is empty");
		break;
case 3:exit(0);
}
}
}
output
1.producer
 2.consumer
 3.exit
enter the choice
1
producer produces the item 1enter the choice
1
producer produces the item 2enter the choice
1
producer produces the item 3enter the choice
2
consumer consumes item 3enter the choice
2
consumer consumes item 2enter the choice
2
consumer consumes item 1enter the choice
2
buffer is emptyenter the choice
1
producer produces the item 1enter the choice
2
consumer consumes item 1enter the choice
2
buffer is emptyenter the choice
2


