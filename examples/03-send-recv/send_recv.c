#include <mpi.h>
#include <stdio.h>

enum { TAG_GREETING = 10 };

int main(int argc, char **argv) {
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0) {
            fprintf(stderr, "Run this example with exactly 2 processes.\n");
        }
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        const int value = 42;
        MPI_Send(&value, 1, MPI_INT, 1, TAG_GREETING, MPI_COMM_WORLD);
        printf("rank 0 sent %d to rank 1\n", value);
    } else {
        int value = 0;
        MPI_Status status;
        MPI_Recv(&value, 1, MPI_INT, 0, TAG_GREETING,
                 MPI_COMM_WORLD, &status);
        printf("rank 1 received %d from rank %d with tag %d\n",
               value, status.MPI_SOURCE, status.MPI_TAG);
    }

    MPI_Finalize();
    return 0;
}
