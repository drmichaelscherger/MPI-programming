#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

enum { TAG_PING = 20, TAG_PONG = 21, DEFAULT_ROUNDS = 10000 };

int main(int argc, char **argv) {
    int rank;
    int size;
    int token = 0;
    int rounds = DEFAULT_ROUNDS;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0) fprintf(stderr, "Run with exactly 2 processes.\n");
        MPI_Finalize();
        return 1;
    }
    if (argc == 2) rounds = atoi(argv[1]);
    if (rounds <= 0) {
        if (rank == 0) fprintf(stderr, "Rounds must be positive.\n");
        MPI_Finalize();
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        if (rank == 0) {
            MPI_Send(&token, 1, MPI_INT, 1, TAG_PING, MPI_COMM_WORLD);
            MPI_Recv(&token, 1, MPI_INT, 1, TAG_PONG, MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);
        } else {
            MPI_Recv(&token, 1, MPI_INT, 0, TAG_PING, MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);
            MPI_Send(&token, 1, MPI_INT, 0, TAG_PONG, MPI_COMM_WORLD);
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    const double start = MPI_Wtime();
    for (int i = 0; i < rounds; ++i) {
        if (rank == 0) {
            MPI_Send(&token, 1, MPI_INT, 1, TAG_PING, MPI_COMM_WORLD);
            MPI_Recv(&token, 1, MPI_INT, 1, TAG_PONG, MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);
        } else {
            MPI_Recv(&token, 1, MPI_INT, 0, TAG_PING, MPI_COMM_WORLD,
                     MPI_STATUS_IGNORE);
            MPI_Send(&token, 1, MPI_INT, 0, TAG_PONG, MPI_COMM_WORLD);
        }
    }
    const double elapsed = MPI_Wtime() - start;

    if (rank == 0) {
        const double one_way_us = elapsed * 1.0e6 / (2.0 * rounds);
        printf("%d round trips in %.6f s; estimated one-way latency %.3f us\n",
               rounds, elapsed, one_way_us);
    }

    MPI_Finalize();
    return 0;
}
