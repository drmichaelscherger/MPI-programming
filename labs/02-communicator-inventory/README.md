# Lab 02 — Communicator Inventory

## Goal

Create a readable inventory of all ranks without point-to-point messages.

## Tasks

1. Complete rank, size, and processor-name discovery in `communicator_inventory.c`.
2. Use the existing turn loop and a collective synchronization operation so ranks print in ascending order.
3. Measure each rank's elapsed interval from immediately before the loop through its print.
4. Test with at least two process counts.
5. Answer: why does the barrier not make clocks on different ranks equal?

Build with `make`; run with `mpirun -np 4 ./communicator_inventory`.

## Success criteria

Exactly one line appears for every rank, lines are in rank order, names are safely bounded, and all ranks execute the same number of collective operations.
