#include <limits.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

enum { TAG_RANGE = 60, TAG_RESULT = 61 };
static const int DATA[] = {4, 7, 1, 9, 7, 3, 8, 2, 7, 5, 6, 0};
static const int DATA_COUNT = (int)(sizeof(DATA) / sizeof(DATA[0]));

int main(int argc, char **argv) {
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2 || argc != 2) {
        if (rank == 0) fprintf(stderr, "Usage: mpirun -np N %s TARGET (N >= 2)\n", argv[0]);
        MPI_Finalize();
        return 1;
    }

    const int target = atoi(argv[1]);
    if (rank == 0) {
        const int workers = size - 1;
        int best = INT_MAX;

        for (int worker = 1; worker < size; ++worker) {
            const int index = worker - 1;
            const int range[2] = {
                index * DATA_COUNT / workers,
                (index + 1) * DATA_COUNT / workers
            };
            MPI_Send(range, 2, MPI_INT, worker, TAG_RANGE, MPI_COMM_WORLD);
        }

        for (int completed = 0; completed < workers; ++completed) {
            int result;
            MPI_Status status;
            MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE, TAG_RESULT,
                     MPI_COMM_WORLD, &status);
            if (result >= 0 && result < best) best = result;
        }

        if (best == INT_MAX) {
            printf("target %d: not found\n", target);
        } else {
            printf("target %d: found at index %d\n", target, best);
        }
    } else {
        int range[2];
        int result = -1;

        MPI_Recv(range, 2, MPI_INT, 0, TAG_RANGE,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = range[0]; i < range[1]; ++i) {
            if (DATA[i] == target) {
                result = i;
                break;
            }
        }
        MPI_Send(&result, 1, MPI_INT, 0, TAG_RESULT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
