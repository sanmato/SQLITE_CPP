#ifndef SMART_MONEY_BOX_H
#define SMART_MONEY_BOX_H


#ifndef COLLECTIONS_H
    #include "collections.h"
#endif // collections

struct SmartMoneyBox
{
    //AssociativeContainer<Money, Owner> moneyBox;


    void loadTransaction();
    int ownersWhoDeposited();
    int totalCoins();
    double totalAmount();
    void coinDetailsByOwner(AnsiString ownerName);
    double ownerDepositsGreatherThanAmount(double moneyParameter);
    bool ownerMakeADeposit(AnsiString ownerName);
    bool ownerMakeASpecificAmount();
    bool release(double limit);




};


#endif // SMART_MONEY_BOX_H
