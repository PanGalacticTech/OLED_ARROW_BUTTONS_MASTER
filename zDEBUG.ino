/*
    Functions to Help Debug functions



*/




unsigned long debuggingDelay = 100;    // delay between debugging printouts
unsigned long lastDebugPrint;



bool debug = true;

void debugFunction() {

  if (debug) {

    if (millis() - lastDebugPrint >= debuggingDelay) {

      // Put all Debugging Printouts here and comment in the ones being used



      // Hardware Linked Variables:


      //    Serial.print("Page Number: ");
      //    Serial.print(pageNumber);
      //       Serial.print("  Scroll: ");
      //    Serial.print(scrollPage);


      //    Serial.print("    Item Number: ");
      //    Serial.print(itemNumber);
      //    Serial.print("  Scroll: ");
      //    Serial.print(scrollItem);

   //   Serial.print("    Char Number: ");
   //   Serial.print(charNumber);
      //    Serial.print("  Scroll: ");
      //    Serial.print(scrollChar);


      //    Serial.print("   Button Locked: ");
      //    Serial.print(buttonLockout);






   //   Serial.println(" ");

      /*
        // Testing Output
        if (printSerial) {
          for (int i = 0; i < numberofbuttons; i++) {
            Serial.print(buttonStatus[i]);
          }
          Serial.println(" ");
        }
        //Serial.print(pageNumber);
      */



      lastDebugPrint = millis();
    }
  }
}
