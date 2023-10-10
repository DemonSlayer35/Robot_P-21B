/**
 * @file   main.ino
 * Équipe: P-21B
 * @author Mohammad Barin Wahidi, Cédrick Pelchat
 *         et les autres (Cédric Charbonneau et Mathias Cloutier)
 * @date   9 octobre 2023
 * @brief  Code brisé pour le défi du parcours
 *
 * @version 1.0 : Première version
 */

/*
Inclure les librairies de fonctions que vous voulez utiliser
*/
#include <LibRobus.h> // Essentielle pour utiliser RobUS

/*
Variables globales et defines
 -> defines...
 -> L'ensemble des fonctions y ont accès
*/
#define AVANT 0
#define GAUCHE 1
#define DROITE 2

#define CHEMIN_G 0
#define CHEMIN_M 1
#define CHEMIN_D 2

const float KD = 0.00001; // facteur de pondération pour ajuster la vitesse de droite
const float KG = 0.00001; // facteur de pondération pour ajuster la vitesse de gauche

const float KDA = 0.00004; // facteur de pondération pour ajuster la vitesse de droite (angles)
const float KGA = 0.00001; // facteur de pondération pour ajuster la vitesse de gauche (angles)

const int CLICS_PAR_CYCLE = 835; // nombre de clics attendus par cycle
const int TOUR = 3342; // 3342/4=835
const int CASE = 2 * TOUR; // 6684

const int ANGLE_PAR_CYCLE = 15;
const int CLICS_PAR_15 = 332; // 1995/6=332

/*
Vos propres fonctions sont créées ici
*/

/**
 * @brief Fait avancer le robot à la vitesse demandée
 * @param vitessed vitesse désirée du moteur droit
 * @param vitesseg vitesse désirée du moteur gauche
 * @return void
 */
void avance(float vitessed, float vitesseg){
  MOTOR_SetSpeed(RIGHT,vitessed);
  MOTOR_SetSpeed(LEFT, vitesseg);
}

/**
 * @brief Arrête le robot
 * @param Aucun
 * @return void
 */
void arret(){
  MOTOR_SetSpeed(RIGHT, 0);
  MOTOR_SetSpeed(LEFT, 0);
}

/**
 * @brief Fait tourner le robot vers la droite
 * @param vitessed vitesse désirée du moteur droit
 * @param vitesseg vitesse désirée du moteur gauche
 * @return void
 */
void tourneDroit(float vitessed, float vitesseg){
  MOTOR_SetSpeed(RIGHT, -1 * vitessed);
  MOTOR_SetSpeed(LEFT, vitesseg);
}

/**
 * @brief Fait tourner le robot vers la gauche
 * @param vitessed vitesse désirée du moteur droit
 * @param vitesseg vitesse désirée du moteur gauche
 * @return void
 */
void tourneGauche(float vitessed, float vitesseg){
  MOTOR_SetSpeed(RIGHT, vitessed);
  MOTOR_SetSpeed(LEFT, -1 * vitesseg);
};

/**
 * @brief Fait avancer le robot pour la distance demandée
 * @param distance distance désirée en pulses
 * @return void
 */
void forward(int distance)
{
  float vitessed = 0.307; // Commande de vitesse envoyée par l’utilisateur
  float vitesseg = 0.30; 

  int32_t encRight = ENCODER_ReadReset(RIGHT); // Remise à zéro des encodeurs (par une lecture)
  int32_t encLeft = ENCODER_ReadReset(LEFT);

  int i = 0; // déclaration et initialisation d'un compteur de cycles à 0
  int cycles = distance / CLICS_PAR_CYCLE;
  // int moyenned = 0;
  // int moyenneg = 0;

  do
  {
    avance(vitessed, vitesseg); // Envoyer la commande de vitesse aux roues

    delay(250); // Pause de temps fixe
    arret();

    encRight = ENCODER_ReadReset(RIGHT); // Lecture des encodeurs (nombre de clics réels)
    encLeft = ENCODER_ReadReset(LEFT);

    // Serial.print("moteur droit:");
    // Serial.print(encRight);
    // Serial.print("\tmoteur gauche:");
    // Serial.println(encLeft);

    if(encRight != CLICS_PAR_CYCLE) // Nb clics réel == nb clics attendu
    {
      vitessed = vitessed + (KD * (CLICS_PAR_CYCLE - encRight));
      // Serial.print("droite corigée :");
      // Serial.print(vitessed);
    }
    if(encLeft != CLICS_PAR_CYCLE) // Nb clics réel == nb clics attendu
    {
      vitesseg = vitesseg + (KG * (CLICS_PAR_CYCLE - encLeft));
      // Serial.print("\tgauche corigée :");
      // Serial.println(vitesseg);
    }
    i++; // incrémentation du compteur
    // moyenned += encRight;
    // moyenneg += encLeft;
  } while (i < cycles); // Commande d’arrêt du programme?
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  // moyenned = moyenned / cycles;
  // moyenneg = moyenneg / cycles;
  // Serial.println("FIN-D");
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  arret();
  delay(50);
}

/**
 * @brief Fait tourner le robot pour l'angle demandé vers la droite
 * @param angle angle désiré de rotation
 * @return void
 */
void spinRight(int angle)
{
  float vitessed = 0.1412; // Commande de vitesse envoyée par l’utilisateur
  float vitesseg = 0.1412;

  int32_t encRight = ENCODER_ReadReset(RIGHT); // Remise à zéro des encodeurs (par une lecture)
  int32_t encLeft = ENCODER_ReadReset(LEFT);

  int i = 0; // déclaration et initialisation d'un compteur de cycles à 0
  int cycles = angle / ANGLE_PAR_CYCLE;
  // int moyenned = 0;
  // int moyenneg = 0;

  do
  {
    tourneDroit(vitessed, vitesseg); // Envoyer la commande de vitesse aux roues

    delay(250); // Pause de temps fixe
    arret();
    delay(10);

    encRight = ENCODER_ReadReset(RIGHT); // Lecture des encodeurs (nombre de clics réels)
    encLeft = ENCODER_ReadReset(LEFT);

    // Serial.print("moteur droit:");
    // Serial.print(encRight);
    // Serial.print("\tmoteur gauche:");
    // Serial.println(encLeft);

    if(encRight != -CLICS_PAR_15) // Nb clics réel == nb clics attendu
    {
      vitessed = vitessed - (KDA * (-CLICS_PAR_15 - encRight));
      // Serial.print("droite corigée :");
      // Serial.print(vitessed);
    }
    if(encLeft != CLICS_PAR_15) // Nb clics réel == nb clics attendu
    {
      vitesseg = vitesseg + (KGA * (CLICS_PAR_15 - encLeft));
      // Serial.print("\tgauche corigée :");
      // Serial.println(vitesseg);
    }
    i++; // incrémentation du compteur
    // moyenned += encRight;
    // moyenneg += encLeft;
  } while (i < cycles); // Commande d’arrêt du programme?
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  // moyenned = moyenned / cycles;
  // moyenneg = moyenneg / cycles;
  // Serial.println("FIN-D");
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  arret();
  delay(50);
}

/**
 * @brief Fait tourner le robot pour l'angle demandé vers la gauche
 * @param angle angle désiré de rotation
 * @return void
 */
void spinLeft(int angle)
{
  float vitessed = 0.1387; // Commande de vitesse envoyée par l’utilisateur
  float vitesseg = 0.1387;

  int32_t encRight = ENCODER_ReadReset(RIGHT); // Remise à zéro des encodeurs (par une lecture)
  int32_t encLeft = ENCODER_ReadReset(LEFT);

  int i = 0; // déclaration et initialisation d'un compteur de cycles à 0
  int cycles = angle / ANGLE_PAR_CYCLE;
  // int moyenned = 0;
  // int moyenneg = 0;

  do
  {
    tourneGauche(vitessed, vitesseg); // Envoyer la commande de vitesse aux roues

    delay(250); // Pause de temps fixe
    arret();
    delay(10);

    encRight = ENCODER_ReadReset(RIGHT); // Lecture des encodeurs (nombre de clics réels)
    encLeft = ENCODER_ReadReset(LEFT);

    // Serial.print("moteur droit:");
    // Serial.print(encRight);
    // Serial.print("\tmoteur gauche:");
    // Serial.println(encLeft);

    if(encRight != -CLICS_PAR_15) // Nb clics réel == nb clics attendu
    {
      vitessed = vitessed + (KDA * (CLICS_PAR_15 - encRight));
      // Serial.print("droite corigée :");
      // Serial.print(vitessed);
    }
    if(encLeft != CLICS_PAR_15) // Nb clics réel == nb clics attendu
    {
      vitesseg = vitesseg - (KG * (-CLICS_PAR_15 - encLeft));
      // Serial.print("\tgauche corigée :");
      // Serial.println(vitesseg);
    }
    i++; // incrémentation du compteur
    // moyenned += encRight;
    // moyenneg += encLeft;
  } while (i < cycles); // Commande d’arrêt du programme?
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  // moyenned = moyenned / cycles;
  // moyenneg = moyenneg / cycles;
  // Serial.println("FIN-D");
  // Serial.println(moyenned);
  // Serial.println(moyenneg);
  arret();
  delay(50);
}

/**
 * @brief Vérifie s'il y a un obstacle devant (deux DELs allumées)
 * @param Aucun
 * @return True si un obstacle est détecté, False sinon
 */
bool detectObs()
{
  int vertpin = 44;
  int rougepin = 45;
  if((digitalRead(vertpin) || digitalRead(rougepin)) == false)
    return true;
  else
    return false;
}

/**
 * @brief Réinitialise les possibilités du tableau des chemins par rangée à true
 * @param tableau_Chemins pointeur du tableau à réinitialiser
 * @return void
 */
void resetTab(bool* tableau_Chemins)
{
  for(int i = 0; i < 3; i++)
  {
    tableau_Chemins[i] = true;
  }
}

/*
Fonctions d'initialisation (setup)
 -> Se fait appeler au début du programme
 -> Se fait appeler seulement une fois
 -> Généralement on y initialise les variables globales
*/
void setup(){
 BoardInit();
}

/*
Fonctions de boucle infinie
 -> Se fait appeler perpétuellement suite au "setup"
*/
void loop(){
  int rangee = 0;
  int colonne = 1;
  int orientation = AVANT; // Initialise l'orientation à l'avant

  bool demitour = false; // Initialise la variable de demi-tour à false
  bool tableau_Chemins[3] = {true, true, true}; // Initialise le tableau des chemins à true

  while(rangee < 10) // Boucle tant que nous ne sommes pas à la dernière rangée
  {
    switch (orientation) // Commence à évaluer l'orientation
    {
    case AVANT: // Si le robot est orienté vers l'avant
      if(!detectObs()) // S'il n'y a pas d'obstacle devant
      {
        forward(CASE); // Avance d'une case
        rangee++; // Incrémente la rangée
        resetTab(tableau_Chemins); // Réinitialise le tableau des chemins
      }
      else if(colonne == 0) // Si nous sommes à la colonne gauche (et obstacle détecté)
      {
        tableau_Chemins[CHEMIN_G] = false; // Marque le chemin gauche comme impossible
        spinRight(90); // Tourne à droite
        forward(CASE); // Avance d'une case
        spinLeft(90); // Tourne à gauche
        colonne++; // Incrémente la colonne
      }
      else if(colonne == 1) // Si nous sommes à la colonne centrale (et obstacle détecté)
      {
        tableau_Chemins[CHEMIN_M] = false; // Marque le chemin du milieu comme impossible
        if(tableau_Chemins[CHEMIN_D] == true) // Si le chemin droit est possible
        {
          spinRight(90); // Tourne à droite
          if(!detectObs()) // S'il n'y a pas d'obstacle devant
          {
            forward(CASE); // Avance d'une case
            spinLeft(90); // Tourne à gauche
            
            if(!detectObs()) // S'il n'y a pas d'obstacle devant
            {
              forward(CASE); // Avance d'une case
              colonne++; // Incrémente la colonne
              rangee++; // Incrémente la rangée
              resetTab(tableau_Chemins); // Réinitialise le tableau des chemins
            }
            else // S'il y a un obstacle devant
            {
              tableau_Chemins[CHEMIN_D] = false; // Marque le chemin de droite comme impossible
              colonne++; // Incrémente la colonne
            }
          }
          else // S'il y a un obstacle devant
          {
            orientation = DROITE; // Met l'orientation vers la droite
            tableau_Chemins[CHEMIN_D] = false; // Marque le chemin de droite comme impossible
          }
        }
        else if(tableau_Chemins[CHEMIN_G] == true) // Si le chemin gauche est possible
        {
          spinLeft(90); // Tourne à gauche
          if(!detectObs()) // S'il n'y a pas d'obstacle devant
          {
            forward(CASE); // Avance d'une case
            spinRight(90); // Tourne à droite

            if(!detectObs()) // S'il n'y a pas d'obstacle devant
            {
              forward(CASE); // Avance d'une case
              colonne--; // Décrémente la colonne
              rangee++; // Incrémente la rangée
              resetTab(tableau_Chemins); // Réinitialise le tableau des chemins
            }
            else // S'il y a pas un obstacle devant
            {
              tableau_Chemins[CHEMIN_G] = false; // Marque le chemin de gauche comme impossible
              colonne--; // Décrémente la colonne
            }

          }
          else // S'il y a pas un obstacle devant
          {
            orientation = GAUCHE; // Met l'orientation vers la gauche
            tableau_Chemins[CHEMIN_G] = false; // Marque le chemin de gauche comme impossible
          }
        }
      }
      else if(colonne == 2) // Si nous sommes à la colonne droite (et obstacle détecté)
      {
        tableau_Chemins[CHEMIN_D] = false;
        spinLeft(90); // Tourne à gauche
        forward(CASE); // Avance d'une case
        spinRight(90); // Tourne à gauche
        colonne--; // Décrémente la colonne
      }
      break;

    case GAUCHE: // Si le robot est orienté vers la gauche
      spinRight(90); // Tourne à droite
      spinRight(90); // Tourne à droite (pour faire un demi-tour)
      forward(CASE); // Avance d'une case
      spinLeft(90); // Tourne à gauche
      orientation = AVANT; // Remet l'orientation à l'avant
      colonne++; // Incrémente la colonne
      break;

    case DROITE: // Si le robot est orienté vers la droite
      spinLeft(90); // Tourne à gauche
      spinLeft(90); // Tourne à gauche (pour faire un demi-tour)
      forward(CASE); // Avance d'une case
      spinRight(90); // Tourne à droite
      orientation = AVANT; // Remet l'orientation à l'avant
      colonne--; // Décrémente la colonne
      break;
    
    default:
      break;
    }
    
    // Si nous sommes à la dernière rangée et que le demi-tour n'a pas encore été effectué
    if(rangee == 9 && demitour == false)
    {
      rangee = 0; // Remet la rangée à 0
      if (colonne == 0) // Si nous sommes à la première colonne, déplace à la dernière
        colonne = 2; 
      else if (colonne == 2) // Si nous sommes à la dernière colonne, déplace à la première
        colonne = 0; 
      spinRight(180); // Fait un demi-tour vers la droite
      demitour = true; // Indique que le demi-tour a été effectué
    }
  }
  arret(); // Arrête le robot à la fin du parcours
  while(true)
  {
    // code à exécuter en fin de parcours (ex. jouer de la musique)
  }
}