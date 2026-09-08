# Static Worker Pool

Build with `make`, then run `mpirun -np 4 ./worker_pool`.

Rank 0 sends one integer task to each worker and accepts results in arrival order with `MPI_ANY_SOURCE`. The returned pair preserves the task/result relationship. Lab 04 extends this idea to partitioned data.
