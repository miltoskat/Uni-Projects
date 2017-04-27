#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char** argv) {
	int N,i,sum=0,sum_total=0;
	int upperbound,lowerbound,part;
	int rank,size;
	double ta,tt;
	float avg;
	int* A;
	MPI_Init(&argc, &argv); 	                        // Ενεργοποίηση της MPI.
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);            // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &size);           // Αρ. Σύνολικών κόμβων.
	if(argc<2){
		if(rank==0){
			printf("\n Please give N: ");
			scanf("%d", &N);
		}
	}else{
		N=atoi(argv[1]);
	}
	ta=MPI_Wtime();
	MPI_Bcast(&N,1,MPI_INT,0,MPI_COMM_WORLD);      // Broadcast του N από τον Master
		A=malloc(N*sizeof(int));
		for(i=0;i<N;i++){
			A[i]=rand()%1000;
			//A[i]=10;
			printf("\n A[%d]: %d", i,A[i]);
		}
		part=N/size;
		lowerbound=part*rank;
		upperbound=(part*rank)+part;
		for(i=lowerbound;i<upperbound;i++){
			sum=sum+A[i];
		}
		printf("\n Local sum: %d\n Rank: %d", sum,rank);
	MPI_Reduce(&sum,&sum_total,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0){
		avg=sum_total/N;
		tt=MPI_Wtime();
		printf("\nTime: %0.5f", tt-ta);
		printf("\nSum_total: %d", sum_total);
		printf("\nAverage: %0.5f\n", avg);

	}
	MPI_Finalize();
	return 0;
}
