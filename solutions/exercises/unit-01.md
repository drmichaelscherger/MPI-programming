# Unit 01 Answer Key

1. Rank 0 ends with 5; rank 1 ends with 6. Each `x` belongs to a separate process address space.
2. No order is guaranteed. The program needs an explicit causal or synchronization scheme, such as token passing or carefully structured turns.
3. SPMD means processes start the same program. Rank, data, and message history can lead them through different branches and workloads.
4. A typical sketch queries rank; rank 0 runs coordinator logic and owns coordinator-local state, while nonzero ranks run worker logic and own worker-local state.
5. Pointer values are virtual addresses interpreted within different address spaces. Equal numeric values do not name shared physical storage.
6. Check `argc` after initialization, report usage from rank 0 if needed, and have every rank finalize. Otherwise parse the value locally and print `rank + argument`.
