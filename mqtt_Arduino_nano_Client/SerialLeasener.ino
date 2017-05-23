
void SerialLeasener(){
  
     if(Serial.available()>0){
            message=Serial.readString();
            for(int i=0;i<message.length();i++){
              if(message[i]=='$'){
                topic=message.substring(0,i);
                command=message.substring(i+1,message.length()-2);
              }
                  //#####################################################################################
                  if(topic=="mainLight"){
                    if(command=="0"){
                      digitalWrite(MainLight,HIGH);
                      Serial.println("badRoom/text&lol");
                    }else{
                      digitalWrite(MainLight,LOW);
                      Serial.println("badRoom/text&gg");
                    }
                  }
                  //#####################################################################################
                   
                  else if(topic=="badLight"){
                    if(command=="0")
                       digitalWrite(BadLight,HIGH);
                    else
                       digitalWrite(BadLight,LOW);
                  }

                  //#####################################################################################
                  else if(topic=="barLight"){
                   
                    newBrightness=(int)command.toInt();
                   // String buf1="badRoom/text&";
                   //  buf1=buf1+newBrightness;
                    //Serial.println(buf1);
                    if(newBrightness>barLightBrightness){
                      while(newBrightness!=barLightBrightness){
                        delay(2);
                        barLightBrightness=barLightBrightness+1;
                        analogWrite(BarLight,barLightBrightness);
                      } 
                      
                    }
                    //#####################################################################################
                   else if(newBrightness<barLightBrightness){
                      while(newBrightness!=barLightBrightness){
                        delay(2);
                        barLightBrightness=barLightBrightness-1;
                        analogWrite(BarLight,barLightBrightness);
                      } 
                    }
                         
                  }

                  //#####################################################################################
                  else if(topic=="transmitt"){
//                      const char *msg = "hello";
//                      vw_send((uint8_t *)msg, strlen(msg));
//                      vw_wait_tx(); // Wait until the whole message is gone
                      
                  }
                  
                  //#####################################################################################
                  else if(topic=="RGB"){
                    if(command=="1"){
                      if(savedRGB.r+savedRGB.g+savedRGB.b!=0){
                        softRGB(savedRGB);
                        currentRGB=savedRGB;
                      }else{
                        softRGB(white);
                        currentRGB=white;
                    }}
                    else if(command=="0"){
                       softRGB(black);
                       currentRGB=black;
                    }
                  }

                  //#####################################################################################
                   else if(topic=="RGBColor"){
                    
                     command.substring(1,3).toCharArray(rgbBuf, 10);
                     newRGB.r=(int)strtol(rgbBuf, 0,16);
      
                     command.substring(3,5).toCharArray(rgbBuf, 10);
                     newRGB.g=(int)strtol(rgbBuf, 0, 16);
                     
                     command.substring(5,7).toCharArray(rgbBuf,10);
                     newRGB.b=(int)strtol(rgbBuf, 0, 16);
                     
                     softRGB(newRGB);
                     currentRGB=newRGB;
                     savedRGB=newRGB;
                     if(newRGB.r+newRGB.g+newRGB.b!=0){
                     Serial.println("badRoom/RGB&1");
                     }else 
                     Serial.println("badRoom/RGB&0");
                   }

                     //#####################################################################################
                     
                    else if(topic=="relay1"){
                      Serial.println("badRoom/text&relay1");
                       if(command=="0")
                       digitalWrite(Relay3,HIGH);
                    else
                       digitalWrite(Relay3,LOW);
                    }
  
                     //#####################################################################################
                    
                    else if(topic=="relay2"){
                      Serial.println("badRoom/text&relay2");
                       if(command=="0")
                       digitalWrite(Relay4,HIGH);
                    else
                       digitalWrite(Relay4,LOW);
                    }
                    //#####################################################################################

                    else if(topic=="time"){
                      //command.subString(0,2);
                      currentTime.hour=command.substring(0,2).toInt();
                      currentTime.minute=command.substring(3,5).toInt();
                      
                          delay(200);
                          stringBuff="badRoom/time&"+currentTime.getTime();
                          Serial.println(stringBuff);
                          delay(200);
                    }
                    
                    else if(topic=="alarm"){
                      //command.subString(0,2);
                      alarm.hour=command.substring(0,2).toInt();
                      alarm.minute=command.substring(3,5).toInt();
                      
                          delay(200);
                          stringBuff="badRoom/alarm&"+alarm.getTime();
                          Serial.println(stringBuff);
                          delay(200);
                       
                    }

                      else if(topic=="sleep"){
                      //command.subString(0,2);
                      sleep.hour=command.substring(0,2).toInt();
                      sleep.minute=command.substring(3,5).toInt();
                      
                          delay(200);
                          stringBuff="badRoom/sleep&"+sleep.getTime();
                          Serial.println(stringBuff);
                          delay(200);
                    }
                    
                  

                 
                  if(message[i]=='&'){
                    Serial.println(message);  
                    break;
                  }
                  else{
                    if(i==message.length()-1){
                        break;
                }
              }
           } 
        }
    }
