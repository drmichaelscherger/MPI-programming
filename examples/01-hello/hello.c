#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int rank;
    int size;
    int local_value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    local_value = 100 + rank;
    printf("Hello from rank %d of %d; my local value is %d\n",
           rank, size, local_value);

    MPI_Finalize();
    return 0;
}
