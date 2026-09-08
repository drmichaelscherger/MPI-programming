#include <mpi.h>
#include <stdio.h>

enum { TAG_TOKEN = 30 };

int main(int argc, char **argv) {
    int rank;
    int size;
    int token = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size == 1) {
        printf("rank 0 holds token 0; ring is complete\n");
        MPI_Finalize();
        return 0;
    }

    const int predecessor = (rank - 1 + size) % size;
    const int successor = (rank + 1) % size;

    if (rank == 0) {
        printf("rank 0 injects token %d\n", token);
        MPI_Send(&token, 1, MPI_INT, successor, TAG_TOKEN, MPI_COMM_WORLD);
        MPI_Recv(&token, 1, MPI_INT, predecessor, TAG_TOKEN,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("rank 0 received completed token %d\n", token);
    } else {
        MPI_Recv(&token, 1, MPI_INT, predecessor, TAG_TOKEN,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        ++token;
        printf("rank %d forwards token %d to rank %d\n",
               rank, token, successor);
        MPI_Send(&token, 1, MPI_INT, successor, TAG_TOKEN, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
