#include "sync_car.h"

pthread_mutex_t mutex;
pthread_cond_t cond1;
pthread_cond_t cond2;

void station_init(struct station *station)
{
	station->psgwait = 0;
	station->car = 0;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond1,NULL);
	pthread_cond_init(&cond2,NULL);
}

void station_load_car(struct station *station, int count)
{
  	pthread_mutex_lock(&mutex);

	while(station->psgwait > 0 && count > 0){
		station->car = 1;
		pthread_cond_signal(&cond1);
		count--;
		pthread_cond_wait(&cond2,&mutex);
	}

	pthread_mutex_unlock(&mutex);
}

void station_wait_for_car(struct station *station)
{
	pthread_mutex_lock(&mutex);
	while(station->car == 0){
		station->psgwait++;
		pthread_cond_wait(&cond1,&mutex);
	}
	pthread_mutex_unlock(&mutex);
}

void station_on_board(struct station *station)
{
	station->psgwait--;
	pthread_cond_broadcast(&cond2);
}