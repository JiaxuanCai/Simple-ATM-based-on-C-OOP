/*
 * operation.h
 *
 *  Created on: 2019Äê5ÔÂ10ÈÕ
 *      Author: CJX
 */

#ifndef OPERATION_H_
#define OPERATION_H_
#include"account_basic.h"
#include"account_credit.h"
#include"account_deposit.h"
class operation
{
private:

public:

	void deposit_query(deposit depositaccount0);//query
	void credit_query(credit creditaccount0);
	int deposit_withdraw(deposit& depositaccount0);//withdraw money
	int credit_withdraw(credit& creditaccount0);
	void deposit_changepassword(deposit& depositaccount0);//change password
	void credit_changepassword(credit& creditaccount0);
	void deposit_to_deposit(deposit& d1account, deposit& d2account);//transfer money from a deposit account to a deposit account
	void deposit_to_credit(deposit& depositaccount0, credit& creditaccount0);//transfer money from a deposit account to a credit account
};




#endif /* OPERATION_H_ */
