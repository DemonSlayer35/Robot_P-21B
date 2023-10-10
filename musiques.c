
#pragma region Music

#define C  956      // Do
#define Cd 902
#define D  851      // Ré
#define Dd 804
#define E  758      // Mi
#define F  716      // Fa
#define Fd 676
#define G  638      // Sol
#define Gd 602
#define A  568      // La
#define Ad 536
#define B  506      // Si

int BLANCHE = 2000;
int NOIRE   = 1000;
int TRIO    =  666;
int CROCHE  =  500;

void play(char* music, unsigned int tempo)
{

    BLANCHE = 120000/tempo;
    NOIRE   =  60000/tempo;
    TRIO    =  40000/tempo;
    CROCHE  =  30000/tempo;

    Mario();

    wait(BLANCHE);wait(BLANCHE);wait(BLANCHE);wait(BLANCHE);
}

void note(unsigned int note, unsigned int tempsms){
    unsigned int j, nombre_de_cycle=0;
    nombre_de_cycle = (500*tempsms)/note;   // = (1000*tempsms) / (2*note)
    for (j=0; j<nombre_de_cycle; j++)
    {
        AX_BuzzerON();
        delayMicroseconds(5*note);
        AX_BuzzerOFF();
        delayMicroseconds(5*note);
    }
    wait(10);
}

void wait(unsigned int tempsms){
    delay(tempsms);
}

void Mario(void){
    note(C/2, CROCHE);
    note(C/2, CROCHE);wait(CROCHE);
    note(C/2, CROCHE);wait(CROCHE);
    note(A, CROCHE);
    note(C/2, NOIRE);
    note(D/2, NOIRE);wait(NOIRE);
    note(G, NOIRE);wait(NOIRE);
    note(C/2, NOIRE);wait(CROCHE);
    note(G, NOIRE);wait(CROCHE);
    note(E, NOIRE);wait(CROCHE);
    note(A, CROCHE);wait(CROCHE);
    note(B, NOIRE);
    note(Ad, CROCHE);
    note(A, NOIRE);
    note(G, TRIO);
    note(E/2, TRIO);
    note(G/2, TRIO);
    note(A/2, NOIRE);
    note(F/2, CROCHE);
    note(G/2, CROCHE);wait(CROCHE);
    note(E/2, NOIRE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);
    note(B, NOIRE);wait(CROCHE);
    note(C/2, NOIRE);wait(CROCHE);
    note(G, NOIRE);wait(CROCHE);
    note(E, NOIRE);wait(CROCHE);
    note(A, CROCHE);wait(CROCHE);
    note(B, NOIRE);
    note(Ad, CROCHE);
    note(A, NOIRE);
    note(G, TRIO);
    note(E/2, TRIO);
    note(G/2, TRIO);
    note(A/2, NOIRE);
    note(F/2, CROCHE);
    note(G/2, CROCHE);wait(CROCHE);
    note(E/2, NOIRE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);
    note(B, NOIRE);wait(CROCHE);wait(NOIRE);
    note(G/2, CROCHE);
    note(Fd/2, CROCHE);
    note(F/2, CROCHE);
    note(Dd/2, NOIRE);
    note(E/2, CROCHE);wait(CROCHE);
    note(Gd, CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);wait(CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);wait(NOIRE);
    note(G/2, CROCHE);
    note(Fd/2, CROCHE);
    note(F/2, CROCHE);
    note(Dd/2, NOIRE);
    note(E/2, CROCHE);wait(CROCHE);
    note(C/4, NOIRE);
    note(C/4, CROCHE);
    note(C/4, NOIRE);wait(NOIRE);wait(NOIRE);
    note(G/2, CROCHE);
    note(Fd/2, CROCHE);
    note(F/2, CROCHE);
    note(Dd/2, NOIRE);
    note(E/2, CROCHE);wait(CROCHE);
    note(Gd, CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);wait(CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);wait(NOIRE);
    note(Dd/2, NOIRE);wait(CROCHE);
    note(D/2, NOIRE+CROCHE);
    note(C/2, NOIRE);wait(CROCHE);
    note(G, NOIRE);wait(CROCHE);
    note(E, NOIRE);wait(CROCHE);
    note(A, CROCHE);wait(CROCHE);
    note(B, NOIRE);
    note(Ad, CROCHE);
    note(A, NOIRE);
    note(G, TRIO);
    note(E/2, TRIO);
    note(G/2, TRIO);
    note(A/2, NOIRE);
    note(F/2, CROCHE);
    note(G/2, CROCHE);wait(CROCHE);
    note(E/2, NOIRE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);
    note(B, NOIRE);wait(CROCHE);wait(NOIRE);
    note(G/2, CROCHE);
    note(Fd/2, CROCHE);
    note(F/2, CROCHE);
    note(Dd/2, NOIRE);
    note(E/2, CROCHE);wait(CROCHE);
    note(Gd, CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);wait(CROCHE);
    note(A, CROCHE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);wait(NOIRE);
    note(Dd/2, NOIRE);wait(CROCHE);
    note(D/2, NOIRE+CROCHE);
    note(C/2, NOIRE);
}

void StarWars(void){
/*    note(D, NOIRE);
    note(G, BLANCHE);
    note(A, NOIRE+CROCHE);
    note(B, CROCHE/2);
    note(C/2, CROCHE/2);
    note(B, BLANCHE);
    note(D, NOIRE);
    note(D, NOIRE);
    note(G, NOIRE+CROCHE);
    note(A, CROCHE);
    note(B, CROCHE);
    note(D, CROCHE);
    note(B, NOIRE/3);
    note(G, NOIRE/3);
    note(D/2, NOIRE/3);

    note(C/2, BLANCHE+NOIRE);
    note(D, CROCHE+CROCHE/2);
    note(D, CROCHE/2);
    note(G, BLANCHE);
    note(A, NOIRE+CROCHE);
    note(B, CROCHE/2);
    note(C/2, CROCHE/2);
    note(B, BLANCHE);
    note(D, NOIRE);
    note(D, NOIRE);

    note(G, NOIRE+CROCHE);
    note(A, CROCHE);
    note(B, CROCHE);
    note(D, CROCHE);
    note(B, NOIRE/3);
    note(G, NOIRE/3);
    note(D/2, NOIRE/3);
    note(C/2, BLANCHE+NOIRE);
    note(D, CROCHE+CROCHE/2);
    note(D, CROCHE/2);
    note(D, NOIRE+CROCHE+CROCHE/2);
    note(D, CROCHE/2);
    note(G, CROCHE+CROCHE/2);
    note(G, CROCHE/2);
    note(B, CROCHE+CROCHE/2);
    note(B, CROCHE/2);

    note(B/2, BLANCHE);
    note(B, CROCHE+CROCHE/2);
    note(G, CROCHE/2);
    note(B, NOIRE/3);
    note(A, NOIRE/3);
    note(G, NOIRE/3);
    note(D/2, NOIRE+CROCHE);
    note(B, CROCHE/2);
    note(G, CROCHE/2);
    note(D, NOIRE);
    note(D, CROCHE+CROCHE/2);
    note(D, CROCHE/2);
    note(G, BLANCHE+BLANCHE);
*/
////////////////////////////////////////////////
    BLANCHE = 120000/120;
    NOIRE   =  60000/120;
    TRIO    =  40000/120;
    CROCHE  =  30000/120;

    note(G, CROCHE/2);
    note(G, CROCHE/2);
    note(G, NOIRE+CROCHE);
    note(G, CROCHE);
    note(G, CROCHE);
    note(G, CROCHE);

    note(G, CROCHE);
    note(D, CROCHE);
    note(C/2, CROCHE);
    note(E, CROCHE);
    note(D, CROCHE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);
    note(C/2, CROCHE);
    note(G, CROCHE);
    note(G, CROCHE);
    note(D, CROCHE);
    note(C/2, CROCHE);

    note(D/2, CROCHE);
    note(C/2, CROCHE);
    note(G, CROCHE);
    note(D, CROCHE);
    note(C/2, CROCHE);
    note(D/2, CROCHE);
    note(G, CROCHE/2);
    note(G, CROCHE/2);
    note(G, CROCHE);
}

void LaFamilleTortue(void){
    note(A*2, CROCHE);
    note(Ad*2, CROCHE);
    note(C, NOIRE);
    note(A, NOIRE);
    note(A, CROCHE);
    note(G, CROCHE);
    note(F, CROCHE);
    note(E, CROCHE);
    note(G, NOIRE);
    note(D, NOIRE);
    note(D, NOIRE);
    note(G*2, CROCHE);
    note(A*2, CROCHE);

    note(Ad*2, NOIRE);
    note(G, NOIRE);
    note(G, CROCHE);
    note(F, CROCHE);
    note(E, CROCHE);
    note(D, CROCHE);
    note(F, NOIRE);
    note(C, NOIRE);
    note(C, NOIRE);
    note(A*2, CROCHE);
    note(Ad*2, CROCHE);
    note(C, NOIRE);
    note(A, NOIRE);
    note(A, CROCHE);
    note(G, CROCHE);
    note(F, CROCHE);
    note(E, CROCHE);

    note(D, NOIRE);
    note(Ad, NOIRE);
    note(Ad, CROCHE);
    note(A, CROCHE);
    note(G, CROCHE);
    note(F, CROCHE);
    note(E, NOIRE);
    note(C/2, NOIRE);
    note(C/2, CROCHE);
    note(Ad, CROCHE);
    note(A, CROCHE);
    note(G, CROCHE);
    note(F, NOIRE);
    note(A, NOIRE);
    note(F, NOIRE);
}

void HarryPotter(void){
    note(B, NOIRE);
    note(E/2, NOIRE+CROCHE);
    note(G/2, CROCHE);
    note(Fd/2, NOIRE);
    note(E/2, BLANCHE);
    note(B/2, NOIRE);
    note(A/2, BLANCHE+NOIRE);
    note(Fd/2, BLANCHE+NOIRE);
    note(E/2, NOIRE+CROCHE);
    note(G/2, CROCHE);
    note(Fd/2, NOIRE);
    note(Dd/2, BLANCHE);
    note(F/2, NOIRE);
    note(B, BLANCHE*2+NOIRE);

    note(B, NOIRE);
    note(E/2, NOIRE+CROCHE);
    note(G/2, CROCHE);
    note(Fd/2, NOIRE);
    note(E/2, BLANCHE);
    note(B/2, NOIRE);
    note(D/4, BLANCHE);
    note(Cd/4, NOIRE);
    note(C/4, BLANCHE);
    note(Gd/2, NOIRE);
    note(C/4, NOIRE+CROCHE);
    note(B/2, CROCHE);
    note(Ad/2, NOIRE);
    note(Ad, BLANCHE);
    note(G/2, NOIRE);
    note(E/2, BLANCHE+NOIRE);wait(BLANCHE);

    note(G/2, NOIRE);
    note(B/2, BLANCHE);
    note(G/2, NOIRE);
    note(B/2, BLANCHE);
    note(G/2, NOIRE);
    note(C/4, BLANCHE);
    note(B/2, NOIRE);
    note(Ad/2, BLANCHE);
    note(Fd/2, NOIRE);
    note(G/2, NOIRE+CROCHE);
    note(B/2, CROCHE);
    note(Ad/2, NOIRE);
    note(Ad, BLANCHE);
    note(B, NOIRE);
    note(B/2, BLANCHE*2+NOIRE);

    note(G/2, NOIRE);
    note(B/2, BLANCHE);
    note(G/2, NOIRE);
    note(B/2, BLANCHE);
    note(G/2, NOIRE);
    note(D/4, BLANCHE);
    note(Cd/4, NOIRE);
    note(C/4, BLANCHE);
    note(Gd/2, NOIRE);
    note(C/4, NOIRE+CROCHE);
    note(B/2, CROCHE);
    note(Ad/2, NOIRE);
    note(Ad, BLANCHE);
    note(G/2, NOIRE);
    note(E/2, BLANCHE+NOIRE);
}

#pragma endregion Music

// play("Mario",200); // appel de la fonction de musique
/*
Il faudrait ajouter un string compare pour vérifier la chaîne de caractères entrée
et jouer la musique correspondante dans la fonction play(), mais j'ai la flemme.
Faites-le vous-même pour apprendre, vu que j'ai déjà codé le reste et vous ne
voulez sûrement pas corriger le PID ou ajouter les culs-de-sac et les lignes de tape
à la logique du programme du robot.
*/