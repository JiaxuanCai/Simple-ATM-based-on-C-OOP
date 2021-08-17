/*
 * operation.cpp
 *
 *  Created on: 2019年5月10日
 *      Author: CJX
 */
#include<iostream>
#include<string>
using namespace std;
#include"operation.h"


void operation::deposit_query(deposit depositaccount0)//query
{
	cout<<"Your card type is deposit card"<<endl;
	cout<<"The current balance is "<<depositaccount0.getbalance()<<endl;
}

void operation::credit_query(credit creditaccount0)//query
{
	cout<<"Your card type is credit card"<<endl;
	cout<<"The current line is "<<creditaccount0.getline()<<endl;
	cout<<"The current debt is "<<creditaccount0.getdebt()<<endl;
}

int operation::deposit_withdraw(deposit& depositaccount0)//withdraw money
{
	cout<<"Please input the number you want to withdraw"<<endl<<"This number must be a multiple of 100 and you can't withdraw more than your balance"<<endl;
	int number;
	while(1){//make sure input right
		cin>>number;
		if(number%100!=0)
			cout<<"Wrong input, please try again."<<endl;
		else if (number>300000){
			cout<<"Too much money! Beyond the limit!"<<endl;
		}
		else
		{
			if(depositaccount0.getbalance()-number<0)
				cout<<"Balance insufficient, please try again."<<endl;//if the sufficient balance , print error
			else{
				cout<<"Successfully withdraw! Please take your money!!"<<endl;
				double temp=depositaccount0.getbalance();
				depositaccount0.setbalance(temp-number);
				break;
			}
		}
	}
	return number;
}

int operation::credit_withdraw(credit& creditaccount0)//withdraw money
{
	cout<<"Please input the number you want to withdraw"<<endl<<"This number must be a multiple of 100 and you can't debt more than your line"<<endl;
	int number;
	while(1){//make sure input right
		cin>>number;
		if(number%100!=0)
			cout<<"Wrong input, please try again."<<endl;
		else if (number>300000){
			cout<<"Too much money! Beyond the limit!"<<endl;
		}
		else{
			if(creditaccount0.getdebt()+number>creditaccount0.getline())
				cout<<"Debt is more than the line! Please try again."<<endl;
			else{//if not enough line, print the error
				cout<<"Successfully withdraw! Please take your money!!"<<endl;
				double temp=creditaccount0.getdebt();
				creditaccount0.setdebt(temp+number);
				break;
			}
		}
	}
	return number;
}

void operation::deposit_changepassword(deposit& depositaccount0)//change password
{
	cout<<"Please input the new password"<<endl;
	string word;
	string word2;
	while(1){
		while(1){
			cin>>word;//double check!!!!
			if(word.size()!=6)
				cout<<"Wrong input, please try again"<<endl;
			else
				break;
		}
		while(1){
			cout<<"Please input again to confirm"<<endl;
			cin>>word2;
			if(word2.size()!=6)
				cout<<"Wrong input, please try again"<<endl;//make sure the double check is the same
			else
				break;
		}
		if(word!=word2)
			cout<<"Words are not the same, please try again"<<endl;
		else{
			depositaccount0.setpassword(word);
			cout<<"Password changed successfully!"<<endl;
			break;
		}
	}
	string t1="改密码为";//add the record
	string t=t1+word;
	depositaccount0.setrecord(t);
}

void operation::credit_changepassword(credit& creditaccount0)//change password
{
	cout<<"Please input the new password"<<endl;
	string word;
	string word2;
	while(1){//double check!!!!
		while(1){
			cin>>word;
			if(word.size()!=6)
				cout<<"Wrong input, please try again"<<endl;
			else
				break;
		}
		while(1){
			cout<<"Please input again to confirm"<<endl;
			cin>>word2;//make sure the double check is the same
			if(word2.size()!=6)
				cout<<"Wrong input, please try again"<<endl;
			else
				break;
		}
		if(word!=word2)
			cout<<"Words are not the same, please try again"<<endl;
		else{
			creditaccount0.setpassword(word);
			cout<<"Password changed successfully!"<<endl;
			break;
		}
	}
	string t1="改密码为";//add the record
	string t=t1+word;
	creditaccount0.setrecord(t);
}

void operation::deposit_to_deposit(deposit& d1account, deposit& d2account)//transfer money from a deposit account to a deposit account
{
	double number;
	while(1){
		cout<<"Please input the number"<<endl;
		cin>>number;
		if(d1account.getbalance()-number<0)//make sure sufficient balance
			cout<<"Balance insufficient, please try again"<<endl;
		else{
			double temp1=d1account.getbalance();
			double temp2=d2account.getbalance();
			d1account.setbalance(temp1-number);
			d2account.setbalance(temp2+number);
			cout<<"Money transferred successfully!"<<endl;
			break;
		}
	}
	string s1="转账";
	string s2=to_string(number);//add the record!!!!!!
	string s3="元";
	string s4="给";
	string s5=d2account.getuserName();
	string s6="，目标卡号为";
	string s7=d2account.getcardNumber();
	string s8="，操作后余额为";
	string s9=to_string(d1account.getbalance());
	string s10="元。";
	string s=s1+s2+s3+s4+s5+s6+s7+s8+s9+s10;
	d1account.setrecord(s);

	string s1a="接受来自";
	string s2a=d1account.getuserName();
	string s3a="，来源卡号为";//add the record!!!!!!!!
	string s4a=d1account.getcardNumber();
	string s5a="的转账";
	string s6a=to_string(number);
	string s7a="元";
	string s8a="，操作后余额为";
	string s9a=to_string(d2account.getbalance());
	string s10a="元。";
	string sa=s1a+s2a+s3a+s4a+s5a+s6a+s7a+s8a+s9a+s10a;
	d2account.setrecord(sa);
}

void operation::deposit_to_credit(deposit& depositaccount0, credit& creditaccount0)//transfer money from a deposit account to a credit account
{
	double number;
	while(1){
		cout<<"Please input the number"<<endl;
		cin>>number;
		if(depositaccount0.getbalance()-number<0)
			cout<<"Balance insufficient, please try again"<<endl;//make sure the balance is sufficient
		else{
			double temp1=depositaccount0.getbalance();
			double temp2=creditaccount0.getdebt();
			depositaccount0.setbalance(temp1-number);
			creditaccount0.setdebt(temp2-number);
			cout<<"Money transferred successfully!"<<endl;
			break;
		}
	}
	string s1="转账";//add record!!!!!!!!!
	string s2=to_string(number);
	string s3="元";
	string s4="给";
	string s5=creditaccount0.getuserName();
	string s6="，目标卡号为";
	string s7=creditaccount0.getcardNumber();
	string s8="，操作后余额为";
	string s9=to_string(depositaccount0.getbalance());
	string s10="元。";
	string s=s1+s2+s3+s4+s5+s6+s7+s8+s9+s10;
	depositaccount0.setrecord(s);

	string s1a="接受来自";//add record
	string s2a=depositaccount0.getuserName();
	string s3a="，来源卡号为";
	string s4a=depositaccount0.getcardNumber();
	string s5a="的转账";
	string s6a=to_string(number);
	string s7a="元";
	string s8a="，操作后欠款为";
	string s9a=to_string(creditaccount0.getdebt());
	string s10a="元。";
	string sa=s1a+s2a+s3a+s4a+s5a+s6a+s7a+s8a+s9a+s10a;
	creditaccount0.setrecord(sa);
}
