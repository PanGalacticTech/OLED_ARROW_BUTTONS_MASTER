//
/* Global Variables & User Options




*/



// Configuration Variables//

// These variables are ones that would be saved into a re-writeable config file.
// Defaults will be saved perminantly in flash here





bool printSerial = true;



// These bools change how the buttons function depending on what state the program is in.
bool scrollPage = true;
bool scrollItem = true;
bool scrollChar;



uint8_t charSelect;


// Animation Variables


bool animationFinished;                // this can be used to tell other function that animation has finished so pages can return to their stable state

bool triggerFlashBar = false;

unsigned long flashingDelay = 200;    // delay between flashes
unsigned long lastFlash;

unsigned long animationTime = 700;         // length of time to perform animation
unsigned long animationTimer;          // Timer for time flashing
int flashLine;   // int to hold number of line to flash. will only work one at a time 
// function can set flashLine as a line number, then set triggerFlashbar = true and animation will flash untill timers are up. this function is called in main loop as flashingBar(flashLine);
int8_t returnPage;    // place to return to after animations finished.
int8_t returnItem;



int8_t numberOfPages = 4;    //
int8_t numberOfItems = 7;    // max number of items per page (should be -1 as array starts at 0)
int8_t numberOfChar = 21;    // Max number of chars to fit on the screen/ Max data set. (+1 due to array size)



bool charSaveMode;  // when true this triggers char save mode.


bool charUp;
bool charDown;

// OLED Variables & Screen Buffers


bool screenUpdate = false;

uint8_t lineColours[8] = {1, 1, 1, 1, 1, 1, 1, 1};   // used to control line highlighting effect. 1 = Black Background, 0 = White Background Passed to oledUpdate

uint8_t PlineColours[8];   // Previous line colour

//############################## Empty Screen Buffers #########################################################
char oledLine0[23] = {"                     "}; //
char oledLine1[23] = {"                     "}; //
char oledLine2[23] = {"                     "}; //
char oledLine3[23] = {"                     "}; //
char oledLine4[23] = {"                     "}; //
char oledLine5[23] = {"                     "}; //
char oledLine6[23] = {"                     "}; //
char oledLine7[23] = {"                     "}; //

char *screenBuffer[9] = {oledLine0, oledLine1, oledLine2 , oledLine3, oledLine4, oledLine5, oledLine6, oledLine7};



// Previous Screen Buffers;
char PoledLine0[23];
char PoledLine1[23];
char PoledLine2[23];
char PoledLine3[23];
char PoledLine4[23];
char PoledLine5[23];
char PoledLine6[23];
char PoledLine7[23];

char *PscreenBuffer[9] = {PoledLine0, PoledLine1, PoledLine2 , PoledLine3, PoledLine4, PoledLine5, PoledLine6, PoledLine7};

//############################## Empty Screen Buffers #########################################################


// Button Variables

uint8_t buttonStatus[6];
