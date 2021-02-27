#include <stdio.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <string.h>

int main(void){
  char input;               //reset for while
  char remove[MAX];         //remove string variable
	ShoppingCart Cart;        //Struct for cart
  ItemToPurchase Item;      //Struct for Item
  Cart.cartSize = 0;        //Sets cartsize to 0     
  char c;                   //Check for new line charaters

	//Items are Blank
	MakeItemBlank(&Item);

  /*** First Prompt ***/
    printf("Enter Customer's Name:\n");
    fgets(Cart.customerName, MAX, stdin);
    Cart.customerName[strcspn(Cart.customerName, "\n")] = 0;
    printf("Enter Today's Date:\n");
    fgets(Cart.currentDate, MAX, stdin);
    Cart.currentDate[strcspn(Cart.currentDate, "\n")] = 0;
    printf("\nCustomer Name: %s\n", Cart.customerName);
    printf("Today's Date: %s\n", Cart.currentDate);


    while(input != 'q'){
       
       /*** Prompt Menu ***/
       PrintMenu(Cart);
       input = ' ';                       //reset code to enter while loop

        /*** Check for wrong input ***/
        while ((input != 'a' && input != 'r') && (input != 'c' && input != 'i') && (input != 'o' && input != 'q')){

          //PROBLEM WITH CODE WITH MUTIPLE INPUTS
          printf("Choose an option:\n");
          scanf(" %c", &input);
        }
        
        /*** Calls AddItem function ***/
        if(input == 'a'){
          while((c= getchar()) != '\n' && c != EOF);
          Cart = AddItem(Item, Cart);
        }
        
        /*** Calls RemoveItem function ***/
        else if(input == 'r'){
           while((c= getchar()) != '\n' && c != EOF);
           Cart = RemoveItem(remove, Cart);
        }
        
        /*** Calls ModifyItem function ***/
        else if(input == 'c'){
         while((c= getchar()) != '\n' && c != EOF);
         Cart = ModifyItem(Item, Cart);
         getchar();
        }
        
        /*** Calls PrintDescriptions function ***/
        else if(input == 'i'){
          while((c= getchar()) != '\n' && c != EOF);
          PrintDescriptions(Cart);
        }

        /*** Calls PrintTotal function ***/
        else if(input == 'o'){
          while((c= getchar()) != '\n' && c != EOF);
          PrintTotal(Cart);
        }
    }

    return 0;
}