<html>
  <head>
    <title>Pilotage Robot à distance</title>
    <link rel="stylesheet" href="style.css">
  </head>
  <body >
    <h1>Pilotage du robot à distance </h1>
    <div id="deplacement">
      <p id="para">Utilisez les boutons ci-dessous pour contrôler le robot :</p>
      <div id="avance">
        <button id="avancer" onclick="sendCommand('avancer')">Avancer</button>
      </div>
      <div id="tourne">
        <div id="tournegauche">
          <button id="gauche" onclick="sendCommand('gauche')">Tourner à gauche</button>
        </div>
        <div id="tournedroite">
          <button id="droite" onclick="sendCommand('droite')">Tourner à droite</button>
        </div>
      </div>
      <div id="recule">
        <button id="reculer" onclick="sendCommand('reculer')">Reculer</button>
      </div>
  
    </div>
    <script>
      const net = require('net'); // importation de Node.js

      function sendCommand(command) 
      {
        const client = new net.Socket(); // instance représantant le client

        // connexion à l'arduino
        client.connect(80, '192.168.65.71', function() 
        {
            console.log('Connected'); // affiche dans les logs quand on est connecté
            client.write(command); // envoie le message
        });

        // on définit un gestionnaire d'événement pour la réception de données
        client.on('data', function(data) 
        {
            console.log('Received: ' + data); // écrit le message dans la connexion
            client.destroy(); // fermeture de la connexion
        });

        // on définit un gestionnaire d'événement pour la fermeture de la connexion
        client.on('close', function() 
        {
            console.log('Connection closed'); // affiche message quand on arrête la connexion
        });
    }
    </script>
  </body>
</html>