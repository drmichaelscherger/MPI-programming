# Unit 01 — Distributed Memory and SPMD

## Learning objectives

After this unit, students should be able to:

- distinguish shared-memory and distributed-memory execution;
- explain why processes must communicate explicitly;
- describe the single-program, multiple-data (SPMD) model;
- identify local state, rank-dependent behavior, and nondeterministic output;
- compile and launch a small MPI program.

## 1. The process is the unit of isolation

An operating system gives each process a private virtual address space. If two MPI processes each declare `int counter`, those variables occupy unrelated address spaces. Changing one does not change the other. This isolation is valuable: a process cannot casually corrupt another process's memory. It also means cooperation requires an explicit mechanism.

MPI supplies a portable message-passing interface. A message copies typed data from a buffer in one process into a buffer in another. The program, not a shared global variable, determines what moves and when.

| Shared-memory thread | MPI process |
| --- | --- |
| shares the process address space | owns a separate address space |
| communicates through shared objects | communicates through messages |
| synchronizes with locks/atomics | synchronizes through communication operations |
| usually fails within one process | may be a distinct OS process or machine |

MPI does not turn ordinary variables into distributed variables. Data ownership remains explicit.

## 2. Single program, multiple data

Most introductory MPI programs use SPMD: every process starts the same executable, then selects behavior using its integer **rank**. If the communicator has `size` processes, valid ranks are `0` through `size - 1`.

```c
if (rank == 0) {
    /* coordinator behavior */
} else {
    /* participant behavior */
}
```

SPMD does not mean every process executes the same instruction at the same instant. Control flow, local input, timing, and message arrival can differ.

## 3. A minimal lifecycle

```c
#include <mpi.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    /* MPI calls and local computation */
    MPI_Finalize();
    return 0;
}
```

Call `MPI_Init` before other MPI routines and `MPI_Finalize` before normal exit. Compile with the implementation's wrapper compiler:

```sh
mpicc -std=c11 -Wall -Wextra hello.c -o hello
mpirun -np 4 ./hello
```

The wrapper adds the implementation-specific headers and libraries. It is still compiling an ordinary C or C++ program.

## 4. Output is concurrent

When several ranks call `printf`, their writes race through the runtime and operating system. Rank order is not guaranteed. This is an immediate example of a distributed-systems principle: events occurring in different processes do not acquire a useful global order merely because humans expect one.

Avoid teaching `MPI_Barrier` as an output-ordering primitive. A barrier can ensure all ranks have reached a point, but after release they still run concurrently.

## 5. Design questions

For any distributed program, ask:

1. What data does each rank own?
2. Which rank needs data owned elsewhere?
3. What messages establish those dependencies?
4. What can happen concurrently?
5. What assumptions are being made about order and progress?

## Try it

Build [`examples/01-hello`](../../examples/01-hello/) and run it several times with different process counts. Then complete [Lab 01](../../labs/01-process-report/) and the [Unit 01 exercises](../../exercises/01-distributed-memory-spmd/).

## Checkpoint

- A rank identifies a process within a communicator, not necessarily a machine.
- Ordinary variables are local to a process.
- SPMD allows rank-dependent paths through one program.
- Concurrent output order is generally nondeterministic.
