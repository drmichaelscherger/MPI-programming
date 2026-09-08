# Ping-Pong Latency

Build with `make`, then run `mpirun -np 2 ./ping_pong`. Supply an optional positive round count, such as `mpirun -np 2 ./ping_pong 50000`.

The reported value is half the average round-trip time for one integer after ten warm-up exchanges. It is an experiment, not a complete network benchmark.
