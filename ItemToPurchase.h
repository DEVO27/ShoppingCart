#ifndef ITEM_TO_PURCHASE
#define ITEM_TO_PURCHASE
#define MAX 50

typedef struct ItemToPurchase{
	char itemName[MAX];
	int itemPrice;
	int itemQuantity;
	char itemDescription[MAX];
}ItemToPurchase;

void MakeItemBlank(ItemToPurchase *item);

//int PrintItemCost(ItemToPurchase item);

#endif //ITEM_TO_PURCHASE