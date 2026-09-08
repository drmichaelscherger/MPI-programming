# Examples

Build every example from the repository root with `make examples`, or enter an example directory and run `make`.

| Unit | Example | Language | Focus |
| --- | --- | --- | --- |
| 01 | [`01-hello`](01-hello/) | C and C++ | SPMD hello world and local state |
| 02 | [`02-process-info`](02-process-info/) | C | communicator metadata and timing |
| 03 | [`03-send-recv`](03-send-recv/) | C | a matched message and status |
| 03 | [`03-ping-pong`](03-ping-pong/) | C | round-trip latency |
| 04 | [`04-ring`](04-ring/) | C | token passing around a logical ring |
| 04 | [`04-worker-pool`](04-worker-pool/) | C | static manager/worker protocol |

Run programs with `mpirun -np N PROGRAM`. Output order may vary unless the program enforces an order.
