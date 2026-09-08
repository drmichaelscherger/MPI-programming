# Lab 01 — Process Report

## Goal

Demonstrate that ranks execute one SPMD program while owning independent state.

## Tasks

1. Complete the TODOs in `process_report.c`.
2. Set `local_value` to `(rank + 1) * 10` on every rank.
3. Print rank, communicator size, process ID, and the address and value of `local_value`.
4. Run with 1, 2, and 4 ranks. Do not assume rank order in the output.
5. In `observations.md`, explain why similar or different virtual addresses do not imply shared storage.

Build with `make`; run with `mpirun -np 4 ./process_report`. A reference implementation is in [`../../solutions/01-process-report`](../../solutions/01-process-report/).

## Success criteria

The program works for every positive process count, every rank prints once, and the explanation distinguishes a virtual address from a shared memory location.
