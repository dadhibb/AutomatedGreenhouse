# AutomatedGreenhouse
Automated greenhouse project
The sktech here uses 2 different sensors:
1 - A DHT22 combined Temperature and Humidity sensor using SimpleDHT library from https://github.com/winlinvip/SimpleDHT 
2 - A LM-393 soil humidity sensor
I'm using a 4-relay board to turn things off and on according to the data
This code works As Is, help yourself

The idea longer term is to add an ESP8266 to send thet data to my Thingspeak channel and probably make a nice HMI with Blynk
