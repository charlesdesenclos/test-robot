#include <SPI.h>
#include <Ethernet.h>

// variables pour les LED
const int led1Pin = 8;
const int led2Pin = 9;
const int led3Pin = 10;
const int led4Pin = 11;

EthernetServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);

  Ethernet.begin(mac, ip, gateway, subnet);

  // commencez à écouter les connexions sur le port 80
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // attendez une connexion client
  EthernetClient client = server.available();
  if (client) 
  {
     // lisez les données envoyées par le client
    String commande = client.readStringUntil('\r');
    if (commande == "avancer") {
      
      led1Etat = HIGH; // Allume la LED 1
      led2Etat = HIGH; // Allume la LED 2
      led3Etat = LOW; // Eteint la LED 3
      led4Etat = LOW; // Eteint la Led 4

     } else if (commande == "gauche") {
      
      led1Etat = LOW; // Eteint la LED 1
      led2Etat = LOW; // Eteint la LED 2
      led3Etat = HIGH; // Allume la LED 3
      led4Etat = LOW; // Eteint la LED 4
    } else if (commande == "droite") {
      
      led1Etat = LOW; // Eteint la LED 1
      led2Etat = LOW; // Eteint la LED 2
      led3Etat = LOW; // Eteint la LED 3
      led4Etat = HIGH; // Allume la LED 4
    } else if (commande == "reculer") {
     
      led1Etat = LOW; // Eteint la LED 1
      led2Etat = HIGH; // Allume la LED 2
      led3Etat = LOW; // Eteint la LED 3
      led4Etat = HIGH; // Allume la LED 4
    }

    // Met à jour l'état des LED
    digitalWrite(led1Pin, led1Etat);
    digitalWrite(led2Pin, led2Etat);
    digitalWrite(led3Pin, led3Etat);
    digitalWrite(led4Pin, led4Etat);

    // envoie une réponse au client
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html"); //type de contenue de la réponse
    client.println();
    client.println("<h1>Commande recue</h1>");

    delay(1);
    client.stop();
  }

}
