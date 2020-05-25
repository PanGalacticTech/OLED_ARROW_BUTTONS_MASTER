

/* These function control the structure of the menu and select functions based on menu position





*/


uint8_t pageNumber = 0;   // controls the displayed page.
uint8_t itemNumber = 0;   // can be used to select an option on the current page.
uint8_t charNumber = 0;    // Can be used to seek individual characters on the display.


uint8_t previousPage;     // Stores the last page accessed to compare and see if the page has been changed.





char lineWipe[23] = {"                     "};  // used to wipe old messages line by line

char  displayHeading [23] = {"Display Heading"};

char printUP[23] = {"Up"};
char printDOWN[23] = {"Down"};
char printLEFT[23] = {"Left"};
char printRIGHT[23] = {"Right"};
char printENTER[23] = {"Enter"};
char printBACK[23] = {"Back"};

char *printButtons[7] = {printUP, printDOWN, printLEFT, printRIGHT, printENTER, printBACK};



void staticMenu() {            // Updates the entire screen buffer based on the active page.


  if (pageNumber == 0) {

    display.setFont(&FreeSansBold12pt7b);
    sprintf(screenBuffer[0] , "%s", displayHeading );     // %s string of characters
    display.setFont();

    //  sprintf(screenBuffer[1] , "%s", lineWipe );

    displayButtonRead();


    // sprintf(screenBuffer[3] , "%20s", lineWipe);
    // sprintf(screenBuffer[4] , "%20s", lineWipe);
    //  sprintf(screenBuffer[5] , "%20s", lineWipe);
    // sprintf(screenBuffer[6] , "%20s", lineWipe);
    // sprintf(screenBuffer[7] , "%20s", lineWipe);
  }






}
