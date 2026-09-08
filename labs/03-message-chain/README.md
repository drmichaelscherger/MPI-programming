# Lab 03 — Message Chain

## Goal

Pass a value from rank 0 through every rank using blocking point-to-point communication.

## Protocol

- Rank 0 starts with the integer `1` and sends it to rank 1.
- Every intermediate rank receives from its predecessor, adds its rank, and sends to its successor.
- The last rank prints the final value.
- With one process, rank 0 prints `1` without sending.

## Tasks

Complete the TODOs in `message_chain.c`, use the provided tag, and validate the result. For `N` ranks, the expected final value is `1 + N(N-1)/2`.

Build with `make`; test with 1, 2, and 5 ranks. Explain why this blocking order cannot form a cycle.

## Success criteria

Every message has an exact source and tag, all process counts are handled, and the result matches the formula.
