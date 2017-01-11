# Arduino + rfid + esp8266

Read data from RFID and send it to website

| ESP8266 | Arduino |
| ------- |:-------:|
| TX | 6 |
| RX | 7 |

| ESP8266 | 3.3v Reg |
| ------- |:-------:|
| Vin | Vout |
| Gnd | Gnd |

| Arduino | Breadboardg | RFID | 3.3V Reg |
| ------- |:-------|:------- |:-------|
| 5V | - |  5V | Vin




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
