#include <stdio.h>
#include "ItemToPurchase.h"
#include <string.h>


void MakeItemBlank(ItemToPurchase *item){
	strcpy(item->itemName, "none");
	item->itemPrice = 0;
	item->itemQuantity = 0;
	strcpy(item->itemDescription, "none");
}

int PrintItemCost(ItemToPurchase item){

	return ((item.itemPrice) * (item.itemQuantity));	
}