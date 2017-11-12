#include <WiFi.h>

char ssid[] = "PM25";      // your network SSID (name)
char pass[] = "qq12345678";     // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
char server[] = "10.1.1.12";    // name address for Google (using DNS)
int serverPort = 80 ;
//-------------- dht use
#include "DHT.h"
#define DHTPIN 8     // what digital pin we're connected to


//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
String strGet="GET /iot/dht22/dataadd.php";
String strHttp=" HTTP/1.1";
String strHost="Host: 10.1.1.12";  //OK
  String connectstr ;
WiFiClient client;
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
    Serial.begin(9600);
  Serial.println("DHTxx test!");
    dht.begin();
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }
  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWifiStatus();

}// END Setup

static int count=0;
void loop()   
{
   connectstr = "" ;
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t\n");

  connectstr = "?field1=" + String(t)+"&field2="+ String(f)+"&field3="+ String(h);
     Serial.println(connectstr) ;
         if (client.connect(server, serverPort)) {
             Serial.print("Make a HTTP request ... ");
             //### Send to Server
             String strHttpGet = strGet + connectstr + strHttp;
 
             client.println(strHttpGet);
             client.println(strHost);
             client.println();
           } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN

} // END Loop

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

