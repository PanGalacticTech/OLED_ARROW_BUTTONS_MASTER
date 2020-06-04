/*
    Functions to generate animations




*/



void flashingBar(int lineNumber) {

  if (triggerFlashBar) {

    //  animationTimer = millis();


    if (millis() - lastFlash >= flashingDelay) {

      if (lineColours[lineNumber] == 0) {
        lineColours[lineNumber] = 1;
      } else if (lineColours[lineNumber] == 1) {
        lineColours[lineNumber] = 0;
      }


    }

    if (millis() - animationTimer >= animationTime) {
      triggerFlashBar = false;
      animationFinished = true;
    }
  }
}

//'animationEnd

//void animationEnd(int8_t Rpage, int8_t Ritem = 0) {    // this can be passed numbers to return to specific pages after animations have finished animating

void animationEnd(int8_t Rpage) {

//, int Rhidden = 0

if (animationFinished) {

  pageNumber = Rpage;
  //itemNumber = Ritem;
  itemNumber = 0;
  //hiddenPageNumber = Rhidden;
  hiddenPageNumber = 0;

  animationFinished = false;
}

}
