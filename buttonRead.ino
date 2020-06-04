

/*  Button Functions





*/







void buttonRead() {

  for (int i = 0; i < numberofbuttons; i++) {
    buttonStatus[i] = digitalRead(buttonPins[i]);
  }
  /*
    // Testing Output
    if (printSerial) {
      for (int i = 0; i < numberofbuttons; i++) {
        Serial.print(buttonStatus[i]);
      }
      Serial.println(" ");
    }
  */
}





bool buttonLockout = false;


bool upPressed;
bool downPressed;
bool leftPressed;
bool rightPressed;
bool enterPressed;
bool backPressed;

bool buttonsPressed[6] = {upPressed, downPressed, leftPressed, rightPressed, enterPressed, backPressed};


// Useful button press strings;

uint8_t allbuttonsoff[6] = {0, 0, 0, 0, 0, 0};




void buttonControl() {


  if (!buttonLockout) {

    for (int i = 0; i < 6; i++) {

      buttonsPressed[i] = buttonStatus[i];

      if (buttonsPressed[i] == HIGH) {
        buttonsPressed[i] = true;
        buttonLockout = true;
      }
    }
  }

  if (buttonStatus[0] == LOW && buttonStatus[1] == LOW && buttonStatus[2] == LOW && buttonStatus[3] == LOW && buttonStatus[4] == LOW && buttonStatus[5] == LOW) {   // Clunky AF
    buttonLockout = false;
  }


  // only trigger once untill buttonlockout has been lifted

  if (buttonsPressed[0]) {                // If Up has been Pressed
    if (scrollItem) {
      itemNumber--;
    }
    if (scrollPage) {
      // pageNumber--;
    }
    if (scrollChar) {
      charUp = true;                       // needs a function to change the specif char in the highlighted slot.
    }
    buttonsPressed[0] = false;
  }



  if (buttonsPressed[1]) {                  // If Down has been Pressed
    if (scrollItem) {
      itemNumber++;
    }
    if (scrollPage) {
      //   pageNumber++;
    }
    if (scrollChar) {
      charDown = true;                                   // needs a function to change the specif char in the highlighted slot.
    }
    buttonsPressed[1] = false;
  }



  if (buttonsPressed[2]) {                     // If Left has been Pressed
    if (scrollPage) {
      pageNumber--;
    }
    if (scrollChar) {
      if (!charSaveMode) {                       // annoyingly clunky bug fix.
        charNumber--;
      }
    }
    buttonsPressed[2] = false;
  }


  if (buttonsPressed[3]) {                 // If right has been Pressed
    if (scrollPage) {
      pageNumber++;
    }
    if (scrollChar) {
      charNumber++;
    }
    buttonsPressed[3] = false;
  }



  if (buttonsPressed[4]) {                  // If Enter has been Pressed

    //  if (scrollPage) {
    //    scrollPage = false;
    //    scrollItem = true;
    //   } else if (scrollItem) {
    //    scrollItem = false;
    //    scrollPage = true;
    //   }

    itemSelected = true;
    //  Serial.println("itemSelected");

    buttonsPressed[4] = false;
  }



  if (buttonsPressed[5]) {  // If Back has been Pressed

   if (!charSaveMode) {                         // when char save mode is active we want the back button to only return to being able to edit the string      
    
    if (pageNumber != 0) {                 // This is the same as if(pageNumber > 0){}
      pageNumber--;                     // goes back one page at whatever point the menu is at unless already at page 0
    }

                          
      hiddenPageNumber = 0;                      // 
      scrollPage = true;                                 // reset these operational bools
      scrollItem = true;
      scrollChar = false;

    } else {
      charSaveMode = false;
      lineColours[6] = 1;
      scrollChar = true;
    }





    buttonsPressed[5] = false;
  }
}
