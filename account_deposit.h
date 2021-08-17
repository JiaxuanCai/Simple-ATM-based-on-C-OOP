/*
 * account_deposit.h
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */

#ifndef ACCOUNT_DEPOSIT_H_
#define ACCOUNT_DEPOSIT_H_

#include"account_basic.h"

class deposit: public basic //deposit card data type, inhareted from the basic class
{
private:
	double balance;//the balance
public://get and set methods
	double getbalance(){
		return balance;
	}
	void setbalance(double balances){
		balance=balances;
	}
};



#endif /* ACCOUNT_DEPOSIT_H_ */
