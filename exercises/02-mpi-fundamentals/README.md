# Unit 02 Exercises

1. Define communicator, rank, and size, and state how the three are related.
2. Why can a process have rank 0 in one communicator and rank 3 in another?
3. Find the bug: rank 0 calls `MPI_Barrier`, while every other rank skips it and finalizes.
4. Explain why subtracting two `MPI_Wtime()` readings on one rank is safer than comparing raw readings from two ranks.
5. Write pseudocode that prints ranks in descending order using the same number of barrier calls on every rank.
6. Add an exact-two-ranks precondition to a program. Which ranks should finalize, and why?

Answer key: [`../../solutions/exercises/unit-02.md`](../../solutions/exercises/unit-02.md).
