# Unit 03 — Point-to-Point Communication

## Learning objectives

Students should be able to send and receive typed messages, predict message matching, inspect `MPI_Status`, use wildcard receives deliberately, and recognize unsafe blocking dependencies.

## 1. A message and its envelope

A point-to-point operation names a buffer, element count, datatype, peer rank, tag, and communicator.

```c
MPI_Send(&value, 1, MPI_INT, destination, tag, comm);
MPI_Recv(&value, 1, MPI_INT, source, tag, comm, &status);
```

The receiver matches messages by communicator, source, and tag. The sender's rank is implicit. The receive buffer must be large enough for the incoming message, and sender/receiver datatype descriptions must be compatible.

## 2. Tags are protocol fields

Tags distinguish message meanings. Use named constants rather than unexplained integers:

```c
enum { TAG_REQUEST = 10, TAG_RESULT = 11 };
```

A tag is not a global channel. It is interpreted together with communicator and source/destination ranks.

## 3. Status and wildcards

After a receive, `status.MPI_SOURCE` and `status.MPI_TAG` identify the message actually selected. `MPI_Get_count` reports how many elements arrived.

`MPI_ANY_SOURCE` and `MPI_ANY_TAG` let a receive match multiple possible envelopes. This is useful for a manager accepting the next completed worker result, but it introduces nondeterminism. The program must be correct for every permitted arrival order.

## 4. Blocking is not a delivery guarantee

`MPI_Send` is allowed to return when its send buffer is reusable; it does not promise that the receiving application has processed the value. Small messages may be buffered while large messages may wait for a matching receive. Correctness must not depend on an implementation's buffering threshold.

`MPI_Recv` returns after the receive buffer contains the matched message.

Unsafe pattern:

```c
MPI_Send(... peer ...);
MPI_Recv(... peer ...);
```

If both peers send first, the program may deadlock. A safe two-party exchange can alternate roles or use `MPI_Sendrecv`.

## 5. Latency experiment

A ping-pong benchmark sends a payload from rank 0 to rank 1 and back. Measure many iterations, subtract loop overhead only if needed, and report half the average round-trip time as an estimate of one-way latency. Warm-up iterations reduce startup effects. State the message size, process placement, MPI implementation, and repetition count with results.

## Try it

Study [`03-send-recv`](../../examples/03-send-recv/) and [`03-ping-pong`](../../examples/03-ping-pong/), complete [Lab 03](../../labs/03-message-chain/), and solve the [Unit 03 exercises](../../exercises/03-point-to-point/).

## Checkpoint

- Matching uses communicator, source, and tag.
- A successful send does not mean the application-level receiver acted.
- Wildcards trade predetermined order for flexibility.
- Blocking dependencies must be designed without relying on buffering.
