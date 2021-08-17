/*
 * main.cpp
 *
 *  Created on: 2019Äê5ÔÂ7ÈÕ
 *      Author: CJX
 */


#include<iostream>
using namespace std;
#include"controller.h"
int main()
{
	controller main_controller;
	cout<<"--------------------------"<<endl;
	cout<<"Welcome to the ATM system!"<<endl;  //print the interface to hudong with users
	cout<<"--------------------------"<<endl;
	cout<<endl<<"please insert your card."<<endl;
	main_controller.main_controller();


}

