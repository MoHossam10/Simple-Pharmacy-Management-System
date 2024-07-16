#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class medicine
{
public:
	int id;
	string name;
	int stock;
	int price;
	int day;
	int month;
	int year;
	medicine* pnext;
};
class clistMedicine
{
public:
	medicine* phead;
	medicine* ptail;
	clistMedicine()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(medicine* pnn)
	{
		if (phead == NULL)
		{
			phead = ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void Disp()
	{
		medicine* ptrv = phead;
		cout << "MEDICINES" << endl << "=========" << endl;
		while (ptrv != NULL)
		{
			cout << "ID: " << ptrv->id << "," << "NAME: " << ptrv->name << "," << "NUMBER OF STOCKS: " << ptrv->stock << ',' << "PRICE: " << ptrv->price << "," << "EXPIRE DAY: " << ptrv->day << "," << "EXPIRE MONTH: " << ptrv->month << "," << "EXPIRE YEAR: " << ptrv->year << endl;
			ptrv = ptrv->pnext;
		}
		cout << "==============================================================" << endl;
	}
};
class customer
{
public:
	int id;
	string name;
	customer* pnext;
};
class clistCustomer
{
public:
	customer* phead;
	customer* ptail;
	clistCustomer()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(customer* pnn2)
	{
		if (phead == NULL)
		{
			phead = ptail = pnn2;
		}
		else
		{
			ptail->pnext = pnn2;
			ptail = pnn2;
		}
	}
	void Disp()
	{
		customer* ptrv = phead;
		cout << "CUSTOMERS" << endl << "============" << endl;
		while (ptrv != NULL)
		{
			cout << "ID: " << ptrv->id << "," << "NAME: " << ptrv->name << endl;
			ptrv = ptrv->pnext;
		}
		cout << "==============================================================" << endl;
	}
};
class MedCust
{
public:
	int Cid;
	int Mid;
	int price;
	int day;
	int month;
	int year;
	MedCust* pnext;
};
class clistMedCust
{
public:
	MedCust* phead;
	MedCust* ptail;
	clistMedCust()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(MedCust* pnn3)
	{
		if (phead == NULL)
		{
			phead = ptail = pnn3;
		}
		else
		{
			ptail->pnext = pnn3;
			ptail = pnn3;
		}
	}
	void Disp()
	{
		MedCust* ptrv = phead;
		cout << "MEDCUST" << endl << "============" << endl;
		while (ptrv != NULL)
		{
			cout << "MID: " << ptrv->Mid << "," << " CID: " << ptrv->Cid << "," << " PRICE: " << ptrv->price << "," << " DAY: " << ptrv->day << "," << " MONTH: " << ptrv->month << "," << "YEAR: " << ptrv->year << endl;
			ptrv = ptrv->pnext;
		}
		cout << "==============================================================" << endl;
	}
};
int main()
{
	int n;
	fstream xfile;
	clistMedicine l;
	medicine* pnn;
	xfile.open("C://Users//pc//OneDrive//Desktop//medicine.txt");
	if (xfile.is_open())
	{
		string line;
		while (getline(xfile, line))
		{
			int it = 0;
			string temp[7];
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it] += line[i];
				}
			}
			pnn = new medicine;
			pnn->id = stoi(temp[0]);
			pnn->name = temp[1];
			pnn->stock = stoi(temp[2]);
			pnn->price = stoi(temp[3]);
			pnn->day = stoi(temp[4]);
			pnn->month = stoi(temp[5]);
			pnn->year = stoi(temp[6]);
			pnn->pnext = NULL;
			l.attach(pnn);
		}
	}
	xfile.close();
	fstream xfile2;
	clistCustomer l2;
	customer* pnn2;
	xfile2.open("C://Users//pc//OneDrive//Desktop//customer.txt");
	if (xfile2.is_open())
	{
		string line;
		while (getline(xfile2, line))
		{
			int it = 0;
			string temp[2];
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it] += line[i];
				}
			}
			pnn2 = new customer;

			pnn2->id = stoi(temp[0]);
			pnn2->name = temp[1];
			pnn2->pnext = NULL;
			l2.attach(pnn2);
		}
	}
	xfile2.close();
	fstream xfile3;
	clistMedCust l3;
	MedCust* pnn3;
	xfile3.open("C://Users//pc//OneDrive//Desktop//MedCust.txt");
	if (xfile3.is_open())
	{
		string line;
		while (getline(xfile3, line))
		{
			int it = 0;
			string temp[6];
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it] += line[i];
				}
			}
			pnn3 = new MedCust;
			pnn3->Mid = stoi(temp[0]);
			pnn3->Cid = stoi(temp[1]);
			pnn3->price = stoi(temp[2]);
			pnn3->day = stoi(temp[3]);
			pnn3->month = stoi(temp[4]);
			pnn3->year = stoi(temp[5]);
			pnn3->pnext = NULL;
			l3.attach(pnn3);
		}
	}
	xfile3.close();
	for (;;)
	{
		cout << "========== PHARMACY SYSTEM ==========" << endl;
		cout << "1- ALL MEDICINCES" << endl;
		cout << "2- ALL CUSTOMERS" << endl;
		cout << "3- BUY" << endl;
		cout << "4- RETURN" << endl;
		cout << "5- THE INCOME OF A SPECIFIC DATE" << endl;
		cout << "6- THE MEDICINES WITH AN EXPIRE DATE" << endl;
		cout << "7-EXIT" << endl;
		cout << "==========================================" << endl;
		cout << "CHOOSE A NUMBER : ";
		cin >> n;
		if (n == 1)
		{
			l.Disp();
		}
		if (n == 2)
		{
			l2.Disp();
		}
		if (n == 3)
		{
			//xfile2.open("C://Users//pc//OneDrive//Desktop//customer.txt");
			cout << " ENTER CUSTOMER ID" << endl;
			int CUST_id;
			cin >> CUST_id;
			customer* ptrv2 = l2.phead;
			while (ptrv2 != NULL)
			{
				if (ptrv2->id == CUST_id)
				{

					medicine* ptrv = l.phead;
					cout << " ENTER MEDICINE ID" << endl;
					int MED_id;
					cin >> MED_id;
					cout << " HOW MANY OF THIS MEDICINE HE WANTS TO BUY " << endl;
					int numb;
					cin >> numb;
					int price;

					while (ptrv != NULL)
					{
						if (ptrv->id == MED_id)
						{
							cout << " ENTER DAY" << endl;
							int day;
							cin >> day;
							cout << " ENTER MONTH" << endl;
							int month;
							cin >> month;
							cout << " ENTER YEAR" << endl;
							int year;
							cin >> year;
							if (numb < ptrv->stock)
							{
								price = numb * ptrv->price;
								if (day <= ptrv->day && month <= ptrv->month && year <= ptrv->year)
								{
									ptrv->stock = ptrv->stock - numb;
									pnn3 = new MedCust;
									pnn3->Mid = MED_id;
									pnn3->Cid = CUST_id;
									pnn3->price = price;
									pnn3->day = day;
									pnn3->month = month;
									pnn3->year = year;
									pnn3->price = price;
									pnn3->pnext = NULL;
									l3.attach(pnn3);
									xfile3.open("C://Users//pc//OneDrive//Desktop//MedCust.txt", ios::app);
									xfile3 << MED_id << ',' << CUST_id << ',' << price << ',' << day << ',' << month << ',' << year << endl;
									xfile3.close();
									l3.Disp();
									medicine* pt88 = l.phead;
									xfile.open("C://Users//pc//OneDrive//Desktop//medicine.txt", ios::out);
									while (pt88 != NULL)
									{
										xfile << pt88->id << ',' << pt88->name << ',' << pt88->stock << ',' << pt88->price << ',' << pt88->day << ',' << pt88->month << ',' << pt88->year << endl;
										pt88 = pt88->pnext;
									}
									xfile.close();
									break;
								}
								else
								{
									cout << " EXPIRED DATE " << endl;
									cout << "----------------------------------------------------------" << endl;
									l.Disp();
								}
							}
							else
							{
								cout << " OUT OF STOCK" << endl;
								cout << "----------------------------------------------------------" << endl;
								l.Disp();
							}
						}
						ptrv = ptrv->pnext;
					}
				}
				else
				{
					cout << " ID IS NOT FOUND" << endl;
					cout << " ENTER CUSTOMER NAME" << endl;
					string CUST_name;
					cin >> CUST_name;
					pnn2 = new customer;
					pnn2->id = CUST_id;
					pnn2->name = CUST_name;
					pnn2->pnext = NULL;
					l2.attach(pnn2);
					xfile2.open("C://Users//pc//OneDrive//Desktop//customer.txt", ios::app);
					xfile2 << endl << CUST_id << ',' << CUST_name, '\0';
					xfile2.close();
					l2.Disp();
					medicine* ptrv = l.phead;
					cout << " ENTER MEDICINE ID" << endl;
					int MED_id;
					cin >> MED_id;
					cout << " HOW MANY OF THIS MEDICINE HE WANTS TO BUY " << endl;
					int numb;
					cin >> numb;
					int price;
					while (ptrv != NULL)
					{
						if (ptrv->id == MED_id)
						{
							cout << " ENTER DAY" << endl;
							int day;
							cin >> day;
							cout << " ENTER MONTH" << endl;
							int month;
							cin >> month;
							cout << " ENTER YEAR" << endl;
							int year;
							cin >> year;
							if (numb < ptrv->stock)
							{
								price = numb * ptrv->price;
								if (day <= ptrv->day && month <= ptrv->month && year <= ptrv->year)
								{
									ptrv->stock = ptrv->stock - numb;
									pnn3 = new MedCust;
									pnn3->Mid = MED_id;
									pnn3->Cid = CUST_id;
									pnn3->price = price;
									pnn3->day = day;
									pnn3->month = month;
									pnn3->year = year;
									pnn3->pnext = NULL;
									l3.attach(pnn3);
									xfile3.open("C://Users//pc//OneDrive//Desktop//MedCust.txt", ios::app);
									xfile3 << MED_id << ',' << CUST_id << ',' << price << ',' << day << ',' << month << ',' << year << endl;
									xfile3.close();
									l3.Disp();
									medicine* pt88 = l.phead;
									xfile.open("C://Users//pc//OneDrive//Desktop//medicine.txt", ios::out);
									while (pt88 != NULL)
									{
										xfile << pt88->id << ',' << pt88->name << ',' << pt88->stock << ',' << pt88->price << ',' << pt88->day << ',' << pt88->month << ',' << pt88->year << endl;
										pt88 = pt88->pnext;
									}
									xfile.close();
									break;
								}
								else
								{
									cout << " EXPIRED DATE " << endl;
									cout << "----------------------------------------------------------" << endl;
									l.Disp();
								}
							}
							else
							{
								cout << " OUT OF STOCK" << endl;
								cout << "----------------------------------------------------------" << endl;
								l.Disp();
							}
						}
						ptrv = ptrv->pnext;
					}
				}
				ptrv2 = ptrv2->pnext;
			}
			//xfile2.close();
		}
		if (n == 4)
		{
			cout << " ENTER CUSTOMER ID" << endl;
			int CUST_id;
			cin >> CUST_id;
			cout << " ENTER MEDICINE ID" << endl;
			int MED_id;
			cin >> MED_id;
			medicine* pt70 = l.phead;
			MedCust* ptrv3 = l3.phead;
			MedCust* pb = NULL;
			while (ptrv3 != NULL)
			{
				if (ptrv3->Cid == CUST_id && ptrv3->Mid == MED_id)
				{
					cout << " HOW MANY OF THIS MEDICINE HE WANTS TO RETURN " << endl;
					int numbbb;
					cin >> numbbb;
					pt70->stock += numbbb;
					if (pb == NULL)
					{
						l3.phead = l3.phead->pnext;
						ptrv3->pnext = NULL;
						delete ptrv3;
						break;
					}
					pb->pnext = ptrv3->pnext;
					ptrv3->pnext = NULL;
					delete ptrv3;
					break;
				}
				pb = ptrv3;
				ptrv3 = ptrv3->pnext;
			}
			MedCust* pt4 = l3.phead;
			xfile3.open("C://Users//pc//OneDrive//Desktop//MedCust.txt", ios::out);
			while (pt4 != NULL)
			{
				xfile3 << pt4->Mid << ',' << pt4->Cid << ',' << pt4->price << ',' << pt4->day << ',' << pt4->month << ',' << pt4->year << endl;
				pt4 = pt4->pnext;
			}
			l3.Disp();
			xfile3.close();
			medicine* pt77 = l.phead;
			xfile.open("C://Users//pc//OneDrive//Desktop//medicine.txt", ios::out);
			while (pt77 != NULL)
			{
				xfile << pt77->id << ',' << pt77->name << ',' << pt77->stock << ',' << pt77->price << ',' << pt77->day << ',' << pt77->month << ',' << pt77->year << endl;
				pt77 = pt77->pnext;
			}
			xfile.close();
		}
		if (n == 5)
		{
			xfile3.open("C://Users//pc//OneDrive//Desktop//MedCust.txt");
			MedCust* pt5 = l3.phead;
			cout << " ENTER DAY" << endl;
			int day;
			cin >> day;
			cout << " ENTER MONTH" << endl;
			int month;
			cin >> month;
			cout << " ENTER YEAR" << endl;
			int year;
			cin >> year;
			int tot = 0;
			while (pt5 != NULL)
			{
				if (pt5->day == day && pt5->month == month && pt5->year == year)
				{
					tot += pt5->price;
				}
				pt5 = pt5->pnext;
			}
			cout << " INCOME OF DATE: " << tot << endl;
			xfile3.close();
		}
		if (n == 6)
		{
			l.Disp();
			cout << " ENTER DAY" << endl;
			int day;
			cin >> day;
			cout << " ENTER MONTH" << endl;
			int month;
			cin >> month;
			cout << " ENTER YEAR" << endl;
			int year;
			cin >> year;
			medicine* pt22 = l.phead;
			while (pt22 != NULL)
			{
				if (pt22->day - day <= 7 || pt22->day - day * -1 <= 7)
				{
					if (pt22->month == month && pt22->year == year)
					{
						cout << "----------------------------------------------------------" << endl;
						cout << "Display the medicine's name with an expiry date within a week or less" << endl;
						cout << "NAME:" << pt22->name << endl;
						cout << "DATE:" << pt22->day << '/' << pt22->month << '/' << pt22->year << endl;
						cout << "-----------------------------------------------------------" << endl;
					}
				}
				pt22 = pt22->pnext;
			}
		}
		if (n == 7)
		{
			system("cls");
			cout << "GOOD BYE   ";
		}
		system("pause");
		system("cls");
	}
}