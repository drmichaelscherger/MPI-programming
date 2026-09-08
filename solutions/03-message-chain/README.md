# Lab 03 Reference Solution

The chain has no circular wait: rank 0 sends without first waiting, and every later rank waits only for its predecessor. For `N` ranks, the last value is `1 + N(N-1)/2`.
