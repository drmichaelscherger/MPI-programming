# Unit 04 — Communication Patterns

## Learning objectives

Students should be able to translate a distributed protocol into MPI messages, compare ring, pipeline, and manager/worker patterns, assign tags to message meanings, and reason about termination.

## 1. Protocol before code

Write down the protocol before choosing MPI calls:

| Question | Example answer |
| --- | --- |
| Participants | manager rank 0 and workers 1…N−1 |
| Message types | work item, result, stop |
| Payload | integer work index or result pair |
| Allowed order | results may arrive in any order |
| Termination | each worker receives exactly one stop message |

This exposes missing states and ambiguous messages early. Named tag constants make the implemented protocol visible.

## 2. Ring and token passing

In a ring, rank `r` receives from `(r - 1 + size) % size` and sends to `(r + 1) % size`. A token can represent permission, accumulated state, or logical progress. Rank 0 commonly injects and eventually removes the token.

The ring creates a causal order without requiring a global barrier. Be precise about the `size == 1` case, where predecessor and successor are the same process.

## 3. Pipeline

A pipeline assigns stages to ranks. Each stage receives an item, transforms it, and forwards it. Throughput can improve when different items occupy different stages concurrently, even though the latency of one item includes every stage.

Termination must flow through the pipeline, often as a sentinel message. A sentinel value is safe only when it cannot be confused with valid data; a distinct tag is usually clearer.

## 4. Manager/worker

A manager distributes independent work and collects results. Static assignment is simple but may leave fast workers idle. Dynamic assignment sends new work to whichever worker finishes next, improving balance when task costs vary.

A robust dynamic manager tracks:

- undispatched work;
- workers with outstanding tasks;
- results received;
- stop messages sent.

Workers should not guess whether more work exists. The manager explicitly sends work or termination.

## 5. Correctness properties

Reason about more than the happy path:

- **Safety:** no task is processed twice; messages are interpreted correctly.
- **Liveness:** every rank can eventually progress; no receive waits forever.
- **Termination:** every participant learns that the protocol is complete.
- **Edge cases:** one process, more workers than tasks, empty partitions, and uneven work.

## 6. Pattern selection

Use a ring for neighbor relationships or token circulation, a pipeline for staged transformations, and manager/worker for independent tasks with centralized assignment. These are design patterns, not mandatory architectures. Later units introduce collectives and topologies that express some operations more directly.

## Try it

Study [`04-ring`](../../examples/04-ring/) and [`04-worker-pool`](../../examples/04-worker-pool/), implement [Lab 04](../../labs/04-distributed-search/), and complete the [Unit 04 exercises](../../exercises/04-communication-patterns/).

## Checkpoint

- Tags should encode protocol meaning.
- Termination is an explicit part of a distributed protocol.
- Arrival order is not the same as task order.
- Edge cases often reveal hidden protocol assumptions.
