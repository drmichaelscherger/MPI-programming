# Hello, MPI

Build with `make`, then try `mpirun -np 4 ./hello` and `mpirun -np 4 ./hello_cpp`.

Every rank executes the same program but computes a different local value. Run each program repeatedly and observe that output order is not guaranteed.
