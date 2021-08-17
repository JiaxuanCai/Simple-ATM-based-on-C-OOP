/*
 * readcard.h
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */

#ifndef READCARD_H_
#define READCARD_H_
#include<fstream>
#include<string>
#include"account_basic.h"
#include"account_credit.h"
#include"account_deposit.h"
class readcard
{
private:

public:

	void readbasic(string number,basic& basicaccount0);//read the basic information of an account
	void readcredit(credit& creditaccount0,  basic basicaccount0);//read the full information of an credit account
	void readdeposit(deposit& depositaccount0,  basic basicaccount0);//read the full information of an deposit account
};



#endif /* READCARD_H_ */
