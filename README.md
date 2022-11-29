# philosopher

``` bash
./philo [philo_amout] [philo_live] [philo_eating] [philo_sleep]
./philo [philo_amout] [philo_live] [philo_eating] [philo_sleep] [total_eat]


```

## constrin
- every input must be number
- philo amount not over 200
- philo live , philo eat philo spleep not less than 60 ms

---

## Phase 1 
get val
- [x] check argc int between 4 to 5
- [x] Collect parameter one by one
	- [x] check not emptystr
	- [x] check all number in str (not accept '-' sign)
	- [x] check len > 10 for max int - 2147483647 over this len not accept

## Phase 2 start Philo
- [x] Set updinner table   
	- [x] for Timmer and check Philosopher live
	- [x] HP monitor for each philosopher
	- []
	- []
	- []
- [ ] 


### pthread Allowed Function
``` c
int	pthread_create (pthread_t *thread, const pthread *attr, void *(*start_rountine)(void *), void *arg) 
```
- Creates a new thread of execution.

```c
int	pthread_join(pthread_t thread, void	**value_ptr)
```
- Cause the calling thread to wait for the terminated of specified thread.

```c
int	pthread_detach(pthread_t thread)
```
- Mark a thread for deletion   

```c
int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)

// in use
pthread_mutex_init(&(mutex_var), NULL);
```
- Initialize a mutex with specified attributes.

```c
int	pthread_mutex_lock(pthread_mutex_t *mutex);
```
Lock a mutex and block until it becomes available

```c
int	pthread_mutex_unlock(pthread_mutex_t *mutex);
```
Unlock a mutex

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

```c
int pthread_mutex_trylock(
```

### data type
- `pthread_t` 
//


### Timer must check for a philo life

### gettimeofday(struct timeval *s, (*void))  

