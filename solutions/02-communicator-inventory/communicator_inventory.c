#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank;
    int size;
    int name_length;
    char name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(name, &name_length);

    const double start = MPI_Wtime();
    for (int turn = 0; turn < size; ++turn) {
        MPI_Barrier(MPI_COMM_WORLD);
        if (rank == turn) {
            printf("rank %d/%d on %.*s at +%.6f s\n",
                   rank, size, name_length, name, MPI_Wtime() - start);
            fflush(stdout);
        }
    }

    MPI_Finalize();
    return 0;
}
