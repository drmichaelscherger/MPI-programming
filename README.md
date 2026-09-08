# MPI Programming

Teaching materials and examples for learning Message Passing Interface (MPI) programming in C and C++.

This repository is intended first to complement an Advanced Operating Systems course with a distributed-systems emphasis. It connects MPI programming to concepts such as separate address spaces, message passing, synchronization, communication protocols, deadlock, asynchronous computation, data ownership, and distributed algorithms. The material is designed to grow later into a broader resource for a Parallel Computing course, including decomposition, scalability, and performance analysis.

## Repository organization

- `notes/` — concise teaching notes organized by topic
- `examples/` — small, focused, runnable MPI programs
- `labs/` — guided programming assignments
- `exercises/` — practice and debugging problems
- `solutions/` — instructor solutions for selected work
- `include/` — shared headers and teaching utilities
- `Makefile` — root-level entry points for building and cleaning examples and labs

Each directory contains a short README so material can be added incrementally without changing the overall structure.

## Planned progression

1. Distributed memory, message passing, and the SPMD model
2. MPI initialization, communicators, ranks, and process execution
3. Point-to-point communication, tags, and message status
4. Distributed communication patterns: request/reply, ring, pipeline, and worker pools
5. Blocking semantics, ordering, dependencies, and deadlock
6. Nonblocking communication and asynchronous progress
7. Collective communication and synchronization
8. Distributed data, ownership, partitioning, and global/local indexing
9. Distributed algorithms in C and C++
10. Process topologies, neighborhood communication, and halo exchange
11. Measurement, communication cost, scalability, and load balance
12. Advanced topics for a Parallel Computing course

The initial course material emphasizes portable MPI concepts and local or general-purpose MPI execution. Cluster scheduler material, including SLURM, is intentionally outside the scope of this repository.

## Prerequisites

Install an MPI implementation that provides `mpicc`, `mpicxx`, and `mpirun` (for example, Open MPI or MPICH), together with a C/C++ build toolchain and GNU Make.

As examples are added, a typical workflow will be:

```sh
make
mpirun -np 4 ./examples/01-hello/hello
make clean
```

## Current status

This is the initial repository skeleton. Notes, examples, labs, exercises, and solutions will be developed together so that explanations and runnable code remain aligned.
