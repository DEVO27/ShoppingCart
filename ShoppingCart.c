#include "ShoppingCart.h" 
#include <string.h>
#include <stdio.h>

/*** PrintMenu Function ***/
void PrintMenu(ShoppingCart cart){
    printf("\nMENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n\n");
    
}

/*** AddItem Function ***/
ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
  /*** Prompt User ***/
  printf("ADD ITEM TO CART\n");
  printf("Enter the item name:\n");
  
  /*** Item Name input ***/
  fgets(item.itemName, MAX, stdin);
  item.itemName[strlen(item.itemName) - 1] = 0;

  /*** Item description input ***/
  printf("Enter the item description:\n");
 // scanf("%s", item.itemName);
  fgets(item.itemDescription, 50, stdin);
  item.itemDescription[strcspn(item.itemDescription, "\n")] = 0;

  /** Item price input ***/
  printf("Enter the item price:\n");
  scanf(" %d", &item.itemPrice);
  
  /** Item quantity input ***/
  printf("Enter the item quantity:\n");
  scanf(" %d", &item.itemQuantity);

  /*** Copy elements ***/
   strcpy(cart.cartItems[cart.cartSize].itemName, item.itemName);
  strcpy(cart.cartItems[cart.cartSize].itemDescription, item.itemDescription);
  cart.cartItems[cart.cartSize].itemPrice = item.itemPrice;
  cart.cartItems[cart.cartSize].itemQuantity = item.itemQuantity;

  //Increment the size of the cart
  ++cart.cartSize;
  return cart;
}


/*** RemoveItem Function ***/
ShoppingCart RemoveItem(char name[], ShoppingCart cart){
int i;

char itemFound = 'n';

/*** Prompt ***/
printf("REMOVE ITEM FROM CART\n");
printf("Enter name of item to remove:\n");
fgets(name,MAX,stdin);
name[strlen(name) - 1] = 0;

for(i = 0; i < cart.cartSize; i++){
 if (strcmp(name, cart.cartItems[i].itemName) == 0) {
     itemFound = 'y';
     for (int j = i; j < cart.cartSize; ++j) {
       cart.cartItems[j] = cart.cartItems[j + 1];
     }
   }
 }
 if (itemFound == 'y') {
   cart.cartSize = cart.cartSize - 1;
 }
  if (itemFound == 'n') {
   printf("Item not found in cart. Nothing removed.\n");
 }

 return cart;
}


/*** ModifyItem Function ***/
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart){
  int i;
  
   printf("CHANGE ITEM QUANTITY\n");
   printf("Enter the item name:\n");
   fgets(item.itemName,MAX,stdin);
   item.itemName[strlen(item.itemName) - 1] = 0;
   printf("Enter the new quantity:\n");
   scanf("%d", &item.itemQuantity);

  for(i = 0; i < cart.cartSize; i++){
     if(strcmp(item.itemName, cart.cartItems[i].itemName) != 0){
       printf("Item not found in cart. Nothing modified.\n");
       break;
     }
     else if(strcmp(item.itemName, cart.cartItems[i].itemName) == 0){
        cart.cartItems[i].itemQuantity = item.itemQuantity;
  }
 }
 return cart;
}
 

/*** GetNumItemsInCart Function ***/
int GetNumItemsInCart(ShoppingCart cart){
 int i;
 int count = 0;
 for(i = 0; i <cart.cartSize; i++){
   count += cart.cartItems[i].itemQuantity;
 }
  return count; 
}

/*** GetCostOfCart Function ***/
int GetCostOfCart(ShoppingCart cart){
  int i;
  int count = 0;
  for(i = 0; i < cart.cartSize; i++){
    count = count + cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
  }
  printf("Total: $%d\n", count);
  return count;
}

/*** PrintTotal Function ***/
void PrintTotal(ShoppingCart cart){
  int i;
  if(cart.cartSize == 0){
    printf("OUTPUT SHOPPING CART\n");
    printf("%s\'s Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
    printf("SHOPPING CART IS EMPTY\n\n");
    GetCostOfCart(cart);
  }
  else if(cart.cartSize != 0){
      printf("OUTPUT SHOPPING CART\n");
      printf("%s\'s Shopping Cart - %s\n", cart.customerName, cart.currentDate);
      printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
    
      for(i = 0; i < cart.cartSize; i++){
      printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity, cart.cartItems[i].itemPrice, (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice));
      }
     printf("\n");
     
     GetCostOfCart(cart);
    }
}

/*** PrintDescriptions Function ***/
void PrintDescriptions(ShoppingCart cart){
  int i;
  printf("OUTPUT ITEMS\' DESCRIPTIONS\n");
  printf("%s\'s Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
  printf("Item Descriptions\n");
  for(i = 0; i < cart.cartSize; i++){
    printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
  }
}