# Arduino + rfid + esp8266

Read data from RFID and send it to website

|ESP8266|Arduino|
|-------|-------|
| RX    | 7     |
| TX    | 6     |


|ESP8266| 3.3v Reg |
|-------|----------|
|Vcc    |Vout      |
|CH_PD  |Vout      |
|Gnd    |Gnd       |


|3.3v Reg|Arduino|
|--------|-------|
| Vin    | 5v    |
| Gnd    | Gnd   |


| Arduino | RDM 6300 |
| ------- | -------- |
| 5V      | P3-2     |
| Gnd     | P3-3     |
| 2       | P1-3     |




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
