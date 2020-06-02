



/*
 *  ASCII Help
 *  
 *   32: " "         space
 *   
 *   33 - 47         Punctuation
 *   
 *   48 - 57         0 to 9
 *   
 *   58 - 64         Punctuation
 *   
 *   65 - 90         A - Z
 *   
 *   91 - 96         Punctuation
 *   
 *   97 - 
 * 
 * 
 * 
 * 
 */


uint8_t output;

uint8_t charRemap(uint8_t input, int direct){            // passed arguments char input & the direction of movement  if passed 1 ++ of 0 --


/*

    charSelect = uint8_t (editString[charNumber]);                           // unsigned int passed char that is saved in editString the currently selected char. I think this needs to be a CAST to int

    Serial.print(charSelect);                                                    // Serial print this int

  //  charSelect = charRemap(charSelect, 1);                                     // int that pertains to a specific char is passed to remap function, along with direction the char needs to move
                                                                               // this function needs to take this int, remap it to our new table, add one or minus one, then translate the int back to
                                                                                // the int that relates to the new char from the table.
   // charSelect++;

   

 //   editString[charNumber] =  char(charSelect);                            // that int is then passed back to editString{charNumber] so this needs to be a cast to a char. 
                                                                            // this can be passed directly it doesnt need to be split into 2 lines
 editString[charNumber] = char(charRemap(charSelect, 1));                        

    Serial.print(editString[charNumber]);                                         // Serialprint the edited char 
    Serial.print(" ");
    Serial.print(" ");
    charUp = false;                                                          // action has been performed, flag can be unset
*/



// int that pertains to a specific char is passed to remap function, along with direction the char needs to move
// this function needs to take this int, remap it to our new table, add one or minus one, then translate the int back to
 // the int that relates to the new char from the table.
 
// Translation to new table        


if (input == 32){                                                  //  Space
 output = 41;
 
} else if (input >= 48 && input <= 57){                                   // 0 - 9                     

output = map(input, 48, 57, 40, 31);
  
  
} else if(input >= 97 && input <= 122){                                // a - z

output = map(input, 97, 122, 42, 67);
  
} else if(input >= 65 && input <= 89){                                 // A - Z       

  output = map(input, 65, 89, 68, 92);
}


sprintf(screenBuffer[2] , "In: %-i Pre: %-i ", input, output);         // prints the int value of the char to the left of the screen, the currently selected char to the right of the screen


if (direct == 0){                                                    // do the maths

  output--;
  
} else if (direct == 1){

output++;
  
}



// Translation back to origional table:



 

if (output == 41){                                                  //  Space
  
 output = 32; 

  } else if (output >= 31 && output <= 40){                                   // 0 - 9                      

output = map(output,  40, 31, 48, 57); 
  

  } else if(output >= 42 && output <= 67){                                // a - z

output = map(output, 42, 67, 97, 122);
  
} else if(output >= 68 && output <= 92){                                 // A - Z       

  output = map(output, 68, 92, 65, 89);
}



sprintf(screenBuffer[2] , " %i ", output);         // prints the int value of the char to the left of the screen, the currently selected char to the right of the screenPost:%i Out: %i  




// Input

/*
 * Maths  char    OLED side
 *        
 * 0       }
 * 1       £
 * 2       {
 * 3       `
 * 4       _
 * 5       ^
 * 6       ]
 * 7       \
 * 8       [          
 * 9       @          64
 * 10       ?         63
 * 11       >         62
 * 12       =         61
 * 13       <         60
 * 14       ;         59
 * 15       :         58
 * 16       /
 * 17       . 
 * 18       -
 * 19       ,
 * 20       +
 * 21       *
 * 22       )
 * 23       (
 * 24       '
 * 25       &
 * 26       %
 * 27       $
 * 28       #
 * 29       "
 * 30       !       
 * 31       9         57
 * 32       8         56
 * 33       7         55
 * 34       6         54
 * 35       5         53
 * 36       4         52
 * 37       3         51
 * 38       2         50
 * 39       1         49 
 * 40       0         48 
 * 41       Space     32
 * 42       a         97  
 * 43       b         98
 * 44       c         99
 * 45       d         100
 * 46       e         101 
 * 47       f         102
 * 48       g         103
 * 49       h         104
 * 50       i         105
 * 51       j         106 
 * 52       k         107
 * 53       l         108
 * 54       m         109
 * 55       n         110
 * 56       o         111
 * 57       p         112
 * 58       q         113
 * 59       r         114
 * 60       s         115
 * 61       t         116
 * 62       u         117
 * 63       v         118
 * 64       w         119
 * 65       x         120
 * 66       y         121
 * 67       z         122
 * 68       A         65
 * 69       B         66
 * 70       C         67  
 * 71       D         68
 * 72       E         69
 * 73       F         70
 * 74       G         71
 * 75       H         72
 * 76       I         73
 * 77       J         74
 * 78       K         75  
 * 79       L         76
 * 80       M         77
 * 81       N         78
 * 82       O         79
 * 83       P         80
 * 84       Q         81
 * 85       R         82  
 * 86       S         83
 * 87       T         84
 * 88       U         85
 * 89       V         86
 * 90       W         87
 * 91       X         88
 * 92       Y         89  
 * 93       Z         90
 * 94
 * 95
 * 96
 * 97
 * 98
 * 99
 * 100
 * 
  */





  return output;
 }
