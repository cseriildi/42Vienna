# About the FdF project

## Summary
The goal of this project is to solve the **Dining Philosophers Problem**. 
- Philosophers sit at a round table with a bowl of spaghetti in the middle.
- They alternate between eating, thinking, and sleeping.
- There are as many forks as philosophers, and each philosopher needs two forks to eat.
- The simulation ends when a philosopher dies of starvation.

You will learn about **threads** and **mutexes**.

- **Allowed external functions**: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

## Useful stuff
- [Playlist to get familiar with threads](https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&si=AtKXJ5pkEW9mtvHN)

## Mandatory Part
- Each philosopher is a thread.
- The forks are between the philosophers. To eat they need to take both the one from the left and the right side.
- Use mutexes to manage forks *(to avoid philosophers using the same fork at the same time)*.

## Bonus Part
- Each philosopher is a child process.
- All forks are in the middle of the table, represented by a semaphore.
