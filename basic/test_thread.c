#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


#define SLEEP 200
#define EATING 200
#define LIVE 410

int mails = 0;
pthread_mutex_t mutex;
typedef struct s_s
{
	int	live;
	int	live_times;
	pthread_t 			p;
	pthread_mutex_t		my_fork;
	pthread_mutex_t		*next_fork;
	int		i;
}	t_s;

typedef struct s_ob
{
	pthread_t	timer;
	int times;
	t_s **p;
}		t_ob;


void	*ob_routine(void *arg)
{
	int size = 4;
	int		i = 0;
	t_ob *ob;

	ob = (t_ob *)arg;
	printf("Timmer Entered Routine\n");
	while (1)
	{
		usleep(1000);
		ob->times++;
		i = 0;
		while (i < size)
		{
			ob->p[i]->live_times++;
			ob->p[i]->live--;
			if (ob->p[i]->live <= 0)
			{
				printf("%d ms NUMBER %d DIE\n",ob->p[i]->live_times, i);
				exit(0);
			}
			i++;
		}
	}
	
}

void *routine(void	*arg) 
{
	t_s *c;

	c = (t_s *)arg;
	printf("\e[1;32mID = %d\e[0m Entered rountine\n", c->i);
	while(1)
	{
		pthread_mutex_lock(&(c->my_fork));
		printf("\e[1;33mat %d ms ID = %d\e[0m Take Its fork\e[1;38m LIVE = %d\n",c->live_times, c->i, c->live);
		pthread_mutex_lock(c->next_fork);
		printf("\e[1;33mat %d ms ID = %d\e[1;39m Take other fork\e[1;38m LIVE = %d\n",c->live_times, c->i, c->live);
		printf("\e[1;33mat %d ms ID = %d\e[0m Is Eating\e[1;38m LIVE = %d\n",c->live_times, c->i, c->live);
		usleep(EATING * 1000);
		c->live = LIVE;
		printf("C - > live %d\n", c->live); 
		pthread_mutex_unlock(&(c->my_fork));
		pthread_mutex_unlock(c->next_fork);
		printf("\e[1;35mat %d ms ID = %d\e[0m Do Sleeping\n",c->live_times, c->i);
		usleep(SLEEP * 1000);
	}
	return (NULL);
}


int main(int argc, char* argv[]) {
	//pthread_mutex_destroy(&mutex);
	t_s p, p1, p2, p3, p4;
	t_ob ob;
	int	live = LIVE;
	int	i=0;

	// dieing Mus
	ob.p = malloc(sizeof(t_s *) * 4);
	ob.times = 0;
	ob.p[0] = &p;
	ob.p[1] = &p1;
	ob.p[2] = &p2;
	ob.p[3] = &p3;
//	ob.p[4] = &p4;
	p.i = 0;
	p1.i= 1;
	p2.i= 2;
	p3.i= 3;
//	p4.i= 4;
	p.live = live;
	p1.live = live;
	p2.live = live;
	p3.live = live;
//	p4.live = live;
	p.live_times = 0;
	p1.live_times = 0;
	p2.live_times = 0;
	p3.live_times = 0;
	p4.live_times = 0;

	p.next_fork  = &p1.my_fork;
	p1.next_fork = &p2.my_fork;
	p2.next_fork = &p3.my_fork;
	p3.next_fork = &p.my_fork;
//	p4.next_fork = &p.my_fork;
	pthread_mutex_init(p.next_fork, NULL);
	pthread_mutex_init(p1.next_fork, NULL);
	pthread_mutex_init(p2.next_fork, NULL);
	pthread_mutex_init(p3.next_fork, NULL);
//	pthread_mutex_init(p4.next_fork, NULL);
	pthread_create(&ob.timer, NULL, &ob_routine, &ob);
	while (i < 2)
	{
		if (i % 2)
		{
			pthread_create(&p.p, NULL, &routine, &p);
			pthread_create(&p2.p, NULL, &routine, &p2);
//		pthread_create(&p4.p, NULL, &routine, &p4);	
		}
		else		
		{
			pthread_create(&p1.p, NULL, &routine, &p1);
			pthread_create(&p3.p, NULL, &routine, &p3);
		}
		usleep(50);
		i++;
	}
		pthread_join(p.p, NULL);
		pthread_join(p1.p, NULL);
		pthread_join(p2.p, NULL);
		pthread_join(p3.p, NULL);
		pthread_join(ob.timer, NULL);
//	pthread_join(p4.p, NULL);
    return 0;
}
