## Operating System Scheduling Algorithms and Disk Scheduling
This project provides implementations of various operating system scheduling and disk scheduling algorithms. The scheduling algorithms are essential for efficient management and execution of processes and resources in operating systems. The project includes the following scheduling and page replacement algorithms:

### Process Scheduling Algorithms
1. First-Come, First-Served (FCFS):
   - FCFS is the simplest scheduling algorithm.
   - Processes are executed in the order they arrive.
   - No preemption; each process runs to completion.
2. Shortest Job First (SJF):
   - SJF schedules processes based on their burst times.
   - The process with the shortest burst time is executed next.
   - Can be preemptive (SRTF) or non-preemptive. (non-preempt is implemented here).
3. Priority:
   - Processes are scheduled based on priority.
   - The process with the highest priority is executed next.
   - Can be preemptive or non-preemptive. (non-preempt is implemented here).
4. Round-Robin:
   - Round-Robin uses a time quantum to schedule processes.
   - Processes are executed in a circular order, each receiving a fixed time slice (quantum).
   - Preemptive scheduling allows fair CPU time distribution.

### Page Replacement Algorithms
5. First-In-First-Out (FIFO):
   - FIFO replaces the oldest page in memory when a page fault occurs.
   - Pages are managed in a queue.
6. Optimal Page Replacement (OPR):
   - OPR replaces the page that will not be used for the longest period in the future.
   - Often used as a theoretical benchmark due to its impractical implementation.
7. Least Recently Used (LRU):
   - LRU replaces the page that hasn't been used for the longest period of time.
   - Requires keeping track of the usage history of pages.

### Disk Scheduling Algorithms
8. First-Come, First-Served (FCFS):
   - Disk requests are served in the order they arrive.
   - Simple but may cause high seek time.
9. Shortest Seek Time First (SSTF):
   - SSTF serves the disk request closest to the current head position.
   - Reduces average seek time by prioritizing requests near the current position.
