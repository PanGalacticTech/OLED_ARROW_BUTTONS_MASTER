

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



  for (int i = 0; i < 6; i++) {
    if (buttonStatus[i] == HIGH) {

      if (!buttonLockout) {
        buttonsPressed[i] = true;
        buttonLockout = true;
      }
    } else {
      buttonsPressed[i] = false;
    }
  }

  if (buttonStatus[0] == LOW && buttonStatus[1] == LOW && buttonStatus[2] == LOW && buttonStatus[3] == LOW && buttonStatus[4] == LOW && buttonStatus[5] == LOW) {   // Clunky AF
    buttonLockout = false;
  }


  // only trigger once untill buttonlockout has been lifted

  if (buttonsPressed[0]) {  // If Up has been Pressed
    if (scrollItem) {
      itemNumber--;
    }
    if (scrollPage) {
      pageNumber--;
    }
    if (scrollChar) {
      // charNumber--;                         // needs a function to change the specif char in the highlighted slot.
    }
    buttonsPressed[0] == false;
  }


  if (buttonsPressed[1]) {  // If Down has been Pressed
    if (scrollItem) {
      itemNumber++;
    }
    if (scrollPage) {
      pageNumber++;
    }
    if (scrollChar) {
      // charNumber++;                                      // needs a function to change the specif char in the highlighted slot.
    }
    buttonsPressed[1] == false;
  }


  if (buttonsPressed[2]) {  // If Left has been Pressed
    if (scrollChar) {
      charNumber--;
    }
    buttonsPressed[2] == false;
  }

  if (buttonsPressed[3]) {  // If right has been Pressed

    if (scrollChar) {
      charNumber++;
    }
    buttonsPressed[3] == false;
  }



  if (buttonsPressed[4]) {  // If Enter has been Pressed



    itemSelected = true;
    Serial.println("itemSelected");

    buttonsPressed[4] = false;
  }



  if (buttonsPressed[5]) {  // If Back has been Pressed

    pageNumber--;                  // goes back one page at whatever point the menu is at

    buttonsPressed[5] = false;
  }
}
