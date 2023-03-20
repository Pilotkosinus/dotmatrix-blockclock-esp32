#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const char* ssid = "yourssid";
const char* password = "wlanpw";
const char* url = "https://explorer.btc.com/btc/blocks"; // URL der Webseite
const char* fingerprint = "40:5A:AE:D0:1B:56:CE:D0:1C:BA:B8:3F:66:F7:14:6D:30:63:D5:2F";
const String startString = "<span class=\"font-size-sm responsive-label nowrap secondary-text\">";
const String endString = "</span>";

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW  // <-- PAROLA_HW
#define MAX_DEVICES 4
#define CLK_PIN   18      // yellow - SPI SCK
#define DATA_PIN  23      // green - SPI MOSI
#define CS_PIN     5      // orange - black - SP SS

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbindung wird hergestellt...");
  }
  Serial.println("Verbunden mit WLAN");
  P.begin(MAX_DEVICES);
  P.setIntensity(10); // Helligkeit der LED-Matrix (0-15)
  P.setInvert(false); // Invertieren der LED-Matrix
  P.displayText("Hello World!", PA_CENTER, 30, 1000, PA_SCROLL_LEFT);
}

String extractBetween(String data, String startStr, String endStr) {
  int startIndex = data.indexOf(startStr);
  if (startIndex == -1) {
    return "";
  }
  startIndex += startStr.length();
  int endIndex = data.indexOf(endStr, startIndex);
  if (endIndex == -1) {
    return "";
  }
  return data.substring(startIndex, endIndex);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String payload = http.getString();
      String extractedSpan = extractBetween(payload, startString, endString);
      String extractedNumber = extractBetween(extractedSpan, "of ", " Blocks");
    if (extractedNumber != "") {
      extractedNumber.trim();
      Serial.println(extractedNumber); // Ausgabe des extrahierten Texts im seriellen Monitor
      P.displayText(extractedNumber.c_str(), PA_CENTER, 30, 1000, PA_SCROLL_LEFT);
}
    } else {
      Serial.print("Fehler beim Abrufen der Webseite. HTTP-Code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Keine WLAN-Verbindung");
  }
  delay(20000);
}
