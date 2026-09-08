#include <limits.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

enum { TAG_RANGE = 60, TAG_RESULT = 61 };
static const int DATA[] = {4, 7, 1, 9, 7, 3, 8, 2, 7, 5, 6, 0};
static const int DATA_COUNT = (int)(sizeof(DATA) / sizeof(DATA[0]));

int main(int argc, char **argv) {
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2 || argc != 2) {
        if (rank == 0) fprintf(stderr, "Usage: mpirun -np N %s TARGET (N >= 2)\n", argv[0]);
        MPI_Finalize();
        return 1;
    }

    const int target = atoi(argv[1]);
    (void)DATA;
    (void)DATA_COUNT;
    if (rank == 0) {
        int best = INT_MAX;
        /* TODO: partition DATA_COUNT elements and send two-int ranges. */
        /* TODO: receive one result per worker using MPI_ANY_SOURCE. */
        printf("target %d: %s", target, best == INT_MAX ? "not found\n" : "found");
        if (best != INT_MAX) printf(" at index %d\n", best);
    } else {
        int range[2] = {0, 0};
        int result = -1;
        /* TODO: receive range, search DATA[begin..end), and return result. */
        (void)range;
        MPI_Send(&result, 1, MPI_INT, 0, TAG_RESULT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
