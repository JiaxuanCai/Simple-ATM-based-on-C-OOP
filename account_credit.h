/*
 * account_credit.h
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */

#ifndef ACCOUNT_CREDIT_H_
#define ACCOUNT_CREDIT_H_
#include"account_basic.h"

class credit: public basic //credit card data type, inhareted from the basic class
{
private:
	double line;//the line
	double debt;//the debt right now
public://get and set methods
	double getline(){
		return line;
	}
	double getdebt(){
		return debt;
	}
	void setline(double lines){
		line=lines;
	}
	void setdebt(double debts){
		debt=debts;
	}
};



#endif /* ACCOUNT_CREDIT_H_ */
