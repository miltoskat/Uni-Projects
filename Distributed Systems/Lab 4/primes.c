#include <primesieve.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	if(argc<2){
		printf("\n\n No arguments present \n Please input an upperbound number for prime number count\n\n");
		return -1;
	}
  unsigned int count = primesieve_count_primes(0, atoi(argv[1]));
  printf("Primes below %s = %d\n" ,argv[1], count);

  return 0;
}
