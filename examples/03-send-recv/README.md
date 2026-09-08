# Send and Receive

Build with `make`, then run `mpirun -np 2 ./send_recv`.

Rank 0 sends one integer. Rank 1 receives a message with an exact source and tag, then reports the envelope recorded in `MPI_Status`.
