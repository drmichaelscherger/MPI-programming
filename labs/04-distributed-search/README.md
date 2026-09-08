# Lab 04 — Distributed Search

## Goal

Use a manager/worker protocol to search a fixed integer dataset for a target value.

## Protocol

Rank 0 owns the dataset and sends each worker a contiguous `[begin, end)` range using `TAG_RANGE`. Every worker searches its assigned range in the known dataset, then returns its first matching index or `-1` with `TAG_RESULT`. Rank 0 accepts results in any arrival order and reports the smallest matching index.

## Tasks

1. Complete the manager and worker TODOs in `distributed_search.c`.
2. Partition all elements across `size - 1` workers; uneven and empty ranges must be valid.
3. Receive results with `MPI_ANY_SOURCE`.
4. Run with target `7`, target `42`, and a missing target.
5. Explain why receiving in arrival order does not change the smallest-index result.

Build with `make`; for example, run `mpirun -np 4 ./distributed_search 7`.

## Constraints

Use at least two ranks. Do not use collectives; the purpose is to implement the point-to-point protocol explicitly.
