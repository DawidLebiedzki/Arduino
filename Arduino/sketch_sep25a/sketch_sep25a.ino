#include <stdlib.h>
#include <SoftwareSerial.h>
#include <DHT11.h>
SoftwareSerial monitor(2, 3);
String GET;
DHT11 dht11(A0);
String Thingspeak_KEY = "TYESNCB248JNVMT8"; //Tu wpisz swój Thingspeak KEY.
String NazwaSieci = "DomL"; //Tu podaj nazwe swojej sieci.
String HasloSieci = "6626414757274350"; //Tu hasło do sieci.
void setup()
{
    monitor.begin(115200);
  	monitor.println("AT+CIPMUX=1");
  	delay(200);
  	connect();
 
}
 
void loop(){
	delay(15000); //czekam 15 sekund na polaczenie
	char buffer[10];
	char buffer1[10];
	float Btemp, Bhumi;
	dht11.read(Bhumi, Btemp);
	delay(10000);
	String Temp = dtostrf(Btemp, 4, 1, buffer);
	String Humi = dtostrf(Bhumi, 4, 1, buffer1);
	updateTemp(Temp); //wysylam dane
	delay(30000); //czekam 30 sekund do wyslania wilgotnosci
	updateHumi(Humi); //wysylam dane
	delay(3600); //odczekuje godzine. co tyle wykonuje odczyty
}
void updateTemp(String Temp){
	GET = "GET /update?key=";
        GET+= Thingspeak_KEY;
        GET += "&field1=";
	String command = GET;
	command += String(Temp);
	command += "\n\r\n\r";
	monitor.println("AT+CIPSTART=4, \"TCP\",\"184.106.153.149\",80");
	delay(10000);
	monitor.println("AT+CIPSEND=4,46");
	delay(3000);
	monitor.println(command);
	delay(2000);
	monitor.println("AT+CIPCLOSE");
}
void updateHumi(String Humi){
	GET = "GET /update?key=";
        GET+= Thingspeak_KEY;
        GET += "&field2=";
	String command = GET;
	command += String(Humi);
	command += "\n\r\n\r";
	monitor.println("AT+CIPSTART=4, \"TCP\",\"184.106.153.149\",80");
	delay(10000);
	monitor.println("AT+CIPSEND=4,46");
	delay(3000);
	monitor.println(command);
	delay(2000);
	monitor.println("AT+CIPCLOSE");
}
void connect(){
	monitor.println("AT+CWMODE=1");
	delay(200);
        String cmd = "AT+CWJAP=\""+NazwaSieci+"\", \""+HasloSieci+"\"";
	monitor.println(cmd);
	delay(2000);
 
}
