#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int rank = -1;
    int size = 0;

    MPI_Init(&argc, &argv);
    /* TODO: query rank and size from MPI_COMM_WORLD. */

    int local_value = 0; /* TODO: compute the rank-dependent value. */
    printf("rank=%d size=%d pid=%ld address=%p value=%d\n",
           rank, size, (long)getpid(), (void *)&local_value, local_value);

    MPI_Finalize();
    return 0;
}
