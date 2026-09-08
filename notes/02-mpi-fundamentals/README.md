# Unit 02 — MPI Fundamentals

## Learning objectives

Students should be able to initialize and finalize MPI, query rank and size, use communicator metadata safely, measure elapsed time, and explain the role of a communicator.

## 1. Communicators define a communication universe

A communicator contains an ordered group of processes plus a communication context. `MPI_COMM_WORLD` contains all processes launched for the program. A rank is meaningful only relative to a communicator: the same process may have different ranks in different communicators.

```c
int rank;
int size;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
```

Keep the communicator visible in program design. It determines which ranks may address one another and prevents unrelated communication from being confused.

## 2. Discovering the execution environment

`MPI_Get_processor_name` returns a printable processor name. Multiple ranks may report the same name because ranks can share a machine.

```c
char name[MPI_MAX_PROCESSOR_NAME];
int length;
MPI_Get_processor_name(name, &length);
```

Treat the name as descriptive metadata, not a globally unique identity. Use ranks for protocol decisions.

## 3. Timing

`MPI_Wtime()` returns a local wall-clock value as a `double`. Measure elapsed time by subtraction:

```c
double start = MPI_Wtime();
/* work */
double elapsed = MPI_Wtime() - start;
```

The clocks of different processes are not guaranteed to be synchronized. Comparing elapsed intervals on one rank is safe; comparing raw timestamps from different ranks may not be.

`MPI_Barrier(comm)` blocks a rank until every member of `comm` has entered the barrier. It can align the start of a classroom timing experiment, but barriers also add synchronization cost and can hide load imbalance.

## 4. Errors and valid program shapes

MPI routines return error codes, although the default communicator error handler usually aborts the job. Check assumptions that belong to the application. If a program requires exactly two ranks, validate `size` and print a clear usage message from rank 0.

```c
if (size != 2) {
    if (rank == 0) fprintf(stderr, "Run with exactly 2 processes.\n");
    MPI_Finalize();
    return 1;
}
```

All ranks must follow compatible lifecycle and collective-call paths. One rank returning while peers wait in a collective is a distributed control-flow bug.

## 5. Ordered reporting without point-to-point messages

For a small diagnostic only, ranks can take turns while all ranks execute the same loop:

```c
for (int turn = 0; turn < size; ++turn) {
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == turn) printf("rank %d\n", rank);
}
```

This is deliberately synchronization-heavy. Unit 03 introduces messages, which provide more meaningful ordering and data transfer.

## Try it

Run [`examples/02-process-info`](../../examples/02-process-info/), complete [Lab 02](../../labs/02-communicator-inventory/), and answer the [Unit 02 exercises](../../exercises/02-mpi-fundamentals/).

## Checkpoint

- A communicator supplies both membership and communication context.
- Rank and size are properties of a communicator.
- Raw `MPI_Wtime` values are local; elapsed intervals are the normal measurement.
- A collective must be called compatibly by every participating rank.
