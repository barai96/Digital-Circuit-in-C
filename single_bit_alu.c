#include <stdio.h>
#include <stdbool.h>

typedef unsigned char uint8_t;
typedef struct
{
bool out;
bool carry_out;
} sum;
//function prototyping
static inline bool AND(bool B1, bool B2);
static inline bool XOR(bool B1, bool B2);
static inline bool NOR(bool B1, bool B2);
sum one_bit_adder(bool B1, bool B2, bool carry_in);

int main() {
   
  // Input variables decleration
  bool B1 =0;
  bool B2 = 0;
  bool carry_in = 0;
  bool result = 0;
  bool D0 = 0;
  bool D1 = 0;
  sum output = {0,0};


  //declear buffer for user input of data to remove compilation warnings
  uint8_t temp = 0;
  //Take user input for data
  printf("Enter First Bit\n");
  scanf("%hhd",&temp);
  B1 = (bool)temp;
  printf("Enter Second Bit\n");
  scanf("%hhd",&temp);
  B2 = (bool)temp;
  printf("Enter First Data Line (D0)\n");
  scanf("%hhd",&temp);
  D0 = (bool)temp;
  printf("Enter First Data Line (D1)\n");
  scanf("%hhd",&temp);
  D1 = (bool)temp;

  // Perform operation based on input (D1,D0)
  switch ((int)D1<<1 | (int)D0) 
  {
    case 0: // AND
      result = AND(B1,B2);
	  printf("AND Output: %d\n", result);
      break;
    case 1: // XOR
      result = XOR(B1,B2);
	  printf("XOR Output: %d\n", result);
      break;
    case 2: // NOR
      result = NOR(B1,B2);
	  printf("NOR Output: %d\n", result);
      break;
	case 3: // one_bit_adder
      output = one_bit_adder(B1,B2,carry_in);
	  printf("Sum: %d\n", output.out);
      printf("Carry out: %d\n", output.carry_out);
      break;
    default:
      printf("Invalid operation\n");
	  //terminate main
      return 1;
  }
}


static inline bool AND(bool B1, bool B2) {
  // bitwise AND operator for AND gate logic
  return B1 & B2;
}


static inline bool XOR(bool B1, bool B2) {
  //bitwise XOR operator for XOR gate logic
  return B1 ^ B2;
}

static inline bool NOR(bool B1, bool B2) {
  //bitwise operators for NOR gate logic
  return !(B1 | B2);
}

sum one_bit_adder(bool B1, bool B2, bool carry_in) {
  //declear and initiate variable of structure sum
  sum result = {0,0};
  //XOR for sum and bitwise AND for carry out
  result.out = B1 ^ B2;
  result.carry_out = B1 & B2;
  
  //return result structure
  return result;
}
