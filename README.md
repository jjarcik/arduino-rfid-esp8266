# Arduino + rfid + esp8266

Read data from RFID and send it to website



### Source
https://www.youtube.com/watch?v=q02f4sPghSo

### AT Commands
```
AT+RST
AT+CWMODE=3
AT+CIPMUX=0
AT+CWJAP="WIFI SSID","password"
AT+CIPSTART="TCP","10.0.0.2",3000
AT+CIPSEND=36
GET /ok HTTP/1.1
Host: 10.0.0.2
```
