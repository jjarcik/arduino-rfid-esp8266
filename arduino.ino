#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // your esp's baud rate might be different
  
  
  sendData("AT+RST\r\n",5000,DEBUG); // reset module
  sendData("AT+CWMODE=3\r\n",5000,DEBUG); // configure as access point  
  sendData("AT+CIPMUX=0\r\n",1000,DEBUG); // configure for multiple connections  
  Serial.println("wait 15 seconds");
  sendData("AT+CWJAP=\"SSID WIFI\",\"password\"\r\n",15000,DEBUG); // get ip address  
  sendData("AT+CIFSR\r\n",5000,DEBUG); // get ip address

  sendData("AT+CIPSTART=\"TCP\",\"10.0.0.2\",3000\r\n",3000,DEBUG); // connect to webpage
  sendData("AT+CIPSEND=36\r\n",3000,DEBUG); // init sending
  sendData("GET /ok HTTP/1.1\r\n",3000,DEBUG); // send header
  sendData("Host: 10.0.0.2\r\n",3000,DEBUG); // send data
  sendData("\r\n",3000,DEBUG); // send data
}
 
void loop()
{
  
  if(esp8266.available()) // check if the esp is sending a message 
  {
    while(esp8266.available())
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266.read(); // read the next character.
      Serial.write(c);
    }

  /*
    Serial.println("AT+CIPSEND=0,5");
    sendData("AT+CIPSEND=0,5\r\n",1000,DEBUG);  
    Serial.println("hello");
    sendData("hello\r\n",1000,DEBUG);  
    Serial.println("AT+CIPCLOSE=0");
    sendData("AT+CIPCLOSE=0\r\n",1000,DEBUG);
    /**/
  }
}
 
/*
* Name: sendData
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the esp8266 (if there is a reponse)
*/
String sendData(String command, const int timeout, boolean debug)
{

  Serial.println(command);
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}