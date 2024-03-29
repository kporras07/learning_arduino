/* ESP Server receive and parse JSON
 
*/
#include "WiFiEsp.h"
#include <ArduinoJson.h>

#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"

// set up software serial to allow serial communication to our TX and RX pins
SoftwareSerial Serial1(10, 11);
#endif

// Set  baud rate of so we can monitor output from esp.
#define ESP8266_BAUD 9600

#define LED_PIN 8

// CHANGE THIS TO MATCH YOUR SETTINGS
char ssid[] = "SSID";
char pass[] = "PASSWORD";
int status = WL_IDLE_STATUS;

// Define an esp server that will listen on port 80
WiFiEspServer server(80);

void setup()
{
  // Open up communications for arduino serial and esp serial at same rate
  Serial.begin(ESP8266_BAUD);
  Serial1.begin(ESP8266_BAUD);

  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);

  // Initialize the esp module
  WiFi.init(&Serial1);

  // Start connecting to wifi network and wait for connection to complete
  while (status != WL_CONNECTED)
  {
    Serial.print("Conecting to wifi network: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  // Once we are connected log the IP address of the ESP module
  Serial.print("IP Address of ESP8266 Module is: ");
  Serial.println(WiFi.localIP());
  Serial.println("You're connected to the network");

  // Start the server
  server.begin();
}

void turnOn()
{
  digitalWrite(LED_PIN, HIGH);
}

void turnOff()
{
  digitalWrite(LED_PIN, LOW);
}

void postRoot(WiFiEspClient client)
{
  client.readStringUntil('{');
  // get json body (everything inside of the main brackets)
  String jsonStrWithoutBrackets = client.readStringUntil('}');

  // Append brackets to make the string parseable as json
  String jsonStr = "{" + jsonStrWithoutBrackets + "}";

  // if we managed to properly form jsonStr...
  if (jsonStr.indexOf('{', 0) >= 0) {
    // parse string into json, bufferSize calculated by https://arduinojson.org/v5/assistant/
    const size_t bufferSize = JSON_OBJECT_SIZE(1) + 20;
    DynamicJsonBuffer jsonBuffer(bufferSize);
    JsonObject &root = jsonBuffer.parseObject(jsonStr);
    // get and print the value of the action key in our json object
    const char *value = root["action"];

    if (strcmp(value, "on") == 0) {
      // Do something when we receive the on command
      Serial.println("Received on command from client");
      turnOn();
    }
    else if (strcmp(value, "off") == 0) {
      // Do something when we receive the off command
      Serial.println("Received off command from client");
      turnOff();
    }

    // send response and close connection
    client.print(
      "HTTP/1.1 200 OK\r\n"
      "Connection: close\r\n" // the connection will be closed after completion of the response
      "\r\n"
    );
    client.stop();
  }
  else {
    // we were unable to parse json, send http error status and close connection
    throw500(client, "Error, bad or missing json");
  }
}

void throw500(WiFiEspClient client, String message) {
  client.print(
    "HTTP/1.1 500 ERROR\r\n"
    "Connection: close\r\n"
    "\r\n"
  );

  Serial.println(message);
  client.stop();
}

void throw404(WiFiEspClient client, String message) {
  client.print(
    "HTTP/1.1 404 Not Found\r\n"
    "Connection: close\r\n"
    "\r\n"
  );

  Serial.println(message);
  client.stop();
}

//  Continually check for new clients
void loop()
{
    WiFiEspClient client = server.available();

    // If a client has connected...
    if (client)
    {
        String json = "";
        Serial.println("A client has connected");

        while (client.connected())
        {
            // Read in json from connected client
            if (client.available())
            {
                bool handled = false;
                // ignore headers and read to first json bracket
                String httpMethod = client.readStringUntil(' ');
                String path = client.readStringUntil(' ');
                if (httpMethod == "POST" && path == "/") {
                  postRoot(client);
                  handled = true;
                }
                if (!handled) {
                  throw404(client, "No path found for method: " + httpMethod + " and path: " + path);
                }
            }
        }

        delay(10);
        client.stop();
        Serial.println("Client disconnected");
    }
}