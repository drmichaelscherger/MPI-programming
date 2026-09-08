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

The initial course material emphasizes portable MPI concepts and local or general-purpose MPI execution. Cluster scheduler material is outside the scope of this repository.

## Prerequisites

Install an MPI implementation that provides `mpicc`, `mpicxx`, and `mpirun` (for example, Open MPI or MPICH), together with a C/C++ build toolchain and GNU Make.

As examples are added, a typical workflow will be:

```sh
make
mpirun -np 4 ./examples/01-hello/hello
make clean
```

## Current status

Units 01–04 are ready for use:

| Unit | Notes | Examples | Lab | Exercises |
| --- | --- | --- | --- | --- |
| 01 — Distributed Memory and SPMD | [Notes](notes/01-distributed-memory-spmd/) | [Hello](examples/01-hello/) | [Process Report](labs/01-process-report/) | [Exercises](exercises/01-distributed-memory-spmd/) |
| 02 — MPI Fundamentals | [Notes](notes/02-mpi-fundamentals/) | [Process Info](examples/02-process-info/) | [Communicator Inventory](labs/02-communicator-inventory/) | [Exercises](exercises/02-mpi-fundamentals/) |
| 03 — Point-to-Point Communication | [Notes](notes/03-point-to-point/) | [Send/Receive](examples/03-send-recv/), [Ping-Pong](examples/03-ping-pong/) | [Message Chain](labs/03-message-chain/) | [Exercises](exercises/03-point-to-point/) |
| 04 — Communication Patterns | [Notes](notes/04-communication-patterns/) | [Ring](examples/04-ring/), [Worker Pool](examples/04-worker-pool/) | [Distributed Search](labs/04-distributed-search/) | [Exercises](exercises/04-communication-patterns/) |

Instructor reference implementations and answer keys are in [`solutions/`](solutions/).
