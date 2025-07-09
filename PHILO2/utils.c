#include "philo.h"

#include <sys/time.h>

long get_time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec) * 1000L + (long)(tv.tv_usec) / 1000L);
}

