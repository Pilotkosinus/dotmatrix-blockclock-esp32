# Noch in der Entwicklung (Anzeige auf der Dotmatrix funktionert noch nicht)
# Dokumentation  Dotmatrix-Blockclock-esp32


Das gegebene Skript ist in der Programmiersprache C++ geschrieben und verwendet mehrere Bibliotheken, um eine Verbindung zu einem WLAN-Netzwerk herzustellen, eine Webseite abzurufen, Daten aus der Webseite zu extrahieren und die extrahierten Daten auf einer LED-Matrix anzuzeigen. Eine kurze Beschreibung der wichtigsten Funktionen und Bibliotheken ist wie folgt:

## Bibliotheken
### WiFi.h

Die Bibliothek WiFi.h wird verwendet, um eine Verbindung zu einem WLAN-Netzwerk herzustellen.
### HTTPClient.h

HTTPClient.h wird verwendet, um eine HTTP-Verbindung zu einer Webseite herzustellen und Daten abzurufen.
### WiFiClientSecure.h

WiFiClientSecure.h wird verwendet, um eine sichere Verbindung zu einer Webseite herzustellen, die eine SSL/TLS-Verschlüsselung verwendet.
### MD_Parola.h

MD_Parola.h wird verwendet, um eine LED-Matrix anzusteuern und Text auf der Matrix anzuzeigen.
### MD_MAX72xx.h

MD_MAX72xx.h wird verwendet, um eine LED-Matrix zu konfigurieren und anzusteuern.
### SPI.h

SPI.h wird verwendet, um die Kommunikation zwischen dem Mikrocontroller und der LED-Matrix über den SPI-Bus zu ermöglichen.
## Funktionen
### void setup()

Die Funktion `setup()` wird einmalig aufgerufen, wenn das Programm gestartet wird. Sie initialisiert die serielle Kommunikation, stellt eine Verbindung zum WLAN-Netzwerk her, initialisiert die LED-Matrix und zeigt "Hello World!" an.
### String extractBetween(String data, String startStr, String endStr)

Die Funktion `extractBetween()` wird verwendet, um einen Text zwischen zwei Zeichenketten zu extrahieren. Sie erhält den vollständigen Text (data) und die Start- und Endzeichenketten (startStr und endStr) als Parameter. Sie gibt den extrahierten Text als Zeichenkette zurück.
### void loop()

Die Funktion `loop()` wird kontinuierlich ausgeführt, nachdem die Funktion setup() einmal aufgerufen wurde. Sie prüft, ob eine WLAN-Verbindung hergestellt ist, stellt eine Verbindung zur Webseite her, ruft Daten von der Webseite ab, extrahiert den relevanten Text und zeigt ihn auf der LED-Matrix an. Wenn keine Verbindung hergestellt werden kann, wird eine entsprechende Fehlermeldung ausgegeben.

Das Skript ist für den speziellen Anwendungsfall geschrieben, die Anzahl der Blöcke der Kryptowährung Bitcoin abzurufen und auf der LED-Matrix anzuzeigen. 
