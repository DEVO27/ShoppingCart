#ifndef SHOPPING_CART
#define SHOPPING_CART
#include "ItemToPurchase.h"
#define MAX 50


typedef struct ShoppingCart{
	char customerName[MAX];
	char currentDate[MAX];
	ItemToPurchase cartItems[10];
	int cartSize;
}ShoppingCart;


/*** PrintMenu Function ***/
void PrintMenu(ShoppingCart cart);

/*** AddItem Function ***/
ShoppingCart AddItem(ItemToPurchase, ShoppingCart);

/*** RemoveItem Function ***/
ShoppingCart RemoveItem(char[], ShoppingCart);

/*** ModifyItem Function ***/
ShoppingCart ModifyItem(ItemToPurchase, ShoppingCart);

/*** GetNumItemsInCart Function ***/
int GetNumItemsInCart(ShoppingCart);

/*** GetCostOfCart Function ***/
int GetCostOfCart(ShoppingCart);

/*** PrintTotal Function ***/
void PrintTotal(ShoppingCart);

/*** PrintDescriptions Function ***/
void PrintDescriptions(ShoppingCart);


#endif //SHOPPING_CART