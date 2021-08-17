/*
 * basic_account.h
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */

#ifndef ACCOUNT_BASIC_H_
#define ACCOUNT_BASIC_H_

#include<iostream>
#include <vector>
using namespace std;

class basic//basic data type
{
private:
	string cardNumber;
	string userName;
	string idNumber;
	string password;
	int attempt;
	int condition;
	int cardType;
	vector<string> record;
public://get and set methods
	string getcardNumber(){
		return cardNumber;
	}
	string getuserName(){
		return userName;
	}
	string getidNumber(){
		return idNumber;
	}
	string getpassword(){
		return password;
	}
	int getattempt(){
		return attempt;
	}
	int getcondition(){
		return condition;
	}
	int getcardType(){
		return cardType;
	}
	vector<string> getrecord(){
		return record;
	}
	void setcardNumber(string cardnumber){
		cardNumber=cardnumber;
	}
	void setuserName(string username){
		userName=username;
	}
	void setidNumber(string idnumber){
		idNumber=idnumber;
	}
	void setpassword(string password0){
		password=password0;
	}
	void setattempt(int attempts){
		attempt=attempts;
	}
	void setcondition(int conditions){
		condition=conditions;
	}
	void setcardType(int type){
		cardType=type;
	}
	void setrecord(string line){
		record.push_back(line);
	}
};



#endif /* ACCOUNT_BASIC_H_ */
