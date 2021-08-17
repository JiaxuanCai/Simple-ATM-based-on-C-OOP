/*
 * writecard.cpp
 *
 *  Created on: 2019��5��10��
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
	outfile<<"�˺�     ";
	outfile<<creditaccount0.getcardNumber()<<endl;
	outfile<<"����     ";
	outfile<<creditaccount0.getuserName()<<endl;
	outfile<<"���֤   ";
	outfile<<creditaccount0.getidNumber()<<endl;
	outfile<<"����     ";
	outfile<<creditaccount0.getpassword()<<endl;
	outfile<<"���ö�� ";
	outfile<<creditaccount0.getline()<<endl;
	outfile<<"��ǰǷ�� ";
	outfile<<creditaccount0.getdebt()<<endl;
	outfile<<endl<<"������¼"<<endl;
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
	outfile<<"�˺�     ";
	outfile<<depositaccount0.getcardNumber()<<endl;
	outfile<<"����     ";
	outfile<<depositaccount0.getuserName()<<endl;
	outfile<<"���֤   ";
	outfile<<depositaccount0.getidNumber()<<endl;
	outfile<<"����     ";
	outfile<<depositaccount0.getpassword()<<endl;
	outfile<<"��ǰ��� ";
	outfile<<depositaccount0.getbalance()<<endl;
	outfile<<endl<<"������¼"<<endl;
	vector<string> t=depositaccount0.getrecord();
	for(string r:t){
		outfile<<r<<endl;
	}
	outfile.close();
}
