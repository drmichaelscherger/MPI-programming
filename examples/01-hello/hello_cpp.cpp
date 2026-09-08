#include <mpi.h>

#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank = 0;
    int size = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::ostringstream line;
    line << "C++ hello from rank " << rank << " of " << size
         << "; local square = " << rank * rank << '\n';
    std::cout << line.str();

    MPI_Finalize();
    return 0;
}
