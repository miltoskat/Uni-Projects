#include <stdio.h>
#include "mpi.h"


int main(int argc, char** argv) {

	int rank, size;
	int N=10;
	MPI_Init(&argc, &argv); 	// Ενεργοποίηση της MPI.
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &size); // Αρ. Σύνολικών κόμβων.

	if(rank == 0){
		MPI_Send(&N,1,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Recv(&N,1,MPI_INT,size-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("\n Eimai o master kai to Teliko N=%d\n", N);
	}
	else{
		MPI_Recv(&N,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("\n Eimai o %d kai to N= %d*2\n",rank,N );
		N=N*2;
		MPI_Send(&N,1,MPI_INT,(rank+1)%size,0,MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}
