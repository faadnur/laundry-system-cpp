#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <cstring>
using namespace std;
void serviceDetails(string&,string&,double&,int);
void cardPurchase(string&,string&,double&);
void cardTopup(string&,string&,double&);
void washerServ(string&,string&,double&);
void dryerServ(string&,string&,double&);
char ansService,code,temp;

int main()
{
	char answer;
	string nameServ[10],servDetail[10],name,details;
	double price,servPrice[10];

	cout<<"Do you want to use the Laundry ABC service (Y-yes, otherwise-no): ";
	cin>>answer;
	answer=toupper(answer);
	while (answer=='Y')
	{
		float total=0.00;
		cout<<"\t\tWasher\n";
		cout<<"\t\t==============================================\n";
		cout<<"\t\tWeight(kg)   Code            Price(RM)        \n";
		cout<<"\t\t                    Cold(C)   Warm(W)   Hot(H)\n";
		cout<<"\t\t----------------------------------------------\n";
		cout<<"\t\t    10        a        4        6         8   \n";
		cout<<"\t\t    15        b        6        8         10  \n";
		cout<<"\t\t    20        c        8        10        12  \n";
		cout<<"\t\t==============================================\n\n\n";

		cout<<"\t\tDryer\n";
		cout<<"\t\t=====================================\n";
		cout<<"\t\t Temperature    Code    Price(RM)    \n";
		cout<<"\t\t-------------------------------------\n";
		cout<<"\t\t    Low          L         6         \n";
		cout<<"\t\t  Medium         M         7         \n";
		cout<<"\t\t   High          H         8         \n";
		cout<<"\t\t=====================================\n";
	
		for (int i=0; i<4 ;i++)
		{
			serviceDetails(name,details,price,i);
			nameServ[i]=name;
			servDetail[i]=details;
			servPrice [i]=price;
			total+=price;
		}
		cout<<"\n\t=============Laundry ABC=============\n";
		cout<<"\t"<<setw(12)<<"Service"<<setw(12)<<"Detailed"<<setw(12)<<"Price(RM)"<<endl;
		for (int j=0; j<4; j++)
		{
			//ada logic error dekat servPrice(Price tak display)
			cout<<"\t"<<setw(12)<<nameServ[j]<<setw(12)<<servDetail[j]<<setw(12)<<setprecision(2)<<fixed<<servPrice[j]<<endl;
		}
		cout<<"\t"<<setw(32)<<"Total(RM):"<<setprecision(2)<<fixed<<total;
		cout<<"\n\tThank you for using our service. Please come again :) ";
		cout<<"\n\nDo you want to use the Laundry ABC service (y-yes, otherwise-no): ";
		cin>>answer;
		answer=toupper(answer);
	}
}

void serviceDetails(string& name,string& details,double& price,int i)
{
	if (i==0)
		cardPurchase (name,details,price);
	if (i==1)
		cardTopup (name,details,price);
	if (i==2)
		washerServ (name,details,price);
	if (i==3)
		dryerServ (name,details,price);
}

void cardPurchase(string& name,string& details,double& price)
{
	name="Card";
	cout<<"1 card:RM 2";
	cout<<"\nBuy card ? (y-yes, otherwise-no): ";
	cin>>ansService;
	ansService=tolower(ansService);
	if (ansService=='y')
	{
		details="1";
		price=2;
	}
	else
	{
		details="-";
		price=0;
	}
}

void cardTopup(string& name,string& details,double& price)
{
	name="Top up";
	details="-";
	cout<<"Top-up card(RM): ";
	cin>>price;
}

void washerServ(string& name,string& details,double& price)
{
	name="Washer";
	cout<<"Want to use washer?(y-yes, otherwise-no): ";
	cin>>ansService;
	ansService=tolower(ansService);
	if (ansService=='y')
	{
		cout<<"Washer code(a/b/c): ";
		cin>>code;
		code=tolower(code);
		
		while (code!='a'&&code!='b'&&code!='c')
		{
			cout<<"You've entered invalid code. Please enter again.";
			cout<<"\nWasher code(a/b/c): ";
			cin>>code;
			code=tolower(code);
		}
		
		cout<<"Water temperature(C/W/H): ";
		cin>>temp;
		temp=toupper(temp);
		while (temp!='C'&&temp!='W'&&temp!='H')
		{
			cout<<"You've entered invalid temperature. Please enter again.";
			cout<<"\nWater temperature(C/W/H): ";
			cin>>temp;
			temp=toupper(temp);
		}
		switch (code)
		{
			case 'a': 
				details="10 kg";
				if (temp=='C')
					price=4;
				else if (temp=='W')
					price=6;
				else
					price=8;
				break;
			case 'b': 
				details="15 kg";
				if (temp=='C')
					price=6;
				else if (temp=='W')
					price=8;
				else
					price=10;
				break;
			default:
				details="20 kg";
				if (temp=='C')
					price=8;
				else if (temp=='W')
					price=10;
				else
					price=12;
		}
	}
	else
	{
		details="-";
		price=0;
	}
}

void dryerServ(string& name,string& details,double& price)
{
	name="Dryer";
	cout<<"Want to use dryer?(y-yes, otherwise-no): ";
	cin>>ansService;
	ansService=tolower(ansService);
	if (ansService=='y')
	{
		cout<<"Dryer temperature(L/M/H): ";
		cin>>temp;
		temp=toupper(temp);
		
		while (temp!='L'&&temp!='M'&&temp!='H')
		{
			cout<<"You've entered invalid temperature. Please enter again.";
			cout<<"\nDryer temperature(L/M/H): ";
			cin>>temp;
			temp=toupper(temp);
		}
		switch (temp)
		{
			case 'L':
				details="Low";
				price=6;
				break;
			case 'M': 
				details="Medium";
				price=7;
				break;
			default:
				details="Medium";
				price=8;
		}
	}
	else
	{
		details="-";
		price=0;
	}
}
