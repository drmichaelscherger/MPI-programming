# Unit 01 Exercises

1. Two ranks each execute `int x = rank; x += 5;`. List the final value of `x` on each rank and explain why neither assignment changes the other.
2. A four-rank program prints immediately after initialization. Is `0, 1, 2, 3` a guaranteed output order? What information would be required to impose that order?
3. In your own words, distinguish SPMD from “every process does identical work.”
4. Sketch an SPMD program in which rank 0 coordinates and all other ranks perform work. Label local variables.
5. A student says two variables are shared because their printed pointer values are equal in two processes. Identify the mistake.
6. Modify the Unit 01 C example so each rank prints the sum of its rank and a command-line integer. Define behavior for a missing argument.

Answer key: [`../../solutions/exercises/unit-01.md`](../../solutions/exercises/unit-01.md).
