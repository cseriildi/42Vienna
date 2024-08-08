# About the Philosophers project

## Summary
The goal of this project is to solve the **Dining Philosophers Problem**. 
- Philosophers sit at a round table with a bowl of spaghetti in the middle.
- They alternate between eating, sleeping, and thinking.
- There are as many forks as philosophers, and each philosopher needs two forks to eat.
- The simulation ends when a philosopher dies of starvation or if the optional `number of times each philosophers must eat` condition has been reached.

## Useful stuff
- [Playlist to get familiar with threads, mutexes and semaphores](https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&si=AtKXJ5pkEW9mtvHN)
- [Playlist about Unix Processes in C](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=iyDYLxQotEdMbpUW)
- [Visualizer](https://nafuka11.github.io/philosophers-visualizer/) for the output of your project
- To check for data races and deadlocks in your code use the `--tool=helgrind` flag with valgrind
- To check for the leaks in each process use the `--track-children=yes` flag with the valgrind
- Check out [Lukas' README](https://github.com/itislu/42-Philosophers/blob/main/README.md) for the optimal distribution of the thinking time in case of odd number of philosophers

## Mandatory Part

You will learn about **threads** and **mutexes** and everything that comes with them, like **data races** and **deadlocks**.
- **Allowed external functions**: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- Each philosopher is a thread.
- The forks are between the philosophers. To eat they need to take both the one from the left and the right side.
- Use mutexes to manage forks *(to avoid philosophers using the same fork at the same time)*.

## Bonus Part

You will learn about **processes** and **semaphores**.
- **Allowed external functions**: `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
- Each philosopher is a child process.
- All forks are in the middle of the table, represented by a semaphore.
