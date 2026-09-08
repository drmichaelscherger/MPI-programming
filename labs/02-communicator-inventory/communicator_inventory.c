#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank = -1;
    int size = 0;
    int name_length = 0;
    char name[MPI_MAX_PROCESSOR_NAME] = "unknown";

    MPI_Init(&argc, &argv);
    /* TODO: query rank, size, and processor name. */

    const double start = MPI_Wtime();
    for (int turn = 0; turn < size; ++turn) {
        /* TODO: synchronize every rank on every iteration. */
        if (rank == turn) {
            printf("rank %d/%d on %.*s at +%.6f s\n",
                   rank, size, name_length, name, MPI_Wtime() - start);
            fflush(stdout);
        }
    }

    MPI_Finalize();
    return 0;
}
