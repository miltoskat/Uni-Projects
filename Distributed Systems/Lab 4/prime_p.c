#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv) {

  int s=0,i,N,d,prime;
  int s_total=0;
  int rank,size;
  double ta,tt;
  MPI_Init(&argc, &argv); 	                        // Ενεργοποίηση της MPI.
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);            // Βρές ποιός κόμβος είσαι.
	MPI_Comm_size(MPI_COMM_WORLD, &size);           // Αρ. Σύνολικών κόμβων.
  if(rank==0){                                   // Έλεγχος για τον Master
    printf("\n Please give N: ");
    scanf("%d", &N);
  }
  ta=MPI_Wtime();                                // Αρχή του Timer
  MPI_Bcast(&N,1,MPI_INT,0,MPI_COMM_WORLD);      // Broadcast του N από τον Master
  if(rank!=0){                                   // Έλεγχος για τον Worker
    s=0;                                         // Μηδενισμός του Sum (s)
    for(i=rank;i<=N;i+=size){                    // Επανάληψη που θα εκτελέσει ο κάθε worker
      prime=0;                                   // Μηδενισμός Flag εύρεσης πρώτου
      for(d=2;d<=i/2;d++){                       // Διαδικασία εύρεσης πρώτου
        if(i%d==0){
          prime=1;                               // Αν δεν βρέθηκε πρώτος flag=1
        }
      }
    	if(prime==0){
				printf("\nPrime number found: %3d By Worker:%d", i,rank);
				s++;
			}
    }
  }
  MPI_Reduce(&s,&s_total,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
  tt=MPI_Wtime();
  if(rank==0){
    printf("\n\nPrime numbers found:%d\n", s_total);
    printf("\n\nTime = %6f\n\n", tt-ta);
  }

  MPI_Finalize();
  return 0;
}
