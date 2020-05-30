

/* These function control the structure of the menu and select functions based on menu position





*/


int8_t pageNumber = 0;   // controls the displayed page.
int8_t itemNumber = 0;   // can be used to select an option on the current page.
int8_t charNumber = 0;    // Can be used to seek individual characters on the display.

int8_t hiddenPageNumber = 0;  // if hiddenPage number = zero functions off. any numbers +1 can be used to display extra pages not accessable from the main rota of pages.

int8_t previousPage;     // Stores the last page accessed to compare and see if the page has been changed.

int8_t previousHiddenPage;




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

char variable1Name[23] = {"VariableOne"};
char variable2Name[23] = {"VariableTwo"};
char variable3Name[23] = {"VariableThree"};
char variable4Name[23] = {"VariableFour"};
char variable5Name[23] = {"VariableFive"};
char variable6Name[23] = {"VariableSix"};

char variable1String[] = {"StringOne"};
char variable2String[] = {"StringTwo"};
char variable3String[] = {"StringThree"};
char variable4String[] = {"StringFour"};
char variable5String[] = {"StringFive"};
char variable6String[] = {"StringSix"};




char pageHeadingZero[23] = {"Page Zero"};
char pageHeadingOne[23] = {"Page One"};
char pageHeadingTwo[23] = {"Page Two"};
char pageHeadingThree[23] = {"Page Three"};
char pageHeadingFour[23] = {"Page Four"};
char pageHeadingFivee[23] = {"Page Five"};
char pageHeadingSix[23] = {"Page Six"};


char hiddenPageHeadingOne[23] = {"Hidden Page One"};


char option1text[23] = {"OptionOne"};
char option2text[23] = {"OptionTwo"};
char option3text[23] = {"OptionThree"};
char option4text[23] = {"OptionFour"};

char *optionArray[5] = {option1text, option2text, option2text, option4text};

char item1Text[23] = {"itemOne"};
char item2Text[23] = {"itemTwo"};
char item3Text[23] = {"itemThree"};
char item4Text[23] = {"itemFour"};
char item5Text[23] = {"itemFive"};
char item6Text[23] = {"itemSix"};
char item7Text[23] = {"itemSeven"};
char item8Text[23] = {"itemEight"};

char *itemTextArray[9] = {item1Text, item2Text, item3Text, item4Text, item5Text, item6Text, item7Text, item8Text};

int8_t   upArrow = 0x18;    ///
int8_t downArrow = 0x19;   ///

char space[2] = {" "};



uint8_t currentOption = 0;

uint8_t sizeofString;




void staticMenu() {            // Updates the entire screen buffer based on the active page.


  if (previousPage != pageNumber || previousHiddenPage != hiddenPageNumber) {



    for (int i = 0; i < 8; i++) {
     
    Serial.printf("Screen Line: %i Wiped" , i);
    Serial.println(" ");
      
      sprintf(screenBuffer[i], "%22s", lineWipe);     // %s string of characters
      //  messageReplace(i , lineWipe);   //Clear Text Buffer recently addedm remove if problems occur
    }
  }


  if (hiddenPageNumber == 0) {                                                                     // This lets me add hidden pages not accessable from the arrow buttons but functions can be used to send the user to them.

    if (pageNumber == 0) {

      sprintf(screenBuffer[0] , "%-21s", displayHeading );     // %s string of characters
      sprintf(screenBuffer[1] , "%-21s", pageHeadingZero );     // %s string of characters

      // sprintf(screenBuffer[1] , "%s", lineWipe );

      displayButtonRead();

      // sprintf(screenBuffer[3] , "%20s", lineWipe);
      // sprintf(screenBuffer[4] , "%20s", lineWipe);
      //  sprintf(screenBuffer[5] , "%20s", lineWipe);
      // sprintf(screenBuffer[6] , "%20s", lineWipe);
      // sprintf(screenBuffer[7] , "%20s", lineWipe);
    }


    if (pageNumber == 1) {

      sprintf(screenBuffer[0] , "%-21s", settingsHeading );     // %s string of characters

      sprintf(screenBuffer[1] , "%-21s", pageHeadingOne);

      sprintf(screenBuffer[3] , "%s %-s", variable1Name, variable1String);
      sprintf(screenBuffer[4] , "%s %-s", variable2Name, variable2String);
      //  sprintf(screenBuffer[5] , "%20s", lineWipe);
      // sprintf(screenBuffer[6] , "%20s", lineWipe);
      // sprintf(screenBuffer[7] , "%20s", lineWipe);
    }

    if (pageNumber == 2) {


      sprintf(screenBuffer[0] , "%s", pageHeadingTwo );     // %s string of characters


      sprintf(screenBuffer[1] , "%s", lineWipe );

      sprintf(screenBuffer[3] , "%20s", optionArray[currentOption]);
      sprintf(screenBuffer[4] , "%20s", lineWipe);
      sprintf(screenBuffer[5] , "%20s", lineWipe);
      sprintf(screenBuffer[6] , "%20s", lineWipe);
      sprintf(screenBuffer[7] , "%20s", lineWipe);
    }


    if (pageNumber == 3) {


      sprintf(screenBuffer[0] , "%s", pageHeadingThree);     // %s string of characters


      sprintf(screenBuffer[1] , "%s", lineWipe );
      sprintf(screenBuffer[2] , "%s", lineWipe );
      sprintf(screenBuffer[3] , "%s", lineWipe );
      sprintf(screenBuffer[4] , "%20s", optionArray[currentOption]);

      sprintf(screenBuffer[5] , "%20s", lineWipe);
      sprintf(screenBuffer[6] , "%20s", lineWipe);
      sprintf(screenBuffer[7] , "%20s", lineWipe);
    }



    if (pageNumber == 4) {

      sprintf(screenBuffer[0] , "%s", pageHeadingFour);     // %s string of characters


      sprintf(screenBuffer[1] , "%s", lineWipe );
      sprintf(screenBuffer[2] , "%s", lineWipe );
      sprintf(screenBuffer[3] , "%s", lineWipe );
      sprintf(screenBuffer[4] , "%20s", lineWipe);
      sprintf(screenBuffer[5] , "%20s", optionArray[currentOption]);
      sprintf(screenBuffer[6] , "%20s", lineWipe);
      sprintf(screenBuffer[7] , "%20s", lineWipe);
    }



    previousPage = pageNumber;

  }

  if (hiddenPageNumber == 1) {                     // This will be the page to edit string one

    sizeofString = sizeof(variable1String);


    sprintf(screenBuffer[0] , "%-21s", hiddenPageHeadingOne);     // %s string of characters


    sprintf(screenBuffer[1] , "%21s", variable1Name);
    sprintf(screenBuffer[2] , "%21i", charNumber);

    // Need a way to print arrows here

    //  sprintf(screenBuffer[3], "%c%s",  downArrow, lineWipe);              // Prints arrow
  //  sprintf(screenBuffer[3], "%*s%*c%*s", charNumber , space, (sizeofString - (21 - charNumber)),  downArrow, (20-charNumber), space);

    sprintf(screenBuffer[3], " %*c ", (20-charNumber+sizeofString),  downArrow);              // Prints arrow

      sprintf(screenBuffer[4] , "%22s", variable1String);

   // sprintf(screenBuffer[5], "%s%*c%s", space, (sizeofString - (21 - charNumber)),  upArrow, space);         // (22-(20-0)
    //  sprintf(screenBuffer[5], "%c%s",  upArrow, lineWipe);              // Prints arrow

    sprintf(screenBuffer[7], "SizeOf String: %10-u" , sizeofString);

  }

  previousHiddenPage = hiddenPageNumber;

}







void itemNav() {  // Function to select and highlight specific line


  // Roll Arounds a Limits on navigation


  // Itemnumber roll around
  if (itemNumber > numberOfItems) {
    itemNumber = 0;
  } else if (itemNumber < 0) {
    itemNumber = numberOfItems;
  }

  // Page Number Roll Around
  if (pageNumber > numberOfPages) {
    pageNumber = 0;
  } else if (pageNumber < 0) {
    pageNumber = numberOfPages;
  }

  // Char Number Roll Around
  if (charNumber > numberOfChar) {
    charNumber = 0;
  } else if (charNumber < 0) {
    charNumber = numberOfChar;
  }



  // ~~~~~~~~~~~~~~~~~~ Text and Line Highlighting~~~~~~~~~~~~~~~~~~~

  for (int i = 0; i < numberOfItems + 1; i++) {                       // THIS IS SO MUCH NEATER THAN MY LAST IMPLEMENTATION

    lineColours[i] = 1;                       // Turn all highlighted lines off

  }

  if (scrollItem) {
    lineColours[itemNumber] = 0;                     // highlight the line selected by itemNumber if itemscroll is active
  }
}








bool itemSelected;   // if enter button pressed itemSelected = true


void itemSelect() {


  if (itemSelected) {


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 0 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    if (pageNumber == 0) {

      if (itemNumber == 0) {


        // pageNumber = 1;                        // navigate to page 1
        //  scrollPage = false;
        // scrollItem = true;

      } else if (itemNumber == 1) {


      }


      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } else if (pageNumber == 1) {

      if (itemNumber == 0) {

        //    pageNumber = 0;    // return to page 0
        //   scrollItem = false;
        //   scrollPage = true;

      } else if (itemNumber == 1) {

        //    pageNumber = 2;                                    // Navigate to page 2
        //   scrollPage = false;
        //   scrollItem = false;
        //   scrollChar = true;
      } else if (itemNumber == 2) {

        //    pageNumber = 2;                                    // Navigate to page 2
        //   scrollPage = false;
        //   scrollItem = false;
        //   scrollChar = true;
      } else if (itemNumber == 3) {

        hiddenPageNumber = 1;                           // Navigate to hiddenPageNumber 1
        scrollPage = false;
        scrollItem = false;
        scrollChar = true;

      }  else if (itemNumber == 4) {


        //   scrollPage = false;
        //   scrollItem = false;
        //   scrollChar = true;
      }







      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Page 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    } else if (pageNumber == 2) {



      if (itemNumber == 0) {

        //   pageNumber = 1;
        //   scrollItem = true;
        //   scrollPage = false;
        //
      } else if (itemNumber == 1) {


      }





    }











    itemSelected = false;
  }
}
