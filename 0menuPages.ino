

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

char variable1String[23] = {"StringOne"};
char variable2String[23] = {"StringTwo"};
char variable3String[23] = {"StringThree"};
char variable4String[23] = {"StringFour"};
char variable5String[23] = {"StringFive"};
char variable6String[23] = {"StringSix"};


char string12345[23] = {"0123456789ABCDEFGHIJK"};



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

char saveText[23] = {"Save"};

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

      screenUpdate = true;
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

      //  sprintf(screenBuffer[3] , "%s %-s", variable1Name, variable1String);
      sprintf(screenBuffer[3] , "%-20s", variable1Name);
      sprintf(screenBuffer[4] , "%20s", variable1String);

      //      sprintf(screenBuffer[5] , "%s %-s", variable2Name, variable2String);
      sprintf(screenBuffer[5] , "%-20s", variable2Name);
      sprintf(screenBuffer[6] , "%20s", variable2String);

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



    //  previousPage = pageNumber;

  }

  if (hiddenPageNumber == 1) {                     // This will be the page to edit string one


    sprintf(screenBuffer[0] , "%21s", hiddenPageHeadingOne);     // %s string of characters

    stringEditPage(variable1Name, variable1String);

  }

  previousPage = pageNumber;
  previousHiddenPage = hiddenPageNumber;

}






char editString[23];

bool openString;

// int16_t sizeofString;

uint8_t inStringLength;




//void stringEditPage(char variableName[23], char inputString[23]) {                  // passed 2 arguments name of the variable string and the string to be edited (also will need some reference to the origonal string to save, unless this entire routine can be passed as and argument

void stringEditPage(char variableName[23], char inputString[23]) {

  inStringLength = strlen(inputString);

  if (openString) {                                       // if string has been opened for the first time without saving

    sprintf(editString, "%21s", inputString);                // copy input string to edit string that is 22 chars long   changed from 20 to 21

    charNumber = 21 - inStringLength;                           // This line makes sure cursor is highlighting first character in string
    openString = false;
  }

  sizeofString = strlen(editString);                // this should always return 21

  //  Serial.print("size of string: ");
  // Serial.println(sizeofString);


  sprintf(screenBuffer[1] , "%-21s", variableName);                                   // name of the data point that is being edited


  sprintf(screenBuffer[2] , "%-i              %i   ", editString[charNumber], charNumber);         // prints the int value of the char to the left of the screen, the currently selected char to the right of the screen




  sprintf(screenBuffer[3], "%*c%*s", charNumber + (22 - sizeofString) , downArrow, (sizeofString - charNumber) , space);    // prints an arrow above the active char    //21 or 22 on this line

  // sprintf(screenBuffer[3], "%*c", charNumber + (22 - sizeofString) , downArrow);    // prints an arrow above the active char    //21 or 22 on this line



  sprintf(screenBuffer[4] , "%21s", editString);                                                                             // string that is being edited                    // 21 or 22 on this line


  sprintf(screenBuffer[5], "%*c%*s", charNumber + (22 - sizeofString) , upArrow, (sizeofString - charNumber) , space);       // prints arrow below active char


  sprintf(screenBuffer[6] , "%-20s" , saveText);

  //sprintf(screenBuffer[7], "SizeOf String: %10-u" , sizeofString);                                                           // Prints size of string, this should always return 23 now.



  if (charNumber < 0) {
    // charSaveMode = false;
    charNumber = 20;                                                          // Changed it so it always prints save, but should only highlight save when we want savemode to be active.
    //  lineColours[6] = 1;
  }

  // Char Number Roll Around
  if (charNumber > 20) {
    charNumber = 0;
  }

  if (charNumber == 0) {


    //  lineColours[6] = 0;
    //  charSaveMode = true;                                                                                 // charSaveMode = true needs to be added to enter button while this page is active

  }



  if (charUp) {                                                       // All of this is broken right now



    charSelect = uint8_t (editString[charNumber]);                           // unsigned int passed char that is saved in editString the currently selected char. I think this needs to be a CAST to int

    //    Serial.print(charSelect);                                                    // Serial print this int

    //  charSelect = charRemap(charSelect, 1);                                     // int that pertains to a specific char is passed to remap function, along with direction the char needs to move
    // this function needs to take this int, remap it to our new table, add one or minus one, then translate the int back to
    // the int that relates to the new char from the table.




    //   editString[charNumber] =  char(charSelect);                            // that int is then passed back to editString{charNumber] so this needs to be a cast to a char.
    // this can be passed directly it doesnt need to be split into 2 lines
    editString[charNumber] = char(charRemap(charSelect, 1));

    //   Serial.print(editString[charNumber]);                                         // Serialprint the edited char
    //  Serial.print(" ");
    //  Serial.print(" ");
    charUp = false;                                                          // action has been performed, flag can be unset


  } else if (charDown) {

    charSelect = uint8_t (editString[charNumber]);                           // unsigned int passed char that is saved in editString the currently selected char. I think this needs to be a CAST to int

    //   Serial.print(charSelect);                                                    // Serial print this int

    //  charSelect = charRemap(charSelect, 1);                                     // int that pertains to a specific char is passed to remap function, along with direction the char needs to move
    // this function needs to take this int, remap it to our new table, add one or minus one, then translate the int back to
    // the int that relates to the new char from the table.


    //   editString[charNumber] =  char(charSelect);                            // that int is then passed back to editString{charNumber] so this needs to be a cast to a char.
    // this can be passed directly it doesnt need to be split into 2 lines
    editString[charNumber] = char(charRemap(charSelect, 0));

    //   Serial.print(editString[charNumber]);                                         // Serialprint the edited char
    //   Serial.print(" ");
    //   Serial.print(" ");

    charDown = false;
  }

  // Function to add another slot to char string // Redundent

  /*
    if (sizeofString < 22) {

      if (editString[0] != 32) {

        sprintf(editString, " %s", editString);
        charNumber++;

      }
    }
    if (editString[0] == 32) {

  */
  // This is all redundent now (I hope)




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
  if (pageNumber != 9) {                                   // bug fix to deal with my stupid idea of making page 9 null rather than page 0
    if (pageNumber > numberOfPages) {
      pageNumber = 0;
    } else if (pageNumber < 0) {
      pageNumber = numberOfPages;
    }
  }
  /*
    // Char Number Roll Around
    if (charNumber > numberOfChar) {
      charNumber = 0;
    } else if (charNumber < 0) {
      charNumber = numberOfChar;
    }
  */


  // ~~~~~~~~~~~~~~~~~~ Text and Line Highlighting~~~~~~~~~~~~~~~~~~~

  if (pageNumber != 9) {                                                                                                       // Another Bug fix to handle when displaying hidden pages and page 9 is null

    for (int i = 0; i < numberOfItems + 1; i++) {                       // THIS IS SO MUCH NEATER THAN MY LAST IMPLEMENTATION

      lineColours[i] = 1;                       // Turn all highlighted lines off

    }

    if (scrollItem) {
      lineColours[itemNumber] = 0;                     // highlight the line selected by itemNumber if itemscroll is active
    }
  }
}







bool itemSelected;   // if enter button pressed itemSelected = true


void itemSelect() {


  if (itemSelected) {


    Serial.printf("itemSelected Page: %i Item: %i hp: %i", pageNumber, itemNumber, hiddenPageNumber);
    Serial.println(" ");

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

        //   oledWipeBuffer();
        hiddenPageNumber = 1;                           // Navigate to hiddenPageNumber 1
        pageNumber = 9;                                // this just needs to be any page not previously used. In future might make this 0 and move every page up one
        scrollPage = false;
        scrollItem = false;
        scrollChar = true;
        openString = true;
        oledWipeHighlight();


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

    else if (charSaveMode) {                             // Function here to save editString into the variable that was passed to it. I think this is a tomorro job now.

      flashLine = 6;
      triggerFlashBar = true;
      returnPage = 1;    // sets to return to page 1 when animation finished
      returnItem = 0;
      scrollItem = true;
      scrollPage = true;
      animationTimer = millis();    // bug fix would like this to be more self contained in animation function
      charSaveMode = false;

      // save char here
      //     *variable1String = saveCharString();
      saveCharString();


    }

    else if (hiddenPageNumber == 1) {
      // Serial.println("TEST LOCATION 1");
      scrollChar = false;
      charSaveMode = true;
      lineColours[6] = 0;

    }


    /*
      else if (charSaveMode) {                      // if enter is pressed while in char save mode string is saved and navigated back to the page it started at

      pageNumber = 1;
      hiddenPageNumber = 0;
      charNumber = 0;
      charSaveMode = false;

      scrollItem = true;
      scrollPage = true;
      scrollChar = false;

      oledWipeBuffer();

      }

    */



    itemSelected = false;
  }
}






// returns whatever is in editString without leading zeros

void saveCharString() {

  uint8_t x;    // value to save location of the start of the string
  uint8_t z = 0 ;       // variable to accumilate and cycle through array seperate to the for loop
  bool startTranslate = false;   // bool used to start translation of char string into shorter string

  // this string cuts off any leading zeros from our edit string

  sizeofString = strlen(variable1String);                // this should return something smaller than 21

  Serial.printf(" Pre Translation: %s Length: %u", variable1String, sizeofString);
  Serial.println(" ");


  for (int i = 0 ; i < 21; i++) {

    if (!startTranslate) {
      if (editString[i] != 32) {         // if input string does not contain a leading space

        Serial.print("Char Number: ");
        Serial.print(i);
        Serial.print("  = ");
        Serial.println(editString[i]);


        x = i;                            // record number of leading spaces
        startTranslate = true;
      }
    }
  }

  startTranslate = false;

  for (int i = x; i < 21; i++) {

    Serial.print("editString: ");
    Serial.print(" i = ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(editString[i]);
    Serial.print("    ");
    Serial.print(" variableString z  = ");
    Serial.print(z);
    Serial.print(" = ");
    variable1String[z] = editString[i];
    Serial.println(variable1String[z]);
    z++;
  }

  // this should have switched everything out fairly robustly.


  //probably need to wipe editString here though

  sprintf(editString , "%20s" , lineWipe);


  Serial.printf("Post Translation: %s Length: %u", variable1String, sizeofString);
  Serial.println(" ");
  Serial.print(":");
  Serial.print(variable1String);
  Serial.println(":");

  //sprintf(shorterString, "%s", editString);

  // sprintf(variable1String, "%s", editString);                        // this doesnt work as it doesnt shorten string and remove leading spaces

  sizeofString = strlen(variable1String);                // this should return something smaller than 21

  sprintf(screenBuffer[6] , "%-20s Chars Saved: %u" , saveText, sizeofString);



  /// delay(2000);   // just for testing

  //return &shorterString;
}
