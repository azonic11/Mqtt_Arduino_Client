void Time(){

  //refresh time every 1min
  
  if(currentTime.hour!=-1){
    if (currentMillis - previousMillis2 >= 60000) {   //if 60s have passed
       previousMillis2 = currentMillis;
  
       currentTime.minute++;
       if(currentTime.minute==60){
        currentTime.minute=0;
        currentTime.hour=currentTime.hour+1;
       }  
       if(currentTime.hour==24)
          currentTime.hour=0;
          
             stringBuff="badRoom/time&"+currentTime.getTime();
           
             delay(200);
             Serial.println(stringBuff);     
             delay(200);

            //check alarm every 1min #####################################
            if(currentTime.equale(alarm)){
               digitalWrite(MainLight,LOW);
               digitalWrite(BadLight,LOW);
               softRGB(white);
  
               Serial.println("badRoom/mainLight&1");
               delay(200);
               Serial.println("badRoom/badLight&1");
               delay(200);
               Serial.println("badRoom/RGB&1");
               delay(200);
               beep();
            }

            //check sleep every 1min #####################################
            
             if(currentTime.equale(sleep)){

               digitalWrite(BadLight,HIGH);
               digitalWrite(Relay3,LOW);
               digitalWrite(Relay4,HIGH);
               
               softRGB(black);
                
               Serial.println("badRoom/relay1&1");
               delay(200);
               Serial.println("badRoom/relay2&0");
               delay(200);
               Serial.println("badRoom/badLight&0");
               delay(200);
               Serial.println("badRoom/RGB&0");
               delay(200);
            }
              
     }

  }

}

