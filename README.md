# spinlockCounter

This uses 2 threads and spinlocks in order to form a simple counter.  If one inputs 1000 as the input, the two threads will result in an output of 2000.  By using spinlocks, it prevents the threads from trying to increment at the same time.
