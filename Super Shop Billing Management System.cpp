#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
		int productcode;
		float price;
		float discount;
		string productname;
public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void list();
			void Delete();
			void receipt();

};

void shopping :: menu()
{
	n:
	int choice;
	string email;
	string password;

	cout<<"\t\t\t\t _____________________________________"<<endl;
	cout<<"\t\t\t\t|                                     |"<<endl;
	cout<<"\t\t\t\t|         Supermarket Main Menu       |"<<endl;
	cout<<"\t\t\t\t|_____________________________________|"<<endl<<endl;
	cout<<"\t\t\t\t          1) Administrator   "<<endl<<endl;
	cout<<"\t\t\t\t          2) Buyer           "<<endl<<endl;
	cout<<"\t\t\t\t          3) Exit            "<<endl<<endl;
	cout<<"\n\t\t\t          Please select:";
	cin>>choice;

	switch(choice)
	{
		case 1:
			cout<<"\n\n\t\t\t\t       Login "<<endl<<endl;
			cout<<"\t\t\t\t  Enter Your Email:   ";
			cin>>email;
			cout<<"\t\t\t\t     Password:       ";
			cin>>password;

			if(email=="CSCProject284@gmail.com" && password=="CSC284")
			{
				administrator();
			}
			else
			{
				cout<<"\nInvalid email/password"<<endl<<endl;
			}
			break;


	case 2:
		{
			buyer();

		}

	case 3:
		{
			exit(0);
		}

		default :
			{
				cout<< "Please select from the given options";

			}
}
goto n;
}
void shopping:: administrator()
{
	n:
	int choice;
	cout<<"\n\n\n\t\t\t     Administrator menu"<<endl;
	cout<<"\t\t    ____________________________________  "<<endl<<endl;
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";

    cout<<"\n\n\t\t   Please enter your choice :";
    cin>>choice;

    switch(choice)
    {
    	case 1:
    		add();
    		break;

    	case 2:
    		edit();
    		break;

    	case 3:
    		Delete();
    		break;

    	case 4:
    		menu();
    		break;

    	default :
    		cout<<"Invalid choice!";

	}
	goto n;
}

void shopping:: buyer()
{
	n:
	int choice;
	cout<<"\t\t\t    Buyer  "<<endl;
	cout<<"\t\t\t_____________  "<<endl<<endl;
	cout<<"\t\t\t1) Buy product "<<endl<<endl;
	cout<<"\t\t\t2) Go back     "<<endl<<endl;
	cout<<"\t\t\t Enter your choice : ";

	cin>>choice;

	switch(choice)
	{
		case 1:
			receipt();
			break;

		case 2:
			menu();

		default :

			cout<<"invalid choice!";

	}

	goto n;
}
void shopping:: add()
{
    n:
	fstream data;
	int code;
	int temp=0;
	float p;
	float d;
	string n;

	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>productcode;
	cout<<"\n\n\t Name of the product ";
	cin>>productname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on product";
	cin>>discount;

	data.open("cscproject.txt",ios::in);

	if(!data)
	{
		data.open("cscproject.txt", ios::app|ios::out);
		data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<endl;
		data.close();
	}
	else
	{
		data>>code>>n>>p>>d;

		while(!data.eof())
		{
			if(code ==productcode)
			{
				temp++;

			}
			data>>code>>n>>p>>d;
		}
		data.close();




	if(temp==1)
    goto n;
	else{
		data.open("cscproject.txt", ios::app|ios::out);
		data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<endl;
		data.close();

	    }
}
	cout<<"\n\n\t\t Record inserted !";

}
void shopping:: edit()
{
	fstream data,data1;
	int pkey;
	int temp=0;
	int code;
	float p;
	float d;
	string n;

	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;

	data.open("cscproject.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Does not exist! ";
	}
	else{

		data1.open("cscproject2.txt", ios::app|ios::out);

		data>>productcode>>productname>>price>>discount;
		while(!data.eof())
		{
			if(pkey==productcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>code;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<code<<" "<<n<<" "<<p<<" "<<d<<endl;
				cout<<"\n\n\t\t Product edited ";
				temp++;
			}
			else
			{
				data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<endl;

			}
			data>>productcode>>productname>>price>>discount;
		}
		data.close();
		data1.close();

		remove("cscproject.txt");
		rename("cscproject2.txt","cscproject.txt");

		if(temp==0)
		{
			cout<<"\n\n Record not found!";
		}
	}
}
void shopping:: Delete()
{
	fstream data,data1;
	int pkey;
	int temp=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("cscproject.txt", ios::in);
	if(!data)
	{
		cout<<"Does not exist";

	}

	else{
		data1.open("cscproject2.txt",ios::app|ios::out);
		data>>productcode>>productname>>price>>discount;
		while(!data.eof())
		{
			if(productcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				temp++;
			}
			else
			{
				data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<endl;

			}
			data>>productcode>>productname>>price>>discount;
		}
		data.close();
		data1.close();
		remove("cscproject.txt");
		rename("cscproject2.txt","cscproject.txt");

		if(temp==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}
void shopping:: list()
{
	fstream data;
	data.open("cscproject.txt",ios::in);
	cout<<"\n\n|___________________________________________________________"<<endl;
	cout<<"ProductNo.\t\tName\t\tPrice\n";
	cout<<"\n\n|___________________________________________________________"<<endl;
	data>>productcode>>productname>>price>>discount;
	while(!data.eof())
	{
		cout<<productcode<<"\t\t"<<productname<<"\t\t"<<price<<endl;
		data>>productcode>>productname>>price>>discount;

	}
	data.close();
}
void shopping:: receipt()
{
		system("cls");
		fstream data;

		int arrc[100],arrq[100];
		char choice;
		int code=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("cscproject.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty List";
		}
		else
		{
			data.close();
			list();
			cout<<"\n ____________________________\n";
			cout<<"\n|                            |";
			cout<<"\n|    Please place the order  |";
			cout<<"\n|____________________________|\n";
			do
			{
				n:
				cout<<"\n\n Product Code : ";
				cin>>arrc[code];
				cout<<"\n Product Quantity : ";
				cin>>arrq[code];
				for(int i=0;i<code;i++)
				{
					if(arrc[code] == arrc[i])
					{
						cout<<"\n\n Product Code is already inserted. Please try again!";
						goto n;
					}
				}
				code++;
				cout<<"\n\n Are you want to buy another product?"<<endl<<" Press y for yes and n for no : ";
				cin>>choice;
			}

			while(choice == 'y');
			system("cls");

			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";


			for(int i=0;i<code;i++)
			{
				data.open("cscproject.txt",ios::in);
				data>>productcode>>productname>>price>>discount;
				while(!data.eof())
				{
					if(productcode == arrc[i])
					{
						amount = price*arrq[i];
						discount = amount - (amount*discount/100);
						total =total+ discount;
						cout<<"\n"<<productcode<<"\t\t"<<productname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
					}
					   data>>productcode>>productname>>price>>discount;
				}
				data.close();
			}
			cout<<"\n\n----------------------------------------";
			cout<<"\n Total Amount : "<<total;
		}
}
int main()
{
    shopping obj;
    obj.menu();
    return 0;
}

