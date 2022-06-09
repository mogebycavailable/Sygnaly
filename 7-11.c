#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//podstawowa wersja programu wyświetla cykliczne 3 napisy po naciśnięciu CTRL+C
//zakończenie programu CTRL+\ (SIGQUIT)

char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\
n", "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n",
"Auć - to bolało!\n"};
int nr_napisu=0;

void obsluga_sig_int(int sig) {

	printf(napisy[nr_napisu],getpid(),sig);
	if(nr_napisu == 3)
	{
		printf("Dobrze! Dobrze! Juz koncze...\n");
		exit(0);
	}else{ nr_napisu++; }
}

int main(int argc, char** argv) {

	signal(SIGINT,obsluga_sig_int);


	while ( 1 ) {

		printf("Cześć tu proces: %d\n",getpid());
		sleep(1);
	}

	return 0;
}

