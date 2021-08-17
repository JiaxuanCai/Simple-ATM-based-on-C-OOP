/*
 * readcard.cpp
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */
#include<iostream>
using namespace std;
#include"readcard.h"



void readcard::readbasic(string number,basic& basicaccount0)//read the basic information of an account
{
	string rubbish;//rubbish is set to store the biaotou
	string reading;
	int reading1;
	ifstream infile;
	string position="E:\\Cpp projects\\ATM\\data\\";
	string backfix=".txt";
	string w;
	w=position+number+backfix;
	infile.open(w,ios::out);
	infile>>reading1;
	basicaccount0.setcardType(reading1);
	infile>>reading1;
	basicaccount0.setcondition(reading1);
	infile>>reading1;
	basicaccount0.setattempt(reading1);
	infile>>rubbish;
	infile>>reading;
	basicaccount0.setcardNumber(reading);
	infile>>rubbish;
	infile>>reading;
	basicaccount0.setuserName(reading);
	infile>>rubbish;
	infile>>reading;
	basicaccount0.setidNumber(reading);
	infile>>rubbish;
	infile>>reading;
	basicaccount0.setpassword(reading);
	infile.close();
}


void readcard::readcredit(credit& creditaccount0,  basic basicaccount0)//read the full information of an credit account
{
	string rubbish;
	string reading;
	int reading1;
	double reading2;
	ifstream infile;
	string position="E:\\Cpp projects\\ATM\\data\\";
	string backfix=".txt";
	string w;
	w=position+basicaccount0.getcardNumber()+backfix;
	infile.open(w,ios::out);
	infile>>reading1;
	creditaccount0.setcardType(reading1);
	infile>>reading1;
	creditaccount0.setcondition(reading1);
	infile>>reading1;
	creditaccount0.setattempt(reading1);
	infile>>rubbish;
	infile>>reading;
	creditaccount0.setcardNumber(reading);
	infile>>rubbish;
	infile>>reading;
	creditaccount0.setuserName(reading);
	infile>>rubbish;
	infile>>reading;
	creditaccount0.setidNumber(reading);
	infile>>rubbish;
	infile>>reading;
	creditaccount0.setpassword(reading);
	infile>>rubbish;
	infile>>reading2;
	creditaccount0.setline(reading2);
	infile>>rubbish;
	infile>>reading2;
	creditaccount0.setdebt(reading2);
	infile>>rubbish;
	while(!infile.eof())
	{
		string temp;
		infile >> temp;
		creditaccount0.setrecord(temp);
	}
	infile.close();

}


void readcard::readdeposit(deposit& depositaccount0,basic basicaccount0)//read the full information of an deposit account
{
	string rubbish;
	string reading;
	int reading1;
	double reading2;
	ifstream infile;
	string position="E:\\Cpp projects\\ATM\\data\\";
	string backfix=".txt";
	string w;
	w=position+basicaccount0.getcardNumber()+backfix;
	infile.open(w,ios::out);
	infile>>reading1;
	depositaccount0.setcardType(reading1);
	infile>>reading1;
	depositaccount0.setcondition(reading1);
	infile>>reading1;
	depositaccount0.setattempt(reading1);
	infile>>rubbish;
	infile>>reading;
	depositaccount0.setcardNumber(reading);
	infile>>rubbish;
	infile>>reading;
	depositaccount0.setuserName(reading);
	infile>>rubbish;
	infile>>reading;
	depositaccount0.setidNumber(reading);
	infile>>rubbish;
	infile>>reading;
	depositaccount0.setpassword(reading);
	infile>>rubbish;
		//cout<<rubbish<<endl;
	infile>>reading2;
		//cout<<reading2<<endl;
	depositaccount0.setbalance(reading2);
	infile>>rubbish;
	while(!infile.eof())
	{
		string temp;
		infile >> temp;
		depositaccount0.setrecord(temp);
	}
	infile.close();
}
