
/*   Functions to Control the OLED screen Buffer
 * 
 * 
 * 
 * 
 */


bool screenUpdate = false;


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
