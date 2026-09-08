# Unit 02 Answer Key

1. A communicator is a process group plus a communication context. Rank is a process's zero-based index in that group; size is the number of members.
2. Ranks are communicator-relative identifiers, so different ordered groups can assign different indices to one process.
3. Rank 0 waits forever because the other communicator members never enter the collective. Collective control flow must be compatible.
4. An elapsed interval uses one local clock. Raw clocks on different processes need not be synchronized.
5. Loop `turn` from `size - 1` down to 0; every rank calls a barrier, and only `rank == turn` prints.
6. Query rank and size, report the error once from rank 0, then have every rank call `MPI_Finalize` and return.
