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
        MPI_Send(&value, 1, MPI_INT, 1, TAG_CHAIN, MPI_COMM_WORLD);
    } else {
        MPI_Recv(&value, 1, MPI_INT, rank - 1, TAG_CHAIN,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        value += rank;
        if (rank == size - 1) {
            printf("final value: %d\n", value);
        } else {
            MPI_Send(&value, 1, MPI_INT, rank + 1, TAG_CHAIN,
                     MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
