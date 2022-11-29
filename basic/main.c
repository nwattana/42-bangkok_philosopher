#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(void)
{
	int	pre = 0;
	int cur = 0;
	struct timeval now;
	int	i=1000;
	long int	prv_time;
	long int	cur_time;
	long int	time_dif;
	
	gettimeofday(&now, NULL);
	prv_time = now.tv_sec * 1000000 + now.tv_usec; 
//	prv_time = now.tv_usec;
	while (i)
	{
		gettimeofday(&now, NULL);
		cur_time = now.tv_sec * 1000000 + now.tv_usec; 
//		cur_time = now.tv_usec;
		time_dif = cur_time - prv_time;
		if (time_dif > 1000 && time_dif < 1005)
		{
			printf("%ld %ld\n",time_dif/1000, cur_time);
			prv_time = cur_time;
			i--;
		}
		else if (time_dif > 1000)
		{
			printf("\e[1;31m i = %d ms %ld\e[0m\n",i, time_dif/1000);
			prv_time = cur_time;
			i--;
		}
	}
}
