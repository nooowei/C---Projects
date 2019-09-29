/*
- A simple card game that asks player for 4 cards (i.e., 2H, 3D, 5C), and determind the best cards.
- the game will ask player to input a "Trump Suit", which will overpower the other suits, if one of the card contains said suit.
- if no cards contain the trump suit, the first card's suit becomes the dominant suit, called "Suit Led".

- getCards() function asks player for 4 valid inputs, and will enter a infinite loop until 4 valid inputs are given.
- getTrump() function asks player for the Trump suit
- isValidRank() function checks the input for valid Rank
- isValidSuit() function checks the pinput for valid suit

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rank[13] = {'2', '3','4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char suit[4] = {'H', 'D', 'S', 'C'};
char trump;
//multilayer array to store players and their cards
//access string as an char array
char players[4][3];
char suitLed;
//pointer pointing to the beginning of the players array
char *ptr = &players[0][0];
//preset the best card to the first player's hand
char *theBestCard = players[0];

void getCards();
int isValidRank(char);
int isValidSuit(char);
void getTrump();
void bestCard(char[][3]);

void main(){
  getTrump();
  getCards();
  bestCard(players);
  printf("\nThe best card out of 4 is: %s.\n", theBestCard);
}

void getCards(){
  int count = 0;
  //infinite loop until players enter 4 valid cards
  while (count < 4){
    printf("\n Player %d: Enter card Rank and suit (e.g., 2S, TC, KD). \n", count);
    scanf("%s", players[count]);
    while(getchar() != '\n');

    // validating input length, Suit and Rank
    if (strlen(players[count]) == 2 && isValidRank(*(ptr + count*3)) == 1 && isValidSuit(*(ptr + count*3 + 1)) == 1){
      count ++;
    }
    // for TA to exit the program
    else if (*players[count] == '.'){
      exit(1);
    }
    // invalid entry warning
    else{
      printf("\n Invalid card, please re-enter. \n");
    }
  }

  suitLed = players[0][1];
  //print out players' cards.
  for (int a = 0; a < 4; a++){
    printf("%s ,", players[a]);
  }
}

int isValidRank(char c){
  for(int i = 0; i < 13; i++){
    //checking the user input against the rank array
    if(c == rank[i]){
      return 1;
      break;
    }
  }
  return 0;
}

int isValidSuit(char c){
  for(int j = 0; j < 4; j++){
    //checking the user input against the suit array
    if(c == suit[j]){
      return 1;
      break;
    }
  }
  return 0;
}

void getTrump(){
  printf("\n Please select a trump suit: \n");
  scanf("%s", &trump);
  while(getchar() != '\n');
  //use recursion to repeat prompt until user enters valid input
  if (isValidSuit(trump) == 0){
    printf("Invalid entry, try again. \n");
    getTrump();
    // break;
  }
}


void bestCard(char p[][3]){
  int bestRank = -1;
  int playerRank;

  //iterate over provided players array
  for (int i = 0; i < 4; i++){
    // if any of the players picked the suit led when there is no trump suit in game
    if(*(ptr + i*3 + 1) == suitLed && *(ptr + 4) != trump && *(ptr + 7) != trump && *(ptr + 10) != trump){
      for (int d = 0; d < 13; d++){
        if (*(ptr + i*3) == rank[d]){
          playerRank = d;
          if (playerRank > bestRank){
            bestRank = playerRank;
            theBestCard = p[i];
          }
        }
      }
    }

    // if any of the players picked the trump card
    // use the pointer to get the character in a string
    else if(*(ptr + i*3 + 1) == trump){
      for(int j = 0; j < 13; j++ ){
        if(*(ptr + i*3) == rank[j]){
          playerRank = j;
          if (playerRank > bestRank){
            bestRank = playerRank;
            theBestCard = p[i];
          }
        }
      }
    }
  }
}
