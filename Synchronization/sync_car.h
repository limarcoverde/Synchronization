#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

struct station{
	int psgwait;
	int car;
};

void station_load_car (struct station *station, int count);
void station_wait_for_car (struct station *station);
void station_on_board (struct station *station);
void station_init(struct station *station);