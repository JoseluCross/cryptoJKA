#include "data.h"

/**
 *Title: randomBet
 *Description: Generation of random number between two numbers
 *@param max: max value
 *@param min: min value
 *@return: número aleatorio
 */
int randomBet(int min, int max) {
  return (rand() % (max - min)) + min;
}

/*
 *Title: ranSpace
 *Description: change space for other character
 *@return num: new character
 */
unsigned char ranSpace(){
  int i;
  unsigned char num;
  i = randomBet(1,5);
  switch(i){
    case 1:
    	num = 32;
    break;
    case 2:
    	num = 126;
    break;
    case 3:
    	num = 46;
    break;
    case 4:
    	num = 45;
    break;
    case 5:
    	num = 95;
    break;
  }
  return num;
}
//Clean buffer
int clean_stdin() {
  while(getchar() != '\n') ;
  return 1;
}
