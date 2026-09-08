# Unit 03 Exercises

1. List every envelope field used to match an `MPI_Recv` with an `MPI_Send`.
2. Rank 0 sends tag 10 and then tag 20 to rank 1. Rank 1 first receives tag 20, then tag 10. Is the first receive allowed to take the tag-10 message?
3. When is `MPI_ANY_SOURCE` useful, and what new correctness obligation does it create?
4. Explain why two ranks that both call blocking `MPI_Send` before `MPI_Recv` are not portable even if a test with small messages succeeds.
5. Write a safe two-rank integer exchange using alternating send/receive roles or `MPI_Sendrecv`.
6. A receive allocates space for 4 integers but a matching sender transmits 10. Describe the problem and one prevention strategy.
7. For 20,000 ping-pong rounds completed in 0.12 seconds, compute the estimated one-way latency.

Answer key: [`../../solutions/exercises/unit-03.md`](../../solutions/exercises/unit-03.md).
