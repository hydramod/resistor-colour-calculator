#include <stdio.h>
#include <stdlib.h>

//calculates and ouputs resister band colour for multiplier
void multiplierColour(int resistValue){

  if (resistValue%1000000000 == 0){
    printf("White ");
  }else if (resistValue%100000000 == 0){
    printf("Grey ");
  }else if ((resistValue%10000000 == 0) && (resistValue>=100000000) && (resistValue<1000000000)){
    printf("Violet ");
  }else if ((resistValue%1000000 == 0) && (resistValue>=10000000) && (resistValue<100000000)){
    printf("Blue ");
  }else if ((resistValue%100000 == 0) && (resistValue>=1000000) && (resistValue<10000000)){
    printf("Green ");
  }else if ((resistValue%10000 == 0) && (resistValue>=100000) && (resistValue<1000000)){
    printf("Yellow ");
  }else if ((resistValue%1000 == 0) && (resistValue>=10000) && (resistValue<100000)){
    printf("Orange ");
  }else if ((resistValue%100 == 0) && (resistValue>=1000) && (resistValue<10000)){
    printf("Red ");
  }else if ((resistValue%10 == 0) && (resistValue>=100) && (resistValue<1000)){
    printf("Brown ");
  }else if ((resistValue%1 == 0) && (resistValue>=1) && (resistValue<100)){
    printf("Black ");
  }

}

//calculates and returns remainainder value of resistor input value, when zeros are removed
int resistValueRemainder(int resistValue){
  int NewResistValue;

    if (resistValue%1000000000 == 0){
      NewResistValue = resistValue/1000000000;
    }else if (resistValue%100000000 == 0){
      NewResistValue = resistValue/1000000000;
    }else if ((resistValue%10000000 == 0) && (resistValue>=100000000) && (resistValue<1000000000)){
      NewResistValue = resistValue/10000000;
    }else if ((resistValue%1000000 == 0) && (resistValue>=10000000) && (resistValue<100000000)){
      NewResistValue = resistValue/1000000;
    }else if ((resistValue%100000 == 0) && (resistValue>=1000000) && (resistValue<10000000)){
      NewResistValue = resistValue/100000;
    }else if ((resistValue%10000 == 0) && (resistValue>=100000) && (resistValue<1000000)){
      NewResistValue = resistValue/10000;
    }else if ((resistValue%1000 == 0) && (resistValue>=10000) && (resistValue<100000)){
      NewResistValue = resistValue/1000;
    }else if ((resistValue%100 == 0) && (resistValue>=1000) && (resistValue<10000)){
      NewResistValue = resistValue/100;
    }else if ((resistValue%10 == 0) && (resistValue>=100) && (resistValue<1000)){
      NewResistValue = resistValue/10;
    }else if ((resistValue%1 == 0) && (resistValue>=1) && (resistValue<100)){
      NewResistValue = resistValue/1;
    }

    return NewResistValue;

  }

//output colours for Band 1, 2 and 3
void bandColour(int NewResistValue){
  int i;
  int j;
  int digit;
  int *resistValueArray;

  //Dynamic memory allocation for array size
  resistValueArray = (int*)malloc(sizeof(NewResistValue));

  i = 0;

  //converts integer to an array in reverse
  while (NewResistValue!=0){
    digit = NewResistValue%10;
    resistValueArray[i] = digit;
    i++;
    NewResistValue = NewResistValue/10;
  }

  //takes reversed array and corrects it, then out puts band colour, according to
  //Integer at the current index of array
    for(j=i-1; j>-1; j--){
      switch (resistValueArray[j]) {
        case 1:
        printf("Brown ");
        break;
        case 2:
        printf("Red ");
        break;
        case 3:
        printf("Orange ");
        break;
        case 4:
        printf("Yellow ");
        break;
        case 5:
        printf("Green ");
        break;
        case 6:
        printf("Blue ");
        break;
        case 7:
        printf("Violet ");
        break;
        case 8:
        printf("Grey ");
        break;
        case 9:
        printf("White ");
        break;
        case 0:
        printf("Black ");
        break;
        default:
        printf("No Colour Found ");
        break;
      }
    }
}

int main(void) {
  int resistValue;
  int NewResistValue;

  printf("Type in your the Resistor Value\n");
  scanf("%d", &resistValue); //takes in user resistor value

  printf("\nThe Colour bands for a %d ohm Resistor are as follows\n\n", resistValue);

  NewResistValue=resistValueRemainder(resistValue); //assigne new resistor to new variable
  bandColour(NewResistValue); //pass new value to band colour
  multiplierColour(resistValue); //pass user input value to get multiplier colour


  return 0;
}
