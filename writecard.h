/*
 * writecard.h
 *
 *  Created on: 2019Äê5ÔÂ10ÈÕ
 *      Author: CJX
 */

#ifndef WRITECARD_H_
#define WRITECARD_H_
#include<fstream>
#include<string>
#include"account_basic.h"
#include"account_credit.h"
#include"account_deposit.h"
class writecard
{
private:

public:

	void writecredit(credit& creditaccount0);//write the full informaiton of a credit account into the file
	void writedeposit(deposit& depositaccount0);//write the full information of a deposit account into the file
};

#endif /* WRITECARD_H_ */
