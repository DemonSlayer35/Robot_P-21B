#include <Arduino.h>
#include <LibRobUS.h>
#include "Adafruit_TCS34725.h" // librairie pour le capteur de couleur

#define MAX_ANALOG_INPUT_VAL 1023 // Le ADC du Mega2560 est sur 10 bits (donc, 0 - 1023)

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);


/**
 * @brief Convertit la valeur IR en distance en centimètres.
 * @param id L'identifiant du capteur IR (0: gauche, 1:droit, 2:avant, 3:arrière)
 * @return La distance en centimètres.
 */
float convertDistanceIR(uint8_t id){

  float InfraredVal = ROBUS_ReadIR(id);

  float analogInVoltage = InfraredVal * (5.0 / MAX_ANALOG_INPUT_VAL);
  
  float distanceCM = 0;
  // Voltage-to-distance formula from https://www.makerguides.com/sharp-gp2y0a21yk0f-ir-distance-sensor-arduino-tutorial/
  distanceCM = 29.988 * pow(analogInVoltage, -1.173);

  return distanceCM;
}

/*
Fonction d'initialisation (setup)
 -> Se fait appeler au début du programme
 -> Se fait appeler seulement une fois
 -> Généralement on y initialise les variables globales
*/
void setup(){
  BoardInit();

  /// CODE POUR LE CAPTEUR DE COULEUR ///

  /*if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }*/
}

/*
Fonctions de boucle infinie
 -> Se fait appeler perpétuellement suite au "setup"
*/
void loop(){

  /// CODE POUR LE CAPTEUR DE DISTANCE INFRAROUGE ///
  float distance = convertDistanceIR(0); // convertit la distance du capteur IR en cm
  Serial.println(distance); // affiche la distance dans le moniteur série
  delay(500); // délai de 500 ms
  

  /// CODE POUR LE CAPTEUR DE COULEUR ///

  /*uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  
  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

  if(r > 900 && g > 900 && b > 900)
    Serial.println("BLANC");
  else if(r > g && r > b)
    Serial.println("ROUGE");
  else if(g > r && g > b)
    Serial.println("VERT");
  else if(b > r && b > g)
    Serial.println("BLEU");
  else if(r > b+300 && g > b+300)
    Serial.println("JAUNE");
  else
    Serial.println("TAPIS");*/

}
