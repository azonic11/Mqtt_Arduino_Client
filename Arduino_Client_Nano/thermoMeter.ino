
 
    int median (int a[], int size) {
                  for(int i=0; i<(size-1); i++) {
                      for(int o=0; o<(size-(i+1)); o++) {
                              if(a[o] > a[o+1]) {
                                  int t = a[o];
                                  a[o] = a[o+1];
                                  a[o+1] = t;
                              }
                      }
                  }
                
                return(a[size/2]);
              }
        
 
 void thermoMeter(int afterPoint,int tempSendInterv){

    


  
    
    if (currentMillis - previousMillis1 >= tempSendInterv) {
        previousMillis1 = currentMillis;

        for(int i=0;i<100;i++){
          delay(5);
          avarageTemp[i]= analogRead(TempPin)-6;
        }
        
        RawValue=median(avarageTemp,100);
        tempVal = (RawValue / 1024.0) * 5000; // 5000 to get millivots. 
        tempVal=tempVal* 0.1;

      

        
        tempMessage="badRoom/temp&";
        //tempVal = (5.0 * analogRead(tempPin) * 100.0) / 1024;
        
        tempMessage=tempMessage+String(tempVal);
        Serial.println(tempMessage);
       
    }

}
 
