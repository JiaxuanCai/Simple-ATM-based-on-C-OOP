/*
 * coontroller.h
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include"account_basic.h"
#include"account_credit.h"
#include"account_deposit.h"
class controller
{
private:
	basic basic_account; //storage of a basic account
	credit credit_account; //storage of a credit account
	deposit deposit_account; //storage of a deposit account
	basic basic_account2; //storage of another basic account
	credit credit_account2; //storage of another credit account
	deposit deposit_account2; //storage of another deposit account

public:
	int main_controller();//the main controller
	void insert_card();//let the user insert card
	int confirmc();// confirm the password
	int confirmp();// confirm the passwords
	void get_account();// read the full account information
	void operate(); //operate the data
	void set_account1(); //set the account
	void set_account2();
	void return_card();//return the card to user
};
#endif /* CONTROLLER_H_ */
