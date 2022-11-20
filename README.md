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
- check argc int between 4 to 5
- Collect parameter one by one
	- check not emptystr
	- check all number in str (not accept '-' sign)
	- check len > 10 for max int - 2147483647 over this len not accept

