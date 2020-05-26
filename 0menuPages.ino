

/* These function control the structure of the menu and select functions based on menu position





*/


uint8_t pageNumber = 0;   // controls the displayed page.
uint8_t itemNumber = 0;   // can be used to select an option on the current page.
uint8_t charNumber = 0;    // Can be used to seek individual characters on the display.


uint8_t previousPage;     // Stores the last page accessed to compare and see if the page has been changed.




char lineWipe[23] = {"                     "};  // used to wipe old messages line by line



//
char  displayHeading [23] = {"Display Heading"};

char printUP[23] = {"Up"};
char printDOWN[23] = {"Down"};
char printLEFT[23] = {"Left"};
char printRIGHT[23] = {"Right"};
char printENTER[23] = {"Enter"};
char printBACK[23] = {"Back"};

char *printButtons[7] = {printUP, printDOWN, printLEFT, printRIGHT, printENTER, printBACK};


//

char settingsHeading[23] = {"Settings"};

char variable1Name[23] = {"Variable One"};
char variable2Name[23] = {"Variable Two"};


char variable1String[] = {"StringOne"};
char variable2String[] = {"StringTwo"};






void staticMenu() {            // Updates the entire screen buffer based on the active page.


  if (previousPage != pageNumber) {

    for (int i = 0; i < 8; i++) {
      sprintf(screenBuffer[i], "%s", lineWipe);     // %s string of characters
      //  messageReplace(i , lineWipe);   //Clear Text Buffer recently addedm remove if problems occur
    }
  }




  if (pageNumber == 0) {

    sprintf(screenBuffer[0] , "%s", displayHeading );     // %s string of characters

    sprintf(screenBuffer[1] , "%s", lineWipe );

    displayButtonRead();

    // sprintf(screenBuffer[3] , "%20s", lineWipe);
    // sprintf(screenBuffer[4] , "%20s", lineWipe);
    //  sprintf(screenBuffer[5] , "%20s", lineWipe);
    // sprintf(screenBuffer[6] , "%20s", lineWipe);
    // sprintf(screenBuffer[7] , "%20s", lineWipe);
  }


  if (pageNumber == 1) {

    sprintf(screenBuffer[0] , "%s", settingsHeading );     // %s string of characters

    sprintf(screenBuffer[1] , "%s", lineWipe );

    sprintf(screenBuffer[3] , "%s %-s", variable1Name, variable1String);
    sprintf(screenBuffer[4] , "%s %-s", variable2Name, variable2String);
    //  sprintf(screenBuffer[5] , "%20s", lineWipe);
    // sprintf(screenBuffer[6] , "%20s", lineWipe);
    // sprintf(screenBuffer[7] , "%20s", lineWipe);
  }

  if (pageNumber == 2) {


    sprintf(screenBuffer[0] , "%s", displayHeading );     // %s string of characters


    //  sprintf(screenBuffer[1] , "%s", lineWipe );

    displayButtonRead();


    // sprintf(screenBuffer[3] , "%20s", lineWipe);
    // sprintf(screenBuffer[4] , "%20s", lineWipe);
    //  sprintf(screenBuffer[5] , "%20s", lineWipe);
    // sprintf(screenBuffer[6] , "%20s", lineWipe);
    // sprintf(screenBuffer[7] , "%20s", lineWipe);
  }
  previousPage = pageNumber;
}





void itemNav() {  // Function to select and highlight specific line

  for (int i = 0; i < 8; i++) {                         // THIS IS SO MUCH NEATER THAN MY LAST IMPLEMENTATION

    lineColours[itemNumber] = 1;                       // Turn all highlighted lines off

  }

  lineColours[itemNumber] = 0;                     // highlight the line selected by itemNumber

}




bool itemSelected;   // if enter button pressed itemSelected = true


void itemSelect() {


  if (itemSelected) {


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 0 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (pageNumber == 0) {

      if (itemNumber == 0) {

        pageNumber = 1;                        // navigate to page 1

      } else if (itemNumber == 1) {


      }


      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } else if (pageNumber == 1) {

      if (itemNumber == 0) {

        pageNumber = 0;    // return to page 0

      } else if (itemNumber == 1) {


      }




      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } else if (pageNumber == 2) {

      pageNumber = 1;

      if (itemNumber == 0) {


      } else if (itemNumber == 1) {


      }





    }











    itemSelected = false;
  }




}
