# Unit 04 Answer Key

1. Predecessor is `(r - 1 + p) % p`; successor is `(r + 1) % p`.
2. Rank 0 sends 0. Ranks 1, 2, and 3 increment it, so 3 returns.
3. Pipeline stages can work on different items simultaneously. One item still passes through every stage, but completed items can emerge more frequently after filling.
4. Example: `TAG_WORK` carries a task identifier and arguments, `TAG_RESULT` carries identifier and result, and `TAG_STOP` carries no payload. Status identifies the worker.
5. Send two tasks to two workers and stop messages to the other three. After each active worker returns its result, send it a stop message too.
6. Safety: the reported index actually contains the target. Liveness: every worker eventually returns a result and terminates.
7. Wildcards select an available matching message; computation and communication times may differ, so completion order can differ from assignment order.
8. The manager initially fills available workers, receives a result from any source, sends that worker another task if one remains, and otherwise sends it a stop. It finishes after all tasks return and all workers receive stop.
