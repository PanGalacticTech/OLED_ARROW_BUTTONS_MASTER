/*
    Functions to Help Debug functions



*/


bool debug = true;

void debugFunction() {

  if (debug) {


    Serial.print("Page Number: ");
    Serial.print(pageNumber);

    Serial.print("   Item Number: ");
    Serial.print(itemNumber);

    Serial.print("   Char Number: ");
    Serial.print(charNumber);





    Serial.println(" ");

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

  }

}
