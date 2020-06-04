
/*   Functions to Control the OLED screen Buffer




*/




void oledUpdate() {
  //if (screenUpdate == true) {
  // NEW
  for (int i = 0; i < 8; i++) {
    if (strcmp(screenBuffer[i], PscreenBuffer[i]) != 0) {   // Compare contents of old buffer and new buffer line by line
      strcpy(PscreenBuffer[i],  screenBuffer[i]);            // if a difference is found new buffer is copied into previous buffer
      screenUpdate = true;                                    // Flag to write to screen set to true
    }
  }

  for (int i = 0; i < 8; i++) {                                     // Sets text colours   // Could also add function to change fonts based on another int array

    if (lineColours[i] != PlineColours[i]) {
      screenUpdate = true;
      PlineColours[i] = lineColours[i];                            // checks if line colours have changed and sets screen to update if it has.
    }
    display.setTextColor(lineColours[i], !lineColours[i]);
    display.setCursor(0, (i * 8));
    display.print(screenBuffer[i]);
  }

  if (screenUpdate == true) {
    display.display();
    //   Serial.print("Oled Updated");
    screenUpdate = false;
  }
}


void oledWipeHighlight(){          // Script to wipe all highlighted lines 

  for (int i = 0; i < numberOfItems + 1; i++) {                       // THIS IS SO MUCH NEATER THAN MY LAST IMPLEMENTATION

    lineColours[i] = 1;                       // Turn all highlighted lines off

  }
  
}



void oledWipeBuffer() {




  sprintf(screenBuffer[0] , "%22s", lineWipe );
  sprintf(screenBuffer[1] , "%22s", lineWipe );
  sprintf(screenBuffer[2] , "%22s", lineWipe );
  sprintf(screenBuffer[3] , "%22s", lineWipe);
  sprintf(screenBuffer[4] , "%22s", lineWipe);
  sprintf(screenBuffer[5] , "%22s", lineWipe);
  sprintf(screenBuffer[6] , "%22s", lineWipe);
  sprintf(screenBuffer[7] , "%22s", lineWipe );



}
