# Process Information

Build with `make`, then run `mpirun -np 4 ./process_info`.

The program prints communicator rank and size, processor name, and local elapsed time. A turn-taking loop makes the report readable; it is intentionally synchronization-heavy and is not a general output strategy.
