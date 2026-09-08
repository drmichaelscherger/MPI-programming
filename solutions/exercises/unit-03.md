# Unit 03 Answer Key

1. Communicator/context, source rank, and tag must match; destination is the receiving rank. Counts and datatypes must describe compatible payloads.
2. No. An exact tag-20 receive does not match tag 10, so tag 10 remains pending until a compatible receive is posted.
3. It lets a server or manager accept whichever peer is ready. Code must inspect status and remain correct for every allowed arrival order.
4. Standard sends may buffer, but are not required to. Both sends can wait for matching receives, creating a cycle.
5. Rank 0 may send then receive while rank 1 receives then sends. Alternatively, both call `MPI_Sendrecv` with complementary peers and tags.
6. The receive buffer is too small and the message is truncated, normally causing an MPI error. Agree on a maximum size or probe the message and allocate enough storage.
7. `0.12 / (2 × 20,000) = 0.000003` seconds, or 3 microseconds.
