#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_value = (rank + 1) * 10;
    printf("rank=%d size=%d pid=%ld address=%p value=%d\n",
           rank, size, (long)getpid(), (void *)&local_value, local_value);

    MPI_Finalize();
    return 0;
}
