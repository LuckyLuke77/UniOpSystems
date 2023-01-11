//COMPLIE WITH: gcc -pthread -o ex2 ex2.c

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t mutex;
char *message = "Hello ";

void* thread(void* arg)
{
    sem_wait(&mutex);
    printf("%s", message);
    if (message == "Hello ") {
	message = "there ";
    } else if (message == "there ") {
	message = "wonderful ";
    } else if (message == "wonderful ") {
        message = "world!\n";
    } else {
	message = "Hello ";
    }  
    sem_post(&mutex);
}

int main() {
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2,t3,t4;
    int i = 0;
    while (i < 100) {
	pthread_create(&t1,NULL,thread,NULL);
	pthread_create(&t2,NULL,thread,NULL);
	pthread_create(&t3,NULL,thread,NULL);
	pthread_create(&t4,NULL,thread,NULL);
	i++;
	sleep(1);
    }
    sem_destroy(&mutex);
    return 0;
}
