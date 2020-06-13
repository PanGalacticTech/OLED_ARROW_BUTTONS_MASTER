
 /*   Functions to Help with Managing Strings
  * 
  * 
  * 
  * 
  */









char input[45] = {"example.net                    "};




void removeTrailingSpaces(){                                                        // Function to remove the trailing spaces from a char array string



 char * p = strchr (input, ' ');                    // search for space
 
 if (p)  {   // if found truncate at space
   *p = 0;
 }
  
 Serial.print ("<");
 Serial.print (input);
 Serial.println (">");

}

// output = "example.net"
