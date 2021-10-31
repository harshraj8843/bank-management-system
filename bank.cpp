//Bank management project;

///////////////////////////////////////////////////////
//  BANK MANAGEMENT SYSTEM                           //
//  ----------------------                           //
//                                                   //
//  FEATURES :                                       //
//     * Object oriented programming.                //
//     * File Handling with C++.                     //
//                                                   //
///////////////////////////////////////////////////////

// Programme Starts Here.

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
void startpage();
void loginpage();
void adminlogin();
void stafflogin();
void customerlogin();
int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}
class forall //for id and pass varification;
{
public:
	int avalidate(char name[], char id[], char pwd[], int nc)
	{
		bool flag = false;
		fstream fname;
		fname.open(name, ios::in);
		string line;
		int r = 0;
		while (!fname.eof())
		{
			getline(fname, line);
			int i = 0;
			if (r != 0)
			{
				for (int j = 0; j < nc; j++)
				{
					if (line[i] == ':')
						i++;
					else
					{
						int k = 0;
						char finput[10] = "";
						while (line[i] != ':')
						{
							finput[k] = line[i];
							i++;
							k++;
						}
						if (compare(finput, id) == 1)
						{
							i = i + 1;
							int k = 0;
							char finput1[10] = "";

							while (line[i] != ':')
							{
								finput1[k] = line[i];
								i++;
								k++;
							}
							if (compare(pwd, finput1) == 1)
							{
								flag = true;
								break;
							}
							break;
						}
					}
				}
			}
			else
				r++;
		}
		cout << endl;
		fname.close();
		if (flag == true)
			return 1;
		else
			return 0;
	}
	int validate(char name[], char id[], char pwd[], int nc)
	{
		bool flag = false;
		fstream fname;
		fname.open(name, ios::in);
		string line;
		int r = 0;
		int x = checka(name, id, nc);
		if (x == 0)
		{
			cout << endl
				 << "\tSorry but this id is not available!!!" << endl;
		}
		else
		{
			if (x == 1)
			{
				while (!fname.eof())
				{
					getline(fname, line);
					int i = 0;
					if (r != 0)
					{
						for (int j = 0; j < nc; j++)
						{
							if (line[i] == ':')
								i++;
							else
							{
								int k = 0;
								char finput[10] = "";
								while (line[i] != ':')
								{
									finput[k] = line[i];
									i++;
									k++;
								}
								if (compare(finput, id) == 1)
								{
									i = i + 1;
									int k = 0;
									char finput1[10] = "";

									while (line[i] != ':')
									{
										finput1[k] = line[i];
										i++;
										k++;
									}
									if (compare(pwd, finput1) == 1)
									{
										flag = true;
										break;
									}
									break;
								}
							}
						}
					}
					else
						r++;
				}
			}
			else
				flag = false;
		}
		cout << endl;
		fname.close();
		if (flag == true)
			return 1;
		else
			return 0;
	}
	int compare(char s1[], char s2[])
	{
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		bool flag = true;
		int i = 0;
		while (i != max(n1, n2))
		{
			if (s1[i] != s2[i])
				flag = false;
			i++;
		}
		if (flag == true)
			return 1;
		else
			return 0;
	}
	void show(char name[], int nc)
	{
		fstream fname;
		fname.open(name, ios::in);
		string line;
		while (!fname.eof())
		{
			getline(fname, line);
			int i = 0;
			for (int j = 0; j < nc; j++)
			{
				if (line[i] == ':')
					i++;
				else
				{
					int k = 0;
					char finput[10] = "";
					while (line[i] != ':')
					{
						finput[k] = line[i];
						i++;
						k++;
					}
					cout << setw(11) << finput;
				}
			}
			cout << endl;
		}
		cout << endl;
		fname.close();
	}
	void find(char name[], char id[], int nc)
	{
		bool flag = false;
		fstream fname, fname1;
		fname.open(name, ios::in);
		fname1.open(name, ios::in);
		string line, line1;
		int r = 0;
		while (!fname.eof())
		{
			getline(fname, line);
			int i = 0;
			int temp = 0;
			if (r != 0)
			{
				for (int j = 0; j < 1; j++)
				{
					if (line[i] == ':')
						i++;
					else
					{
						int k = 0;
						char finput[10] = "";
						while (line[i] != ':')
						{
							finput[k] = line[i];
							i++;
							k++;
						}
						if (compare(finput, id) == 1)
						{
							int r1 = 0;
							while (!fname1.eof())
							{
								getline(fname1, line1);
								int i1 = 0;
								if (r1 == 0)
								{
									for (int j1 = 0; j1 < nc; j1++)
									{
										if (line1[i1] == ':')
											i1++;
										else
										{
											int k1 = 0;
											char finput2[10] = "";
											while (line1[i1] != ':')
											{
												finput2[k1] = line1[i1];
												i1++;
												k1++;
											}
											cout << setw(11) << finput2;
										}
									}
								}
								cout << endl;
								break;
							}
							fname1.close();
							int i = 0;
							for (int j = 0; j < nc; j++)
							{
								if (line[i] == ':')
									i++;
								else
								{
									int k = 0;
									char finput1[10] = "";
									while (line[i] != ':')
									{
										finput1[k] = line[i];
										i++;
										k++;
									}
									cout << setw(11) << finput1;
								}
							}
							flag = true;
							break;
						}
					}
				}
			}
			else
			{
				r++;
			}
		}
		if (flag == false)
			cout << "\tEntered id not found in records.";
		cout << endl;
		fname.close();
	}
	void findcust(char name[], char id[], int nc)
	{
		bool flag = false;
		fstream fname, fname1;
		fname.open(name, ios::in);
		fname1.open(name, ios::in);
		string line, line1;
		int r = 0;
		int temp = 0;
		while (!fname.eof())
		{
			getline(fname, line);
			int i = 0;
			int temp = 0;
			if (r != 0)
			{
				for (int j = 0; j < 1; j++)
				{
					if (line[i] == ':')
						i++;
					else
					{
						int k = 0;
						char finput[10] = "";
						while (line[i] != ':')
						{
							finput[k] = line[i];
							i++;
							k++;
						}
						if (compare(finput, id) == 1)
						{
							int r1 = 0;
							while (!fname1.eof())
							{
								getline(fname1, line1);
								int i1 = 0;
								if (r1 == 0)
								{
									for (int j1 = 0; j1 < nc; j1++)
									{
										if (line1[i1] == ':')
											i1++;
										else
										{
											int k1 = 0;
											char finput2[10] = "";
											while (line1[i1] != ':')
											{
												finput2[k1] = line1[i1];
												i1++;
												k1++;
											}
											if (j1 == 2)
											{
												temp++;
											}
											else
											{
												cout << setw(11) << finput2;
											}
										}
									}
								}
								cout << endl;
								break;
							}
							fname1.close();
							int i = 0;
							for (int j = 0; j < nc; j++)
							{
								if (line[i] == ':')
									i++;
								else
								{
									int k = 0;
									char finput1[10] = "";
									while (line[i] != ':')
									{
										finput1[k] = line[i];
										i++;
										k++;
									}
									if (j == 4)
									{
										temp++;
									}
									else
									{
										cout << setw(11) << finput1;
									}
								}
							}
							flag = true;
							break;
						}
					}
				}
			}
			else
			{
				r++;
			}
		}
		if (flag == false)
			cout << "\tEntered id not found in records.";
		cout << endl;
		fname.close();
	}
	int checka(char name[], char id[], int nc)
	{
		bool idflag = false;
		bool aflag = false;
		char temp[3] = "a";
		fstream fname;
		fname.open(name, ios::in);
		string line;
		int r = 0;
		while (!fname.eof())
		{
			getline(fname, line);
			int i = 0;

			if (r != 0)
			{
				for (int j = 0; j < 1; j++)
				{
					if (line[i] == ':')
						i++;
					else
					{
						int k = 0;
						char finput[10] = "";
						while (line[i] != ':')
						{
							finput[k] = line[i];
							i++;
							k++;
						}
						if (compare(finput, id) == 1)
						{
							idflag = true;
							int i1 = 0;
							for (int j1 = 0; j1 < nc; j1++)
							{
								if (line[i1] == ':')
									i1++;
								else
								{
									int k1 = 0;
									char finput1[10] = "";
									while (line[i1] != ':')
									{
										finput1[k1] = line[i1];
										i1++;
										k1++;
									}
									if (compare(finput1, temp) == 1)
									{
										aflag = true;
									}
								}
							}
						}
					}
				}
			}
			else
				r++;
		}
		fname.close();
		if (idflag == true)
		{
			if (aflag == true)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return -1;
	}
	void remove(char name[], char id[], int nc)
	{
		char name1[11] = ".temporary";
		bool flag = false;
		bool imflag = false;
		bool fflag = false;
		char temp[3] = "a";
		char temp1[3] = "na";
		char tempdata1[3] = "na";
		fstream fname, fname1;
		fname.open(name, ios::in);
		fname1.open(name1, ios::out);
		string line;
		int r = 0;
		while (!fname.eof())
		{
			flag = false;
			getline(fname, line);
			int i = 0;

			for (int j = 0; j < 1; j++)
			{
				if (line[i] == ':')
					i++;
				else
				{
					int k = 0;
					char finput[10] = "";
					while (line[i] != ':')
					{
						finput[k] = line[i];
						i++;
						k++;
					}
					if (compare(finput, id) == 1)
					{
						fname1 << endl;
						flag = true;
						fflag = true;
						int i1 = 0;
						for (int j1 = 0; j1 < nc; j1++)
						{
							if (line[i1] == ':')
								i1++;
							else
							{
								int k1 = 0;
								char finput1[10] = "";
								while (line[i1] != ':')
								{
									finput1[k1] = line[i1];
									i1++;
									k1++;
								}
								if (compare(finput1, temp) == 1)
								{
									flag = true;
									imflag = true;
									fname1 << tempdata1 << ":";
								}
								else
								{
									fname1 << finput1 << ":";
								}
							}
						}
					}
				}
			}
			if (flag == false)
			{
				if (r == 0)
				{
					fname1 << line;
				}
				else
				{
					fname1 << endl
						   << line;
				}
			}
			r++;
		}
		fname.close();
		fname1.close();
		if (fflag == true)
		{
			if (imflag == true)
			{
				system("clear");
				cout << "\t--------------------------" << endl;
				cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
				cout << "\t--------------------------" << endl
					 << endl
					 << endl;
				find(name, id, nc);
				int n;
			label1:
				cout << endl
					 << "\t1. Continue" << endl;
				cout << "\t2. Cancel" << endl
					 << endl;
				cout << "\tEnter number of your choice : ";
				cin >> n;
				if (n == 1)
				{
					fname.open(name, ios::out);
					fname1.open(name1, ios::in);
					int i = 0;
					while (!fname1.eof())
					{
						getline(fname1, line);
						if (i == 0)
						{
							fname << line;
						}
						else
							fname << endl
								  << line;
						i++;
					}
					fname.close();
					fname1.close();
					fname1.open(name1, ios::out);
					fname1.close();
					system("clear");
					cout << "\t--------------------------" << endl;
					cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
					cout << "\t--------------------------" << endl
						 << endl
						 << endl;
					cout << endl
						 << "\tRecord Updated Successfully !!!" << endl;
				}
				else
				{
					if (n == 2)
					{
						fname1.close();
						system("clear");
						cout << "\t--------------------------" << endl;
						cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
						cout << "\t--------------------------" << endl
							 << endl
							 << endl;
						cout << endl
							 << "\tCancelled !!!" << endl;
					}
					else
					{
						cout << endl
							 << "\tInvalid Input" << endl;
						goto label1;
					}
				}
			}
			else
			{
				system("clear");
				cout << "\t--------------------------" << endl;
				cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
				cout << "\t--------------------------" << endl
					 << endl
					 << endl;
				find(name, id, nc);
				cout << endl
					 << "\tRecord already removed" << endl;
				fname1.open(name1, ios::out);
				fname1.close();
			}
		}
		else
		{
			system("clear");
			cout << "\t--------------------------" << endl;
			cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
			cout << "\t--------------------------" << endl
				 << endl
				 << endl;
			cout << "\tRecord Not Found !!!" << endl;
			fname1.open(name1, ios::out);
			fname1.close();
		}
	}
	void removec(char name[], char id[], int nc)
	{
		char name1[11] = ".temporary";
		bool flag = false;
		bool imflag = false;
		bool fflag = false;
		char temp[3] = "a";
		char temp1[3] = "na";
		char tempdata1[3] = "na";
		fstream fname, fname1;
		fname.open(name, ios::in);
		fname1.open(name1, ios::out);
		string line;
		int r = 0;
		while (!fname.eof())
		{
			flag = false;
			getline(fname, line);
			int i = 0;

			for (int j = 0; j < 1; j++)
			{
				if (line[i] == ':')
					i++;
				else
				{
					int k = 0;
					char finput[10] = "";
					while (line[i] != ':')
					{
						finput[k] = line[i];
						i++;
						k++;
					}
					if (compare(finput, id) == 1)
					{
						fname1 << endl;
						flag = true;
						fflag = true;
						int i1 = 0;
						for (int j1 = 0; j1 < nc; j1++)
						{
							if (line[i1] == ':')
								i1++;
							else
							{
								int k1 = 0;
								char finput1[10] = "";
								while (line[i1] != ':')
								{
									finput1[k1] = line[i1];
									i1++;
									k1++;
								}
								if (compare(finput1, temp) == 1)
								{
									flag = true;
									imflag = true;
									fname1 << tempdata1 << ":";
								}
								else
								{
									fname1 << finput1 << ":";
								}
							}
						}
					}
				}
			}
			if (flag == false)
			{
				if (r == 0)
				{
					fname1 << line;
				}
				else
				{
					fname1 << endl
						   << line;
				}
			}
			r++;
		}
		fname.close();
		fname1.close();
		if (fflag == true)
		{
			if (imflag == true)
			{
				system("clear");
				cout << "\t--------------------------" << endl;
				cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
				cout << "\t--------------------------" << endl
					 << endl
					 << endl;
				findcust(name, id, nc);
				int n;
			label1:
				cout << endl
					 << "\t1. Continue" << endl;
				cout << "\t2. Cancel" << endl
					 << endl;
				cout << "\tEnter number of your choice : ";
				cin >> n;
				if (n == 1)
				{
					fname.open(name, ios::out);
					fname1.open(name1, ios::in);
					int i = 0;
					while (!fname1.eof())
					{
						getline(fname1, line);
						if (i == 0)
						{
							fname << line;
						}
						else
							fname << endl
								  << line;
						i++;
					}
					fname.close();
					fname1.close();
					fname1.open(name1, ios::out);
					fname1.close();
					system("clear");
					cout << "\t--------------------------" << endl;
					cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
					cout << "\t--------------------------" << endl
						 << endl
						 << endl;
					cout << endl
						 << "\tRecord Updated Successfully !!!" << endl;
				}
				else
				{
					if (n == 2)
					{
						fname1.close();
						system("clear");
						cout << "\t--------------------------" << endl;
						cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
						cout << "\t--------------------------" << endl
							 << endl
							 << endl;
						cout << endl
							 << "\tCancelled !!!" << endl;
					}
					else
					{
						cout << endl
							 << "\tInvalid Input" << endl;
						goto label1;
					}
				}
			}
			else
			{
				system("clear");
				cout << "\t--------------------------" << endl;
				cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
				cout << "\t--------------------------" << endl
					 << endl
					 << endl;
				find(name, id, nc);
				cout << endl
					 << "\tRecord already removed" << endl;
				fname1.open(name1, ios::out);
				fname1.close();
			}
		}
		else
		{
			system("clear");
			cout << "\t--------------------------" << endl;
			cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
			cout << "\t--------------------------" << endl
				 << endl
				 << endl;
			cout << "\tRecord Not Found !!!" << endl;
			fname1.open(name1, ios::out);
			fname1.close();
		}
	}
	void updatebalanceincust(char id[], int nc, float bal)
	{
		char name[10] = ".cust";
		char name1[11] = ".temporary";
		bool flag = false;
		bool imflag = false;
		bool fflag = false;
		fstream fname, fname1;
		fname.open(name, ios::in);
		fname1.open(name1, ios::out);
		string line;
		int r = 0;
		while (!fname.eof())
		{
			flag = false;
			getline(fname, line);
			int i = 0;

			for (int j = 0; j < 1; j++)
			{
				if (line[i] == ':')
					i++;
				else
				{
					int k = 0;
					char finput[10] = "";
					while (line[i] != ':')
					{
						finput[k] = line[i];
						i++;
						k++;
					}
					if (compare(finput, id) == 1)
					{
						fname1 << endl;
						flag = true;
						fflag = true;
						int i1 = 0;
						for (int j1 = 0; j1 < nc; j1++)
						{
							if (line[i1] == ':')
								i1++;
							else
							{
								int k1 = 0;
								char finput1[10] = "";
								while (line[i1] != ':')
								{
									finput1[k1] = line[i1];
									i1++;
									k1++;
								}
								if (j1 == 12)
								{
									flag = true;
									imflag = true;
									fname1 << bal << ":";
								}
								else
								{
									fname1 << finput1 << ":";
								}
							}
						}
					}
				}
			}
			if (flag == false)
			{
				if (r == 0)
				{
					fname1 << line;
				}
				else
				{
					fname1 << endl
						   << line;
				}
			}
			r++;
		}
		fname.close();
		fname1.close();

		fname.open(name, ios::out);
		fname1.open(name1, ios::in);
		int i = 0;
		while (!fname1.eof())
		{
			getline(fname1, line);
			if (i == 0)
			{
				fname << line;
			}
			else
				fname << endl
					  << line;
			i++;
		}
		fname.close();
		fname1.close();
		fname1.open(name1, ios::out);
		fname1.close();
	}
};
class admin : forall //for admin login;
{
	char name[10] = ".admin";
	char aid[10];
	char fname[10];
	char lname[10];
	char apass[10];
	int nc = 7;
	bool aflag = false;

public:
	admin()
	{
		system("clear");
		fstream af;
		af.open(".admin", ios::out);
		af << "aid:pass:fname:lname:" << endl;
		af << "1:1234:Super:User:" << endl;
		af.close();
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t       Admin Login" << endl
			 << endl;
		cout << "\tBy default, id=1 & password=1234" << endl
			 << endl;
	label1:
		cout << "\tAdmin id : ";
		cin >> aid;
		cout << "\tPassword : ";
		cin >> apass;
		int x = avalidate(name, aid, apass, nc); //name,id,pass,nc
		if (x == 0)
		{
			cout << "\t  Invalid id or password" << endl
				 << endl;
			goto label1;
		}
		else
		{
			aflag = true;
			adminloggedin();
		}
	}
	void adminloggedin() //after admin logged in screen;
	{
		int n;
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Admin Logged in" << endl
			 << endl;
		cout << "\t1. Staff Database" << endl;
		cout << "\t2. Customer Database" << endl;
		cout << "\t3. Transaction Database" << endl;
		cout << "\t4. Logout" << endl;
		cout << "\t5. EXIT" << endl;
	//cout<<"\t4. Backup File System"<<endl;
	label1:
		cout << endl
			 << "\tEnter number of your choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedinstaff();
			break;
		case 2:
			adminloggedincust();
			break;
		case 3:
			adminloggedintrans();
			break;
		case 4:
			aflag = false;
			system("clear");
			startpage();
			break;
		case 5:
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void adminloggedinstaff()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t      Staff Database" << endl
			 << endl;
		cout << "\t1. Hire Staff" << endl;
		cout << "\t2. Remove Staff" << endl;
		cout << "\t3. Show Staff Database" << endl;
		cout << "\t4. BACK" << endl;
		cout << "\t5. LOGOUT" << endl;
		cout << "\t6. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			hirestaff();
			break;
		case 2:
			removestaff();
			break;
		case 3:
			staffdata();
			break;
		case 4:
			adminloggedin();
			break;
		case 5:
			system("clear");
			aflag = false;
			startpage();
			break;
		case 6:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void hirestaff()
	{
		system("clear");
		int sid;
		char pass[10];
		char fname[10];
		char lname[10];
		char ana[3] = "a";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Hire Staff" << endl
			 << endl;
		cout << "\tEnter First Name : ";
		cin >> fname;
		cout << endl
			 << "\tEnter Last Name : ";
		cin >> lname;
		cout << endl
			 << "\tEnter Password : ";
		cin >> pass;
		//reading no of staffs available
		int n;
		fstream snf;
		snf.open(".noofstaff", ios::in);
		while (!snf.eof())
		{
			snf >> n;
		}
		snf.close();
		sid = n + 1;
		//reading completed
		//writting to staff file
		n = n + 1;
		snf.open(".noofstaff", ios::out);
		snf << n;
		snf.close();
		//writting completed
		fstream sf;
		sf.open(".staff", ios::app);
		sf << endl
		   << sid << ":" << pass << ":" << fname << ":" << lname << ":" << ana << ":";
		sf.close();
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Hire Staff" << endl
			 << endl;
		cout << "\tRecord Added Successfully !!!" << endl;
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			adminloggedinstaff();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void removestaff()
	{
		system("clear");
		char name[10] = ".staff";
		char id[10];
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Remove Staff" << endl
			 << endl;
		cout << "\tEnter Staff id : ";
		cin >> id;
		nc = 9;
		remove(name, id, nc);
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			adminloggedinstaff();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void staffdata()
	{
		system("clear");
		nc = 9;
		char sname[10] = ".staff";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Staff Database" << endl
			 << endl;
		show(sname, nc);
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedinstaff();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void adminloggedincust()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Customer Database" << endl
			 << endl;
		cout << "\t1. Find a Customer" << endl;
		cout << "\t2. Show Customer Database" << endl;
		cout << "\t3. BACK" << endl;
		cout << "\t4. LOGOUT" << endl;
		cout << "\t5. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		char name1[6] = ".cust";
		switch (n)
		{
		case 1:
			admincustfindfunction(name1);
			break;
		case 2:
			custdata();
			break;
		case 3:
			adminloggedin();
			break;
		case 4:
			system("clear");
			aflag = false;
			startpage();
			break;
		case 5:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void admincustfindfunction(char name[])
	{
		system("clear");
		nc = 15;
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Find a Customer" << endl
			 << endl;
		cout << "\tEnter customer id : ";
		char id[10];
		cin >> id;
		cout << endl;
		find(name, id, nc); //name,id,nc
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedincust();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void custdata()
	{
		system("clear");
		nc = 17;
		char cname[10] = ".cust";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Customer Database" << endl
			 << endl;
		show(cname, nc);
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedincust();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void adminloggedintrans()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Transaction Database" << endl
			 << endl;
		cout << "\t1. Find a Transaction" << endl;
		cout << "\t2. Show Transaction Database" << endl;
		cout << "\t3. BACK" << endl;
		cout << "\t4. LOGOUT" << endl;
		cout << "\t5. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		char name1[7] = ".trans";
		switch (n)
		{
		case 1:
			admintransfindfunction(name1);
			break;
		case 2:
			transactiondata();
			break;
		case 3:
			adminloggedin();
			break;
		case 4:
			system("clear");
			aflag = false;
			startpage();
			break;
		case 5:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void admintransfindfunction(char name[])
	{
		system("clear");
		nc = 11;
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Find a Transaction" << endl
			 << endl;
		cout << "\tEnter transaction id : ";
		char id[10];
		cin >> id;
		cout << endl;
		find(name, id, nc); //name,id,nc
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedintrans();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void transactiondata()
	{
		system("clear");
		nc = 11;
		char tname[10] = ".trans";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Transaction Database" << endl
			 << endl;
		show(tname, nc);
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			adminloggedintrans();
			break;
		case 2:
			aflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			aflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	~admin() {}
};
class staff : forall
{
	char name[10] = ".staff";
	char sid[10];
	char fname[10];
	char lname[10];
	char spass[10];
	int nc = 9;
	bool sflag = false;

public:
	staff()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Staff Login" << endl
			 << endl;
		cout << "\tBy default, id=101 & password=1234" << endl
			 << endl;
	label1:
		cout << "\tStaff id : ";
		cin >> sid;
		cout << "\tPassword : ";
		cin >> spass;
		int x = validate(name, sid, spass, nc); //name,id,pass,nc
		if (x == 0)
		{
			cout << "\t  Invalid id or password" << endl
				 << endl;
			goto label1;
		}
		else
		{
			sflag = true;
			staffloggedin();
		}
	}
	~staff() {}
	void staffloggedin() //after staff logged in screen;
	{
		int n;
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Staff Logged in" << endl
			 << endl;
		cout << "\t1. Create New Account" << endl;
		cout << "\t2. Close Existing Account" << endl;
		cout << "\t3. Deposit Cash" << endl;
		cout << "\t4. Withdraw Cash" << endl;
		cout << "\t5. Check Balance" << endl;
		cout << "\t6. Transfer Money" << endl;
		cout << "\t7. Transaction History" << endl;
		cout << "\t8. Logout" << endl;
		cout << "\t9. EXIT" << endl;
	label1:
		cout << endl
			 << "\tEnter number of your choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			addcust();
			break;
		case 2:
			removecust();
			break;
		case 3:
			depositcash();
			break;
		case 4:
			withdrawcash();
			break;
		case 5:
			checkbalance();
			break;
		case 6:
			transfer();
			break;
		case 7:
			transhistory();
			break;
		case 8:
			sflag = false;
			system("clear");
			startpage();
			break;
		case 9:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void addcust()
	{
		system("clear");
		int cid;
		int accno;
		char pass[10];
		char fname[10];
		char lname[10];
		char ana[3] = "a";
		float bal = 0.0;
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t   Create New Account" << endl
			 << endl;
		cout << "\tEnter First Name : ";
		cin >> fname;
		cout << endl
			 << "\tEnter Last Name : ";
		cin >> lname;
		cout << endl
			 << "\tEnter Password : ";
		cin >> pass;
		//reading no of customer available
		int n;
		fstream cnf;
		cnf.open(".noofcust", ios::in);
		while (!cnf.eof())
		{
			cnf >> n;
		}
		cnf.close();
		cid = n + 1;
		accno = 100000 + cid;
		//reading completed
		//writting to cust file
		n = n + 1;
		cnf.open(".noofcust", ios::out);
		cnf << n;
		cnf.close();
		//writting completed
		//creating balance file and pcf
		char temp[10];
		cnf.open(".noofcust", ios::in);
		while (!cnf.eof())
		{
			cnf >> temp;
		}
		cnf.close();
		fstream bf;
		char temp1[15] = ".";
		char temp2[10] = "bal";
		strcat(temp1, temp);
		bf.open(temp1, ios::out);
		bf << "tid:amount:from:to:c/d/t:sid/cid:";
		bf.close();
		strcat(temp1, temp2);
		bf.open(temp1, ios::out);
		bf << "0.0";
		bf.close();
		//created
		fstream sf;
		sf.open(".cust", ios::app);
		sf << endl
		   << cid << ":" << pass << ":" << accno << ":" << fname << ":" << lname << ":" << ana << ":" << bal << ":" << sid << ":"
		   << "saving"
		   << ":";
		sf.close();
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     New Account Created" << endl
			 << endl;
		cout << "\tRecord Added Successfully !!!" << endl;
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void removecust()
	{
		system("clear");
		char name[10] = ".cust";
		char id[10];
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Close Account" << endl
			 << endl;
		cout << "\tEnter Customer id : ";
		cin >> id;
		nc = 17;
		removec(name, id, nc);
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void depositcash()
	{
		system("clear");
		char id[10];
		nc = 17;
		char name[10] = ".cust";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Deposit Cash" << endl
			 << endl;
		cout << "\tEnter Customer id : ";
		cin >> id;
		int amount;
		int x = checka(name, id, nc);
		if (x == -1)
		{
			cout << endl
				 << "\tRecord Not Found!!!" << endl;
		}
		else
		{
			if (x == 0)
			{
				cout << endl
					 << "\tSorry but this account has been closed !!!" << endl;
			}
			else
			{
				if (x == 1)
				{
					cout << endl
						 << "\tEnter Amount : ";
					cin >> amount;
					char temp[15] = ".";
					char temp1[15];
					float bal;
					strcat(temp, id);
					strcpy(temp1, temp);
					strcat(temp, "bal");
					fstream balfile;
					balfile.open(temp, ios::in);
					balfile >> bal;
					balfile.close();
					bal = bal + amount;
					balfile.open(temp, ios::out);
					balfile << bal;
					balfile.close();
					char mode[10] = "credit";
					updatebalance(id, id, amount, temp1, mode);
					nc = 17;
					updatebalanceincust(id, nc, bal);
					cout << "\tRecord Updated Successfully !!!" << endl;
				}
				else
				{
					cout << endl
						 << "\tSome problem detected!!!" << endl;
				}
			}
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void updatebalance(char id1[], char id2[], int amount, char temp1[], char mode[])
	{
		//reading no of transaction available
		int nt;
		fstream cnf;
		cnf.open(".nooftrans", ios::in);
		while (!cnf.eof())
		{
			cnf >> nt;
		}
		cnf.close();
		int tid;
		tid = nt + 1;
		//reading completed
		//writting to trans file
		nt = nt + 1;
		cnf.open(".nooftrans", ios::out);
		cnf << nt;
		cnf.close();
		//writting completed
		fstream file1, file2;
		file1.open(".trans", ios::app);
		file2.open(temp1, ios::app);
		file1 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << sid << ":";
		file2 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << sid << ":";
		file1.close();
		file2.close();
	}
	void withdrawcash()
	{
		system("clear");
		char id[10];
		nc = 17;
		char name[10] = ".cust";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Withdraw Cash" << endl
			 << endl;
		cout << "\tEnter Customer id : ";
		cin >> id;
		int amount;
		int x = checka(name, id, nc);
		if (x == -1)
		{
			cout << endl
				 << "\tRecord Not Found!!!" << endl;
		}
		else
		{
			if (x == 0)
			{
				cout << endl
					 << "\tSorry but this account has been closed !!!" << endl;
			}
			else
			{
				if (x == 1)
				{
					cout << endl
						 << "\tEnter Amount : ";
					cin >> amount;
					char temp[15] = ".";
					char temp1[15];
					float bal;
					strcat(temp, id);
					strcpy(temp1, temp);
					strcat(temp, "bal");
					fstream balfile;
					balfile.open(temp, ios::in);
					balfile >> bal;
					balfile.close();
					if (amount > bal)
					{
						cout << endl
							 << "\tInsufficient Balance!!!" << endl;
					}
					else
					{
						bal = bal - amount;
						balfile.open(temp, ios::out);
						balfile << bal;
						balfile.close();
						char mode[10] = "debit";
						updatebalance(id, id, amount, temp1, mode);
						nc = 17;
						updatebalanceincust(id, nc, bal);
						cout << "\tRecord Updated Successfully !!!" << endl;
					}
				}
				else
				{
					cout << endl
						 << "\tSome problem detected!!!" << endl;
				}
			}
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void checkbalance()
	{
		system("clear");
		char id[10];
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Check Balance" << endl
			 << endl;
		cout << "\tEnter Customer id : ";
		cin >> id;
		char temp1[15] = ".";
		char temp2[10] = "bal";
		strcat(temp1, id);
		strcat(temp1, temp2);
		float bal;
		fstream sf;
		sf.open(temp1, ios::in);
		if (!sf)
		{
			cout << endl
				 << "\tRecord not found." << endl;
			sf.close();
		}
		else
		{
			sf >> bal;
			sf.close();
			system("clear");
			cout << "\t--------------------------" << endl;
			cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
			cout << "\t--------------------------" << endl
				 << endl;
			cout << "\t    Balanced Checked" << endl
				 << endl;
			cout << "\tCustomer id : " << id << endl;
			cout << "\tBalance : " << bal << endl;
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void transfer()
	{
		system("clear");
		char id1[10];
		char id2[10];
		nc = 17;
		char name[10] = ".cust";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t   Transfer Money" << endl
			 << endl;
		cout << endl
			 << "\tEnter Sender Customer id : ";
		cin >> id1;
		int amount;
		int x = checka(name, id1, nc);
		if (x == -1)
		{
			cout << endl
				 << "\tSender Record Not Found!!!" << endl;
		}
		else
		{
			if (x == 0)
			{
				cout << endl
					 << "\tSorry but this account has been closed !!!" << endl;
			}
			else
			{
				if (x == 1)
				{
					cout << endl
						 << "\tEnter Receiver Customer id : ";
					cin >> id2;
					int y = checka(name, id2, nc);
					if (y == -1)
					{
						cout << endl
							 << "\tReceiver Record Not Found!!!" << endl;
					}
					else
					{
						if (y == 0)
						{
							cout << endl
								 << "\tSorry but this account has been closed !!!" << endl;
						}
						else
						{
							if (y == 1)
							{
								cout << endl
									 << "\tEnter Amount : ";
								cin >> amount;
								float bal1;
								char temp[15] = ".";
								char temp1[15];
								char temp2[15] = ".";
								char temp3[15];
								float bal2;
								strcat(temp, id1);
								strcpy(temp1, temp);
								strcat(temp, "bal");
								strcat(temp2, id2);
								strcpy(temp3, temp2);
								strcat(temp2, "bal");
								fstream balfile1;
								balfile1.open(temp, ios::in);
								balfile1 >> bal1;
								balfile1.close();
								if (amount > bal1)
								{
									cout << endl
										 << "\tInsufficient Balance!!!" << endl;
								}
								else
								{
									fstream balfile2;
									balfile1.open(temp, ios::in);
									balfile2.open(temp2, ios::in);
									balfile1 >> bal1;
									balfile2 >> bal2;
									balfile1.close();
									balfile2.close();
									bal1 = bal1 - amount;
									bal2 = bal2 + amount;
									balfile1.open(temp, ios::out);
									balfile2.open(temp2, ios::out);
									balfile1 << bal1;
									balfile2 << bal2;
									balfile1.close();
									balfile2.close();
									char mode[10] = "transfer";
									updatebalancetransfer(id1, id2, amount, temp1, temp3, mode);
									nc = 17;
									updatebalanceincust(id1, nc, bal1);
									updatebalanceincust(id2, nc, bal2);
									cout << "\tRecord Updated Successfully !!!" << endl;
								}
							}
							else
							{
								cout << endl
									 << "\tSome problem detected!!!" << endl;
							}
						}
					}
				}
				else
				{
					cout << endl
						 << "\tSome problem detected!!!" << endl;
				}
			}
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void updatebalancetransfer(char id1[], char id2[], int amount, char temp1[], char temp3[], char mode[])
	{
		//reading no of transaction available
		int nt;
		fstream cnf;
		cnf.open(".nooftrans", ios::in);
		while (!cnf.eof())
		{
			cnf >> nt;
		}
		cnf.close();
		int tid;
		tid = nt + 1;
		//reading completed
		//writting to trans file
		nt = nt + 1;
		cnf.open(".nooftrans", ios::out);
		cnf << nt;
		cnf.close();
		//writting completed
		fstream file1, file2, file3;
		file1.open(".trans", ios::app);
		file2.open(temp1, ios::app);
		file3.open(temp3, ios::app);
		file1 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << sid << ":";
		file2 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << sid << ":";
		file3 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << sid << ":";
		file1.close();
		file2.close();
		file3.close();
	}
	void transhistory()
	{
		system("clear");
		nc = 11;
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Transaction History" << endl
			 << endl;
		cout << "\tEnter Customer id : ";
		char name[10];
		cin >> name;
		char name1[11] = ".";
		strcat(name1, name);
		fstream sf;
		sf.open(name1, ios::in);
		if (!sf)
		{
			cout << endl
				 << "\tRecord not found." << endl;
			sf.close();
		}
		else
		{
			system("clear");
			cout << "\t--------------------------" << endl;
			cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
			cout << "\t--------------------------" << endl
				 << endl;
			cout << "\t   Transaction History of " << name << endl
				 << endl;
			show(name1, nc);
			sf.close();
		}
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			staffloggedin();
			break;
		case 2:
			sflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			sflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
};
class customer : forall
{
	char name[10] = ".cust";
	char cid[10];
	char fname[10];
	char lname[10];
	char cpass[10];
	int nc = 17;
	bool cflag = false;

public:
	customer()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Customer Login" << endl
			 << endl;
		cout << "\tBy default, id=1001 & password=1234" << endl
			 << endl;
	label1:
		cout << "\tCustomer id : ";
		cin >> cid;
		cout << "\tPassword : ";
		cin >> cpass;
		int x = validate(name, cid, cpass, nc); //name,id,pass,nc
		if (x == 0)
		{
			cout << "\t  Invalid id or password" << endl
				 << endl;
			goto label1;
		}
		else
		{
			cflag = true;
			custloggedin();
		}
	}
	~customer() {}
	void custloggedin() //after customer logged in screen;
	{
		int n;
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Customer Logged In" << endl
			 << endl;
		cout << "\t1. Check Balance" << endl;
		cout << "\t2. Transfer Money" << endl;
		cout << "\t3. Transaction History" << endl;
		cout << "\t4. Logout" << endl;
		cout << "\t5. EXIT" << endl;
	label1:
		cout << endl
			 << "\tEnter number of your choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			checkbal();
			break;
		case 2:
			ctransfer();
			break;
		case 3:
			ctranshistory();
			break;
		case 4:
			cflag = false;
			system("clear");
			startpage();
			break;
		case 5:
			system("clear");
			cflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void checkbal()
	{
		system("clear");
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t     Check Balance" << endl
			 << endl;
		char temp1[15] = ".";
		char temp2[10] = "bal";
		strcat(temp1, cid);
		strcat(temp1, temp2);
		float bal;
		fstream sf;
		sf.open(temp1, ios::in);
		if (!sf)
		{
			cout << endl
				 << "\tSome Error Detected!!!" << endl;
			sf.close();
		}
		else
		{
			sf >> bal;
			sf.close();
			system("clear");
			cout << "\t--------------------------" << endl;
			cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
			cout << "\t--------------------------" << endl
				 << endl
				 << endl;
			cout << "\tCustomer id : " << cid << endl;
			cout << "\tBalance : " << bal << endl;
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			custloggedin();
			break;
		case 2:
			cflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			cflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void ctransfer()
	{
		system("clear");
		char id2[10];
		nc = 17;
		char name[10] = ".cust";
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Transfer Money" << endl
			 << endl;
		int amount;
		int x = checka(name, cid, nc);
		if (x == -1)
		{
			cout << endl
				 << "\tSender Record Not Found!!!" << endl;
		}
		else
		{
			if (x == 0)
			{
				cout << endl
					 << "\tSorry but this account has been closed !!!" << endl;
			}
			else
			{
				if (x == 1)
				{
					cout << endl
						 << "\tEnter Receiver Customer id : ";
					cin >> id2;
					if (compare(id2, cid) == 1)
					{
						cout << endl
							 << "\tYou can not trnasfer money to yourself!!!" << endl;
					}
					else
					{
						int y = checka(name, id2, nc);
						if (y == -1)
						{
							cout << endl
								 << "\tReceiver Record Not Found!!!" << endl;
						}
						else
						{
							if (y == 0)
							{
								cout << endl
									 << "\tSorry but this account has been closed !!!" << endl;
							}
							else
							{
								if (y == 1)
								{
									cout << endl
										 << "\tEnter Amount : ";
									cin >> amount;
									float bal1;
									char temp[15] = ".";
									char temp1[15];
									char temp2[15] = ".";
									char temp3[15];
									float bal2;
									strcat(temp, cid);
									strcpy(temp1, temp);
									strcat(temp, "bal");
									strcat(temp2, id2);
									strcpy(temp3, temp2);
									strcat(temp2, "bal");
									fstream balfile1;
									balfile1.open(temp, ios::in);
									balfile1 >> bal1;
									balfile1.close();
									if (amount > bal1)
									{
										cout << endl
											 << "\tInsufficient Balance!!!" << endl;
									}
									else
									{
										fstream balfile2;
										balfile1.open(temp, ios::in);
										balfile2.open(temp2, ios::in);
										balfile1 >> bal1;
										balfile2 >> bal2;
										balfile1.close();
										balfile2.close();
										bal1 = bal1 - amount;
										bal2 = bal2 + amount;
										balfile1.open(temp, ios::out);
										balfile2.open(temp2, ios::out);
										balfile1 << bal1;
										balfile2 << bal2;
										balfile1.close();
										balfile2.close();
										char mode[10] = "transfer";
										cupdatebalancetransfer(cid, id2, amount, temp1, temp3, mode);
										nc = 17;
										updatebalanceincust(cid, nc, bal1);
										updatebalanceincust(id2, nc, bal2);
										cout << "\tRecord Updated Successfully !!!" << endl;
									}
								}
								else
								{
									cout << endl
										 << "\tSome problem detected!!!" << endl;
								}
							}
						}
					}
				}
				else
				{
					cout << endl
						 << "\tSome problem detected!!!" << endl;
				}
			}
		}
		cout << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n1;
	label1:
		cout << "\tEnter number of your choice : ";
		cin >> n1;
		switch (n1)
		{
		case 1:
			custloggedin();
			break;
		case 2:
			cflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			cflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
	void cupdatebalancetransfer(char id1[], char id2[], int amount, char temp1[], char temp3[], char mode[])
	{
		//reading no of transaction available
		int nt;
		fstream cnf;
		cnf.open(".nooftrans", ios::in);
		while (!cnf.eof())
		{
			cnf >> nt;
		}
		cnf.close();
		int tid;
		tid = nt + 1;
		//reading completed
		//writting to trans file
		nt = nt + 1;
		cnf.open(".nooftrans", ios::out);
		cnf << nt;
		cnf.close();
		//writting completed
		fstream file1, file2, file3;
		file1.open(".trans", ios::app);
		file2.open(temp1, ios::app);
		file3.open(temp3, ios::app);
		file1 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << cid << ":";
		file2 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << cid << ":";
		file3 << endl
			  << tid << ":" << amount << ":" << id1 << ":" << id2 << ":" << mode << ":" << cid << ":";
		file1.close();
		file2.close();
		file3.close();
	}
	void ctranshistory()
	{
		system("clear");
		nc = 11;
		cout << "\t--------------------------" << endl;
		cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
		cout << "\t--------------------------" << endl
			 << endl;
		cout << "\t    Transaction History" << endl
			 << endl;
		char name1[11] = ".";
		strcat(name1, cid);
		show(name1, nc);
		cout << endl
			 << endl
			 << "\t1. BACK" << endl;
		cout << "\t2. LOGOUT" << endl;
		cout << "\t3. EXIT" << endl
			 << endl;
		int n;
	label1:
		cout << "\tEnter number of four choice : ";
		cin >> n;
		switch (n)
		{
		case 1:
			custloggedin();
			break;
		case 2:
			cflag = false;
			system("clear");
			startpage();
		case 3:
			system("clear");
			cflag = false;
			system("exit");
			break;
		default:
			cout << "\tInvalid input" << endl;
			goto label1;
		}
	}
};
int main()
{
	system("clear");
	startpage();
	return 0;
}
void startpage() //start page of programme
{
	cout << "\t--------------------------" << endl;
	cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
	cout << "\t--------------------------" << endl
		 << endl
		 << endl;
	cout << "\t1. LOGIN" << endl;
	cout << "\t2. EXIT" << endl
		 << endl;
label1:
	cout << "\tEnter number of your choice : ";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		loginpage();
		break;
	case 2:
		system("exit");
		break;
	default:
		cout << "\tInvalid input" << endl;
		goto label1;
	}
}
void loginpage()
{
	system("clear");
	cout << "\t--------------------------" << endl;
	cout << "\t  BANK MANAGEMENT SYSTEM" << endl;
	cout << "\t--------------------------" << endl
		 << endl;
	cout << "\t       LOGIN" << endl
		 << endl;
	cout << "\t1. ADMIN" << endl;
	cout << "\t2. STAFF" << endl;
	cout << "\t3. CUSTOMER" << endl;
	cout << "\t4. BACK" << endl;
	cout << "\t5. EXIT" << endl
		 << endl;
label1:
	cout << "\tEnter number of your choice : ";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		adminlogin();
		break;
	case 2:
		stafflogin();
		break;
	case 3:
		customerlogin();
		break;
	case 4:
		startpage();
		break;
	case 5:
		system("exit");
		break;
	default:
		cout << "\tInvalid input" << endl;
		goto label1;
	}
}
void adminlogin()
{
	admin a;
}
void stafflogin()
{
	staff s;
}
void customerlogin()
{
	customer c;
}

// Programme Ends Here.