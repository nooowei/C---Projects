/*
- A program that gets user input on their patio size, and help them determine the pieces of curb and paver tiles needed to construct the patio
- as well as the total price that will cost the user.

- getDimension() function gets user input for dimensions of the Patio
- totalPieces() function determines the total number of tiles needed
- totalprice() function calculates the price for the entire project.

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float width;
float length;

int curbNum;
int paverNum;
float curbLength = 11.8;
float curbWidth = 4.3;
float paverLW = 7.75;

float curbPrice = 2.48;
float paverPrice = 3.9;
float hst = 0.13;
float subTotal;
float tax;
float total;

void getDimension();
void totalPieces(float, float);
void totalPrice(int, int);

int main(){
  getDimension();
  totalPieces(width, length);
  totalPrice(paverNum, curbNum);

  return(0);
}

void getDimension(){
  // getting user input for patio width in ft
  printf("What's the width of your Patio in ft? \n");
  scanf("%2f", &width);
  while(getchar() != '\n');

  // getting user input for patio length in ft
  printf("What's the length of your Patio in ft? \n");
  scanf("%2f", &length);
  while(getchar() != '\n');

  //converting dimension from ft to in
  width *= 12;
  length *= 12;
  if (width < 24 || length < 24){
    printf("Patio is too small!\n");
    exit(1);
  }
}




void totalPieces(float a, float b){
  int curbTB;
  int curbLR;
  int paverV;
  int paverH;

  // use ceil division to get the rounded up number of curbs needed
  curbTB = ceil(b / curbLength) * 2;
  curbLR = ceil((a - curbWidth * 2) / curbLength) * 2;
  curbNum = curbTB + curbLR;
  printf("Total number of curb needed is %d pieces. \n", curbNum);

  // use ceil division to get the rounded up number of paver needed
  paverV = ceil((a - curbWidth * 2) / paverLW);
  paverH = ceil((b - curbWidth * 2) / paverLW);
  paverNum = paverV * paverH;
  printf("Total number of paver needed is %d pieces. \n", paverNum);
}


void totalPrice(int x, int y){
  // calculating the price with given numbers of total piece needed
  subTotal = x * paverPrice + y * curbPrice;
  tax = subTotal * hst;
  total = subTotal + tax;

  printf("Your total tax for the purchase is $%.2f. \n", tax);
  printf("Your total cost for the purchase is $%.2f. \n", total);
}
