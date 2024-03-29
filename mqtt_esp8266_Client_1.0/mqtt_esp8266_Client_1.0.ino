/*
 Basic ESP8266 MQTT example

 This sketch demonmessageates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.

 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are messageings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"

*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
int ledState = HIGH;             
long previousMillis = 0;    
long interval = 2500;     //in board led blink
const int ledPin =  2;   

const char* ssid = "";
const char* password = "";
const char* mqtt_server = "m20.cloudmqtt.com";
const char* clientId="test11";
const char* userName="";
const char* mqttpassword="";


String message,topic,command;
const char* topic2;
const char* command2;
unsigned char* buf1;
unsigned char* buf2;

String receivedData="";
WiFiClient espClient;
PubSubClient client(espClient);
long lastcommand = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 13228);
  client.setCallback(callback);
  Serial.setTimeout(100);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
 
 // Serial.print("Message arrived [");
 // Serial.print(topic);
  receivedData=String(topic);
   
    for (int i = 0; i< receivedData.length(); i++) {
      if((char)topic[i]=='/'){
       receivedData=receivedData.substring(i+1,receivedData.length());
        break;
      }
    }
   
 
  receivedData=receivedData+"$";  //seperator
 // Serial.print("] ");
    for (int i = 0; i < length; i++) {
      receivedData=receivedData+(char)payload[i];
    //  Serial.print((char)payload[i]);
    }
  //Serial.print(" RECEIVED ");
  Serial.println((String)receivedData);
  receivedData="";
}

void reconnect() {
  // Loop until we're reconnected
  if (client.connect(clientId,userName,mqttpassword)) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("connected", "hello from esp8266 badRoom");
      // ... and resubscribe
      client.subscribe("badRoom/#");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
 client.loop();
  
       if(Serial.available()>0){
//        message=Serial.readString();      
//        if(message=="RECEIVED")
          message=Serial.readString();
            for(int i=0;i<message.length();i++){
              if(message[i]=='&'){
                topic=message.substring(0,i);
                command=message.substring(i+1,message.length()-2);
              
                 buf1= new unsigned char[30];
               topic.getBytes(buf1, 30, 0);
               topic2 = (const char*)buf1;

               buf2= new unsigned char[30];
               command.getBytes(buf2, 30, 0);
               command2 = (const char*)buf2;
  
          client.publish(topic2,command2);
          Serial.print("Publish message: topic[");
          Serial.print(topic);
          Serial.print("] command[");
          Serial.print(command);
          Serial.print("]");
          Serial.println();

          break;
              
              }
            }
              
      
    }

  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  
    


}
