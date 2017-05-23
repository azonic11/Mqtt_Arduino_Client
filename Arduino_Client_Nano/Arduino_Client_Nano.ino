    const int MainLight=12;  
    const int BadLight=8;   
    const int BarLight=5;   
    const int Transmitter=3;
    const int RedRGB=11;     
    const int GreenRGB=10;   
    const int BlueRGB=9;
    const int TempPin=A0;
    const int Relay3=7;
    const int Relay4=4;
    
    String    message;
    String    topic;
    String    command;   
    String    tempMessage;
    String    stringBuff;
    
    struct    RGB {int r,g,b;};
   
    
    RGB       savedRGB;
    RGB       black;
    RGB       newRGB; 
    RGB       white;
    RGB       currentRGB;

    
                      

    
    char             rgbBuf[10];
    char             timeBuf[10];
    
    unsigned long    previousMillis1 = 0;  
    unsigned long    previousMillis2 = 0;  
    unsigned long    currentMillis;
    
    float            RawValue= 0;
    double           tempVal;
   
    int              barLightBrightness=0;
    int              newBrightness=0;
    int              avarageTemp[100];
    
    boolean          firstStart=true;

    struct           myTime {
                        int hour=-1,minute=-1;
                        
                        String getTime(){
                           if(minute<10)
                              stringBuff=String(hour)+":0"+String(minute);
                           else
                              stringBuff=String(hour)+":"+String(minute);
                           return (stringBuff);      
                           };
                           
                          boolean equale(myTime t){
                            if(minute==t.minute&&hour==t.hour)
                              return true;
                            else
                              return false;
                          };
                    };


    myTime             currentTime;                     
    myTime             alarm;                   
    myTime             sleep;
    
    void setup() {
      
      black.r=       0;
      black.g=       0;
      black.b=       0;
      
      white.r=       255;
      white.g=       255;
      white.b=       255;  
      
      newRGB.r=      255;
      newRGB.g=      255;
      newRGB.b=      255;
      
      currentRGB.r=  0;
      currentRGB.b=  0;
      currentRGB.g=  0;

      savedRGB.r=    255;
      savedRGB.g=    255;
      savedRGB.b=    255;
        
      pinMode(MainLight,OUTPUT);
      pinMode(BadLight,OUTPUT);
      pinMode(BarLight,OUTPUT);
      pinMode(RedRGB,OUTPUT);
      pinMode(GreenRGB,OUTPUT);
      pinMode(BlueRGB,OUTPUT);
      pinMode(Relay3,OUTPUT);
      pinMode(Relay4,OUTPUT);

      digitalWrite(Relay3,HIGH);
      digitalWrite(Relay4,HIGH);
      digitalWrite(MainLight,HIGH);
      digitalWrite(BadLight,HIGH);

      Serial.begin(115200);
      Serial.setTimeout(5);
      
    }
 
    void loop() {
      currentMillis = millis();
      
      if(firstStart){
          firstStart=false;
          delay(200);
          Serial.println("badRoom/time&set time");
          delay(200);
          Serial.println("badRoom/alarm&set alarm");
          delay(200);
          Serial.println("badRoom/sleep&set sleep");
          delay(200);
      
          }
     
     thermoMeter(2,10000);  //  (int digitsAfterPoint,int sendInterval(ms) )
     Time();
     SerialLeasener();
     
    }
