#include <iostream> 
#include <thread> 
#include <semaphore.h> 
#include <unistd.h> 

using namespace std;

sem_t sem;


/***************************************
** Thread � ex�cuter en 1er
****************************************/
void CodeThread1() {
	sleep(1);
	cout << "Ceci est une phrase ";
        sem_post(&sem);
}

/*************************************** 
** Thread � ex�cuter en 2eme
****************************************/
void CodeThread2() {
        sem_wait(&sem);
	cout << "affichee forcement dans l'ordre.\n";
}

/*************************************************************
** Initialisation du semaphore, cr�ation des deux threads et
** attente de leur terminaison.
**************************************************************/
int main (void) { 
    
    sem_init(&sem, 0, 0);

    thread Thread1(CodeThread1);
    thread Thread2(CodeThread2);

    Thread1.join();
    Thread2.join();

    sem_destroy(&sem);

    return 0;
}
