//Εύρεση μέγιστου στοιχείου και της θέσης του.
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char** argv) {
	int ego,P;
	int *A; //πίνακας
	int N; //μέγεθος
	int pos; //Θέση του μεγαλύτερου στοιχείου
	int *Max;
	int i;
	double ta,tt;
	MPI_Init(&argc, &argv); 	                        // Ενεργοποίηση της MPI.
  MPI_Comm_rank(MPI_COMM_WORLD, &ego);            // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &P);           // Αρ. Σύνολικών κόμβων.


	if(ego==0){
		printf("\n  Παρακαλώ δώστε το μέγεθος του πίνακα: ");
		scanf("%d", &N);
		ta=MPI_Wtime();
		Max=malloc(P*sizeof(int));
	}
	MPI_Bcast(&N,1,MPI_INT,0,MPI_COMM_WORLD);
	A=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		A[i]=rand()%100;
		//A[i]=10;
	}
	pos=0;
	for(i=ego;i<N;i+=P){
		if(A[i]>A[pos]){
			pos=i;
		}
	}
	if(ego!=0){
		MPI_Send(&pos,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	if(ego==0){
		for(i=1;i<P;i++){
			MPI_Recv(&Max[i],1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		}
		Max[0]=pos;
		pos=0;
		for(i=1;i<P;i++){
			if(Max[i]>Max[pos]){
				pos=i;
			}
		}
		tt=MPI_Wtime();
		printf("\n\n Θέση = %d Στοιχείο = %d \n\n",Max[pos],A[Max[pos]]);
		printf("\n\n Χρόνος = %10.5f\n",tt-ta );
	}

	MPI_Finalize();

	return 0;
}
