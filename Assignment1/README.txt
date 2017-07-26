NAMES
*****
Kristi Chang		kristi.chang@csu.fullerton.edu

Programming Language used: C++
*******



Time:
********

For urls10.txt:

Parallel:
--------
real    0m28.487s
user    0m0.680s
sys     0m0.871s

Serial:
-------
real    1m3.367s
user    0m0.654s
sys     0m0.478s

Questions
*********
1. In the output of time, what is the difference between real, user, and sys times?

Real time is the total elapsed time from the start to the termination of the call.
User time is the amount of CPU time spent executing the process in user mode.
Sys time is the amount of CPU time spent executing the process in the kernel.

2. Which is longer: user time or sys time? Use your knowledge to explain why.

The sys time is longer than user time, since the user starting a system call takes less time than it takes to process it.

3. When downloading the files above, which downloader finishes faster? Why? Please Explain.

The parallel downloader finishes faster since it uses a parallel structure to download multiple files simultaneously. The serial downloader downloads the files one at a time, which takes longer.

4. Repeat the experiment for 10 files (any reasonably large-sized les, e.g., 100 MB, will do). Is the downloader in the previous question still faster? If not so, why? Please Explain.

The parallel downloader is still faster since it runs multiple processes at the same time.

