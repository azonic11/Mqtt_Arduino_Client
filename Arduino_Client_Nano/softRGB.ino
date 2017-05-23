    void softRGB(RGB newRgb){
                  
                  while(!((newRgb.r==currentRGB.r && newRgb.g==currentRGB.g) && newRgb.b==currentRGB.b)){
                 //  while(newRgb.r!=rgb.r){ 
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
                 //  } 
                // while(newRgb.g!=rgb.g){
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
              //   }
              //   while(newRgb.b!=rgb.b){
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
    
