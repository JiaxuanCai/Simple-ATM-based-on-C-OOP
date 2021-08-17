# Simple-ATM-based-on-C-OOP
A project of Chongqing University course: C++ and object oriented programming



This project was meant to deepen the understanding of Object Oriented Programming and practice the skills of coding in C++. 



## Experimental process or algorithm (class design, program implementation process and algorithm process)Experimental process or algorithm (class design, program implementation process and algorithm process)

1. ### Preliminary design

  Before programming, it is necessary to design according to the functions that need to be realized. When I got this topic, I simulated the operation of ATM in real situation in my mind, and divided these operations into different function modules, and made a preliminary assignment of various functions. The initial design followed the MVC design pattern emphasized by the teacher, and the data reading, operation and output were implemented in different classes, which reduced the coupling degree of the code and realized the modular implementation of the function. The initial idea is to create a controller class, which controls the overall flow of the program, stores the data read, calls methods of other objects to operate on the data, and calls the output class to ensure the normal output of the data. Create the readCard class to read the data from the file into the program and store it in the Controller class. Create an Operation class that defines many operations on the data and provides rich interfaces that the Controller class can easily invoke. Create the writecard class to rewrite the processed data to the file. Create the basic class and derive the credit and deposit classes from the basic class to use as data types. A draft of the preliminary design is as follows.

![img](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/clip_image001.png)

2. ### Class design

#### (1) Basic account class (as data type)

Class properties:
String cardNumber specifies the cardNumber of the account
String username Specifies the name of the user
String idNumber specifies the idNumber of the user
String password Specifies the password of the storage account
Int Attempt Indicates the number of attempts to enter the password
Int condition Stores the status of the account (whether the account is locked or not)
Int cardType Specifies the type of the card
Vector record Stores the operation records of this account
Class operations: get and set methods for each property
Class diagram:

![image-20210817155056641](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155056641.png)

#### (2) Savings account class (as data type inheritance basic account class)

Class properties:
In addition to the properties of the superclass, there is a double balance
Class operations: There are set and get methods for balance in addition to the superclass get set method
Class diagram:

![image-20210817155119495](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155119495.png)

#### (3) Credit account class (as data type inheritance basic account class)

Class properties:
In addition to the properties of the superclass
Double line of credit
Double debt The amount currently owed
Class operations: In addition to the superclass's get set methods, there are set and get methods for line,debt
Class diagram:

![image-20210817155139794](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155139794.png)

#### (4) Controller class

Class properties:
Basic basic_account Specifies the basic account
Credit credit_account Deposit credit account
Deposit deposit_account Deposit account
Basic basic_account2 The second account, which is used only for transfer purposes
credit credit_account2;
deposit deposit_account2;
Class operations:
Int main_controller() The primary controller that controls the flow
Void insert_card() controls the function that inserts the card
Int confirmc() confirmc()
Int confirmp() int confirmp()
Void get_account() Read account
Void operate() Operate data
Void set_account1() Write account
void set_account2()
The void return_card () card
Class diagram:

![image-20210817155155409](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155155409.png)

#### (5) Operation data class

Class: none
Class operations:
Void deposit_query(deposit DepositAccount0) query
void credit_query(credit creditaccount0)
Int deposit_withdraw(deposit& DepositAccount0
int credit_withdraw(credit& creditaccount0)
Void deposit_ChangepassWord (deposit& DepositAccount0) Changes the password
void credit_changepassword(credit& creditaccount0)
Void deposit_to_deposit(deposit& d1account, deposit& d2account) Deposit card transfers money to deposit card
Void deposit_to_credit(deposit& DepositAccount0, credit& CreditAccount0) A deposit card transfers money to a credit card
Class diagram:

![image-20210817155210583](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155210583.png)

#### (6) class reading card

Class: none
Class operations:
Void readBasic (String Number,basic& BasicAccount0) Reads the basicaccount information
Void readCredit (credit& CreditAccount0, Basic BasicAccount0) Reads the credit card details
Void readDeposit (deposit& DepositAccount0, Basic BasicAccount0) Reads the details of the deposit card
Class diagram:

![image-20210817155225241](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155225241.png)

#### (7) write a card

Class: none
Class operations:
Void writecredit(credit& CreditAccount0) Writes the credit card information to the file
Void WriteDeposit (deposit& DepositAccount0) Writes the deposit card information to a file
Class diagram:

![image-20210817155237693](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155237693.png)


3. ### Process design

   ![image-20210817155305692](/Users/caijiaxuan/workspace/past_projects/Simple-ATM-based-on-C-OOP/readme imgs/image-20210817155305692.png)

The process design is shown in the UML diagram above!