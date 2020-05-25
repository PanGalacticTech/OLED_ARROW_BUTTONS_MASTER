


/*

    Display Utilites






    These functions can be used when staticMenu calls a page to display data recorded from hardware.



*/




// Prints the name of the button inputs and their status to the screen
// Useful for testing hardware

void displayButtonRead() {



  for (int i = 0; i < 6; i++) {

    sprintf(screenBuffer[i + 2] , "%-18s %u", printButtons[i], buttonStatus[i]);

  }

}
