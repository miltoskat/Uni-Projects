#include <stdio.h>
#include "mpi.h"


int main(int argc, char** argv) {

	int rank, size;
	int N, i;
	MPI_Init(&argc, &argv); 	// Ενεργοποίηση της MPI.
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &size); // Αρ. Σύνολικών κόμβων.
	if(rank == 0)
	{
		printf("\nDwse N: ");
		scanf("%d", &N);
		printf("\nEimai o master kai tempeliazw\n");
	}
	else
	{
		printf("\nEimai o %d kai doulevw.", rank);
		for(i=0;i<N;i++);
		printf("\nEimai o %d kai teleiwsa.", rank);
	}
	MPI_Finalize(); 		// Απενεργοποίηση της MPI.
	return 0;
}
