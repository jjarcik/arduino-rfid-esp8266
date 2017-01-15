#include "WiFiEsp.h"

// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7); // RX, TX
#endif

SoftwareSerial RFID(2, 3); // RX and TX

char ssid[] = "SSID";            // your network SSID (name)
char pass[] = "password";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "arduino.cc";
int port = 80;
char url[] = "/asciilogo.txt";
int i;
int open = 0;

// Initialize the Ethernet client object
WiFiEspClient client;

void setup()
{
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  Serial1.begin(9600);
  // initialize ESP module
  WiFi.init(&Serial1);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");
  
  printWifiStatus();
  
  sendOK();
  RFID.begin(9600); // start serial to RFID reader
}

void loop()
{
  // if there are incoming bytes available
  // from the server, read them and print them
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
/**/
  if (RFID.available() > 0 && open == 0) {
    while (RFID.available()) {
      i = RFID.read();
      Serial.print(i, DEC);    
    }
    Serial.println();
    
    sendOK();
}/**/

  // if the server's disconnected, stop the client
  
  if (!client.connected() && open == 1) {
    close();

    // do nothing forevermore
    //while (true);
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void sendOK(){
  open = 1;
  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, port)) {
    Serial.println("Connected to server");
    // Make a HTTP request
    client.println("GET " + String(url) + " HTTP/1.1");
    client.println("Host: " + String(server));
    client.println("Connection: close");
    client.println();
  } 
}

void close(){
  open = 0;
  Serial.println();
  Serial.println("Disconnecting from server...");
  client.stop();
}




