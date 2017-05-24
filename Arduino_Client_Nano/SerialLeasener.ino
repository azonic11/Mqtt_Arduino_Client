
void serialLeasener(){
  
     if(Serial.available()>0){                         //Leasining for data, data example "badRoom/mainLight$1"
            message=Serial.readString();               //where topic is "badRoom/mainLight" and command is "1"
            for(int i=0;i<message.length();i++){       
              if(message[i]=='$'){                     //Searching for separator
                topic=message.substring(0,i);
                command=message.substring(i+1,message.length()-2);
              
                  //#####################################################################################
                
                  if(topic=="mainLight"){
                    if(command=="0")
                      digitalWrite(MainLight,HIGH); //turn off 
                    else
                      digitalWrite(MainLight,LOW);  //turn on
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
                    if(newBrightness>barLightBrightness){
                      while(newBrightness!=barLightBrightness){
                        delay(2);
                        barLightBrightness=barLightBrightness+1;
                        analogWrite(BarLight,barLightBrightness);
                     }  
                    }
                 
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
                      //coming soon
                  }
                  
                  //#####################################################################################
                 
                  else if(topic=="RGB"){      //turn on/off rgb strip
                    if(command=="1"){
                      if(savedRGB.r+savedRGB.g+savedRGB.b!=0){
                        smoothRGB(savedRGB);
                        currentRGB=savedRGB;
                      }else{
                        smoothRGB(white);
                        currentRGB=white;
                    }}
                    else if(command=="0"){
                       smoothRGB(black);
                       currentRGB=black;
                    }
                  }

                  //#####################################################################################
                 
                   else if(topic=="RGBColor"){  //set color for rgb strip
                    
                     command.substring(1,3).toCharArray(rgbBuf, 10);
                     newRGB.r=(int)strtol(rgbBuf, 0,16);
      
                     command.substring(3,5).toCharArray(rgbBuf, 10);
                     newRGB.g=(int)strtol(rgbBuf, 0, 16);
                     
                     command.substring(5,7).toCharArray(rgbBuf,10);
                     newRGB.b=(int)strtol(rgbBuf, 0, 16);
                     
                     smoothRGB(newRGB);
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
                     //#####################################################################################
                  
                    else if(topic=="alarm"){
                      //command.subString(0,2);
                      alarm.hour=command.substring(0,2).toInt();
                      alarm.minute=command.substring(3,5).toInt();
                      
                          delay(200);
                          stringBuff="badRoom/alarm&"+alarm.getTime();
                          Serial.println(stringBuff);
                          delay(200);
                       
                    }
                     //#####################################################################################
                    
                      else if(topic=="sleep"){
                      //command.subString(0,2);
                      sleep.hour=command.substring(0,2).toInt();
                      sleep.minute=command.substring(3,5).toInt();
                      
                          delay(200);
                          stringBuff="badRoom/sleep&"+sleep.getTime();
                          Serial.println(stringBuff);
                          delay(200);
                    }
               break;     
              }

                 
            
           } 
        }
    }
