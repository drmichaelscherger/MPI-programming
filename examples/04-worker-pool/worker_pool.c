#include <mpi.h>
#include <stdio.h>

enum { TAG_WORK = 40, TAG_RESULT = 41 };

static int square(int value) {
    return value * value;
}

int main(int argc, char **argv) {
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0) fprintf(stderr, "Run with at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        for (int worker = 1; worker < size; ++worker) {
            const int work = worker + 2;
            MPI_Send(&work, 1, MPI_INT, worker, TAG_WORK, MPI_COMM_WORLD);
        }
        for (int completed = 1; completed < size; ++completed) {
            int result[2];
            MPI_Status status;
            MPI_Recv(result, 2, MPI_INT, MPI_ANY_SOURCE, TAG_RESULT,
                     MPI_COMM_WORLD, &status);
            printf("worker %d: %d squared is %d\n",
                   status.MPI_SOURCE, result[0], result[1]);
        }
    } else {
        int work;
        int result[2];
        MPI_Recv(&work, 1, MPI_INT, 0, TAG_WORK,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        result[0] = work;
        result[1] = square(work);
        MPI_Send(result, 2, MPI_INT, 0, TAG_RESULT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
