

/*  Button Functions
 * 
 * 
 * 
 * 
 * 
 */







void buttonRead() {

  for (int i = 0; i < numberofbuttons; i++) {
    buttonStatus[i] = digitalRead(buttonPins[i]);
  }

    // Testing Output
    if (printSerial){
     for (int i = 0; i < numberofbuttons; i++) {
        Serial.print(buttonStatus[i]);
     }
     Serial.println(" ");
    }
 
}
