#include <mpi.h>
#include <stdio.h>

enum { TAG_CHAIN = 50 };

int main(int argc, char **argv) {
    int rank;
    int size;
    int value = 1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size == 1) {
        printf("final value: %d\n", value);
    } else if (rank == 0) {
        /* TODO: send value to rank 1. */
    } else {
        /* TODO: receive from rank - 1, then add rank. */
        if (rank == size - 1) {
            printf("final value: %d\n", value);
        } else {
            /* TODO: forward value to rank + 1. */
        }
    }

    MPI_Finalize();
    return 0;
}
