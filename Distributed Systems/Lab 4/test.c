#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv) {

  int s=0,p,N,d,protos;
  int ego,P;
  double ta,tt;
  MPI_Init(&argc, &argv); 	// Ενεργοποίηση της MPI.
  MPI_Comm_rank(MPI_COMM_WORLD, &ego); // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &P); // Αρ. Σύνολικών κόμβων.
  printf("\n Please give N: ");
  scanf("%d", &N);
  ta=MPI_Wtime();
  s=0;
  for(p=1;p<=N;p++){
    protos=0;
    for(d=2;d<=p/2;d++){
      if(p%d==0){
        protos=1;
      }
    }
    if(protos==0)
      s++;

  }
  tt=MPI_Wtime();
  printf("\nPrime numbers found:%d\n", s);
  printf("\n\nTime = %6f\n\n", tt-ta);



  MPI_Finalize();
  return 0;
}
