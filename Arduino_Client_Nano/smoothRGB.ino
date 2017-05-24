    void smoothRGB(RGB newRgb){
                  
                  while(!(newRgb.equals(currentRGB))){
                    if(newRgb.r>currentRGB.r){
                        currentRGB.r=currentRGB.r+1;
                        analogWrite(RedRGB,currentRGB.r);
                        delay(2);
                      }
                      else if(newRgb.r<currentRGB.r){
                        currentRGB.r=currentRGB.r-1;
                        analogWrite(RedRGB,currentRGB.r);
                        delay(2);
                      }
  
                      
                    if(newRgb.g>currentRGB.g){
                        currentRGB.g=currentRGB.g+1;
                        analogWrite(GreenRGB,currentRGB.g);
                        delay(2);
                      }
                      else if(newRgb.g<currentRGB.g){
                        currentRGB.g=currentRGB.g-1;
                        analogWrite(GreenRGB,currentRGB.g);
                        delay(2);
                      } 
  
                      
                     if(newRgb.b>currentRGB.b){
                        currentRGB.b=currentRGB.b+1;
                        analogWrite(BlueRGB,currentRGB.b);
                        delay(2);
                      }
                      else if(newRgb.b<currentRGB.b){
                        currentRGB.b=currentRGB.b-1;
                        analogWrite(BlueRGB,currentRGB.b);
                        delay(2);
                      } 
                    
                  
                  }
                  
                
                  
      
    
    }
    
