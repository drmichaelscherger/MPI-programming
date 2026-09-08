# Token Ring

Build with `make`, then run `mpirun -np 4 ./ring`.

Rank 0 injects a token. Each other rank increments it and forwards it to its successor. The explicit single-process case prevents rank 0 from issuing a blocking send to itself.
