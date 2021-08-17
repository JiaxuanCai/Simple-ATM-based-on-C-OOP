/*
 * controller.cpp
 *
 *  Created on: 2019年5月7日
 *      Author: CJX
 */

#include<iostream>
#include<string>
#include"controller.h"
#include"readcard.h"
#include"writecard.h"
#include"operation.h"

int controller::main_controller()//the main controller
{
	controller::insert_card();
	controller::get_account();
	if(basic_account.getcardType()==1){ //make sure input right
		int r=controller::confirmc();
		if(r==0){
			controller::set_account1();
			return 0;
		}
		else
			cout<<"Card inserted successfully! Please choose your operations."<<endl;
	}
	if(basic_account.getcardType()==2){ //make sure input right
		int r=controller::confirmp();
		if(r==0){
			controller::set_account1();
			return 0;
		}
		else
			cout<<"Card inserted successfully! Please choose your operations."<<endl;
	}
	/*cout<<"详细信息"<<endl;
	cout<<deposit_account.getcardType()<<endl;
	cout<<deposit_account.getcondition()<<endl;
	cout<<deposit_account.getattempt()<<endl;
	cout<<deposit_account.getcardNumber()<<endl;
	cout<<deposit_account.getuserName()<<endl;
	cout<<deposit_account.getidNumber()<<endl;
	cout<<deposit_account.getpassword()<<endl;
	cout<<deposit_account.getbalance()<<endl;*/
	controller::operate();
	controller::set_account1();
	controller::set_account2();
	controller::return_card();
	return 1;
}


void controller::insert_card()//let the user insert card
{
	string accountnumber;
	cout<<"Please input the account number"<<endl;
	while(1){//make sure input right
		cin>>accountnumber;
		if(accountnumber.size()!=19)
			cout<<"Wrong input, please try again."<<endl;
		else
			break;
	}
	readcard basicreader;
	basicreader.readbasic(accountnumber,basic_account);
	/*cout<<"基础信息"<<endl;
	cout<<basic_account.getcardType()<<endl;
	cout<<basic_account.getcondition()<<endl;
	cout<<basic_account.getattempt()<<endl;
	cout<<basic_account.getcardNumber()<<endl;
	cout<<basic_account.getuserName()<<endl;
	cout<<basic_account.getidNumber()<<endl;
	cout<<basic_account.getpassword()<<endl;*/

}


int controller::confirmc()//confirm the password
{
	if(credit_account.getcondition()==0) //know the card condition
		{
			cout<<"Your card has been locked, please contact us!"<<endl;
			return 0;
		}
	while(1){//make sure an account can be no more than 3 attempts
		cout<<"Please input the password, if you give more than 3 attempts in total, your card will be locked."<<endl;
		string password;
		cin>>password;
		if(credit_account.getattempt()>=2)
		{
			cout<<"Due to too many attempts, your card will be locked, please contact us!"<<endl;
			credit_account.setcondition(0);
			return 0;
		}
		if(password!=credit_account.getpassword()){
			int temp=credit_account.getattempt();
			credit_account.setattempt(temp+1);
			if(credit_account.getattempt()<=2)
				cout<<"Wrong password, please try again!"<<endl;
		}
		if(password==credit_account.getpassword())
		{
			credit_account.setattempt(0);
			return 1;
		}
	}
}

int controller::confirmp()// confirm the passwords
{
	if(deposit_account.getcondition()==0)//know the card condition
	{
		cout<<"Your card has been locked, please contact us!"<<endl;
		return 0;
	}
	while(1){//make sure an account can be no more than 3 attempts
		cout<<"Please input the password, if you give more than 3 attempts in total, your card will be locked."<<endl;
		string password;
		cin>>password;
		if(deposit_account.getattempt()>=2)
		{
			cout<<"Due to too many attempts, your card will be locked, please contact us!"<<endl;
			deposit_account.setcondition(0);
			return 0;
		}
		if(password!=deposit_account.getpassword()){
			int temp=deposit_account.getattempt();
			deposit_account.setattempt(temp+1);
			if(deposit_account.getattempt()<=2)
				cout<<"Wrong password, please try again!"<<endl;
		}
		if(password==deposit_account.getpassword())
		{
			deposit_account.setattempt(0);
			return 1;
		}
	}
}


void controller::get_account()// read the full account information
{
	readcard detailreader;
	if(basic_account.getcardType()==1){//panduan card type and invoke the related function
		detailreader.readcredit(credit_account,basic_account);
	}
	else if(basic_account.getcardType()==2){
		detailreader.readdeposit(deposit_account,basic_account);
	}
}


void controller::operate()//operate the data
{
	cout<<"-------------------------------------"<<endl;
	cout<<"-------Please choose operation-------"<<endl;
	cout<<"1.Query account     2.Withdraw money"<<endl;
	cout<<"3.Change password   4.transfer money"<<endl;   //print the interface to hudong with the users
	cout<<"5.return your card"<<endl;
	cout<<"-------------------------------------"<<endl;
	int mode;
	operation operation;
	while(1){//query card
		cin>>mode;
		if(mode==1){
			if(basic_account.getcardType()==1)
				operation.credit_query(credit_account);
			else if(basic_account.getcardType()==2)
				operation.deposit_query(deposit_account);
		}
		else if(mode==2){//withdraw money
			if(basic_account.getcardType()==1){
				int r=operation.credit_withdraw(credit_account);
				string t1="取款";//add the record
				string t2="元";
				string t=t1+to_string(r)+t2;
				credit_account.setrecord(t);
			}
			else if(basic_account.getcardType()==2){
				int r=operation.deposit_withdraw(deposit_account);
				string t1="取款";//add the record
				string t2="元";
				string t=t1+to_string(r)+t2;
				deposit_account.setrecord(t);
			}
		}
		else if(mode==3){//change password
			if(basic_account.getcardType()==1){
				operation.credit_changepassword(credit_account);
			}
			else if(basic_account.getcardType()==2){
				operation.deposit_changepassword(deposit_account);
			}
		}
		else if(mode==4){//transfer money
			if(basic_account.getcardType()==1)
				cout<<"Your card is credit card, you cann't transfer money!"<<endl;//credit card can't transfer money
			else if(basic_account.getcardType()==2){
				cout<<"Please input the card number"<<endl;
				string cardnumber;
				while(1){
					cin>>cardnumber;
					if(cardnumber.size()!=19)
						cout<<"Wrong input, please try again."<<endl;
					else
						break;
				}
				readcard basicreader;
				basicreader.readbasic(cardnumber,basic_account2);
				readcard detailreader;
				if(basic_account2.getcardType()==1){
					detailreader.readcredit(credit_account2,basic_account2);
					operation.deposit_to_credit(deposit_account,credit_account2);
				}
				else if(basic_account2.getcardType()==2){
					detailreader.readdeposit(deposit_account2,basic_account2);
					operation.deposit_to_deposit(deposit_account,deposit_account2);
				}
			}
		}
		else if(mode==5){//return
			break;
		}
	}
}


void controller::set_account1()//set the account
{
	writecard cardwriter;
	if(basic_account.getcardType()==1)
	{
		cardwriter.writecredit(credit_account);
	}
	else if (basic_account.getcardType()==2)
	{
		cardwriter.writedeposit(deposit_account);
	}
}

void controller::set_account2()//set the account
{
	writecard cardwriter;
	if(basic_account2.getcardType()==1)
	{
		cardwriter.writecredit(credit_account2);
	}
	else if (basic_account2.getcardType()==2)
	{
		cardwriter.writedeposit(deposit_account2);
	}
}

void controller::return_card()//return the card to user
{
	cout<<"Card successfully returned, thank you for your using my ATM!";
}
