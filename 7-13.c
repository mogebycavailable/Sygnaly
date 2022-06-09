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

	nr_napisu=((nr_napisu + 1) % 3);
}

void obsluga_sig_alrm(int sig) {
	signal(SIGINT, SIG_DFL);
	printf("Ding! Ding! Ding! Przywracam domyslne ustawienia Ctrl+C\n");
}

int main(int argc, char** argv) {

	signal(SIGINT, obsluga_sig_int);
	signal(SIGALRM, obsluga_sig_alrm);

	int timer = 15;

	while ( 1 ) {
		
		printf("Cześć tu proces: %d\n",getpid());
		sleep(1);
		timer--;
		if(timer == 0)
		{
			kill(getpid(), SIGALRM);
		}
	}

	return 0;
}

