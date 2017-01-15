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


## Config of ESP8266
```
AT+GMR

AT version:0.50.0.0(Sep 18 2015 20:55:38)
SDK version:1.4.0
compile time:Sep 18 2015 21:46:52

```

## How to run server
```
 cd server
 npm install
 npm run start
```

open http://localhost:3000/
open localhost:3000/ok
open localhost:3000
