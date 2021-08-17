/*
 * writecard.cpp
 *
 *  Created on: 2019年5月10日
 *      Author: CJX
 */

#include<iostream>
using namespace std;
#include"writecard.h"

void writecard::writecredit(credit& creditaccount0)//write the full informaiton of a credit account into the file
{
	ofstream outfile;
	string position="E:\\Cpp projects\\ATM\\data\\";
	string backfix=".txt";
	string w;
	w=position+creditaccount0.getcardNumber()+backfix;
	outfile.open(w,ios::out);
	outfile<<creditaccount0.getcardType()<<"   ";
	outfile<<creditaccount0.getcondition()<<"   ";
	outfile<<creditaccount0.getattempt()<<endl;
	outfile<<"账号     ";
	outfile<<creditaccount0.getcardNumber()<<endl;
	outfile<<"姓名     ";
	outfile<<creditaccount0.getuserName()<<endl;
	outfile<<"身份证   ";
	outfile<<creditaccount0.getidNumber()<<endl;
	outfile<<"密码     ";
	outfile<<creditaccount0.getpassword()<<endl;
	outfile<<"信用额度 ";
	outfile<<creditaccount0.getline()<<endl;
	outfile<<"当前欠款 ";
	outfile<<creditaccount0.getdebt()<<endl;
	outfile<<endl<<"操作记录"<<endl;
	vector<string> t=creditaccount0.getrecord();
	for(string r:t){
		outfile<<r<<endl;
	}
	outfile.close();
}


void writecard::writedeposit(deposit& depositaccount0)//write the full information of a deposit account into the file
{
	ofstream outfile;
	string position="E:\\Cpp projects\\ATM\\data\\";
	string backfix=".txt";
	string w;
	w=position+depositaccount0.getcardNumber()+backfix;
	outfile.open(w,ios::out);
	outfile<<depositaccount0.getcardType()<<"   ";
	outfile<<depositaccount0.getcondition()<<"   ";
	outfile<<depositaccount0.getattempt()<<endl;
	outfile<<"账号     ";
	outfile<<depositaccount0.getcardNumber()<<endl;
	outfile<<"姓名     ";
	outfile<<depositaccount0.getuserName()<<endl;
	outfile<<"身份证   ";
	outfile<<depositaccount0.getidNumber()<<endl;
	outfile<<"密码     ";
	outfile<<depositaccount0.getpassword()<<endl;
	outfile<<"当前余额 ";
	outfile<<depositaccount0.getbalance()<<endl;
	outfile<<endl<<"操作记录"<<endl;
	vector<string> t=depositaccount0.getrecord();
	for(string r:t){
		outfile<<r<<endl;
	}
	outfile.close();
}
