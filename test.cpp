// Ludo Snake Game
// This code is Written by
// Engr. Rashid Farid Chishti
// You are allowed to Use and Share this code with others

#include <iostream>  // for cin and cout
#include <iomanip>
#include <stdlib.h>  // for rand(), srand() and system
#include <stdio.h>
#include <time.h>    // for time()
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
class Dice {
private:
	int number;
public:
	Dice() {
		number = 1;
		srand(time(0));
	}
	int roll() {
		number = rand() % 6 + 1;
		return number;
	}
	int get_number() {
		return number;
	}
	void set_number(int n) {
		number = n;
	}
int display(int a)
{
//	PlaySound(TEXT("ladder"),NULL, SND_FILENAME);
if(a==1)
{
cout << " ----- " << endl;
cout << "|     |" << endl;
cout << "|  O  |" << endl;
cout << "|     |" << endl;
cout <<  " -----" << endl;
}
else if(a==2)
{
cout << " -----" << endl;
cout << "|    O|" << endl;
cout << "|     |" << endl;
cout << "|O    |" << endl;
cout <<  " -----" << endl;
}
else if(a==3)
{
cout << " -----" << endl;
cout << "|    O|" << endl;
cout << "|  O  |" << endl;
cout << "|O    |" << endl;
cout <<  " -----" << endl;
}
else if(a==4)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|     |" << endl;
cout << "|O   O|" << endl;
cout <<  " -----" << endl;
}
else if(a==5)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|  O  |" << endl;
cout << "|O   O|" << endl;
cout <<  " -----" << endl;
}
else if(a==6)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|O   O|" << endl;
cout << "|O   O|" << endl;
cout <<  "-----" << endl;
}
}
};
class Node
{
public:
int data;
Node *next;
Node()
{
this->data = data;
next = NULL;
}
};

class list
{
Node *head, *tail,*current;
public:
list()
{
head = NULL;
tail = NULL;
}
void add_link(int num)
{
Node *temp = new Node;
temp->data = num;
temp->next = NULL;
if(head==NULL)
{
head = temp;
tail = temp;
}
else{
tail->next = temp;
tail = temp;
tail->next = NULL;
}
}
void display()
{
current = head;
if(current==NULL)

{
cout << "NO ELEMENT" << endl;
}
else{
int i = 1;
cout << "Element in List" << endl;
while (current != NULL)
{
cout <<current->data << endl;
current = current->next;
++i;
}
}
}
};


class Grid {
private:
	char p1[100];
	char p2[100];
	//string snakes[2000];	//composition
public:
	Grid(){
	char p1[100];
	char p2[100];
}
void Draw(){
	system("CLS");
cout << " ______________________________________________________________________" << endl;
cout << "|  " << "100  " << "|  " << "99  " << "|  " << "98  "  << "|  " << "97  " << "|  " << "96  " << "|  " << "95  " << "|  " << "94  " << "|  " << "93  " << "|  " << "92  " << "|  " << "91  |" <<endl;
cout << "|"  << "   " <<  p1[100] << p2[100]  << "  |" << "   " <<  p1[99] << p2[99]  << " |"  << "   " <<  p1[98] << p2[98]  << " |"  << "   " <<  p1[97] << p2[97]  << " |" << "     " <<  p1[96] << p2[96]  << " |"  << "   " <<  p1[95] << p2[95] << " |"  << "   " <<  p1[94] << p2[94]<< " |"  << "   " <<  p1[93] << p2[93]<< " |"  << "   " <<  p1[92] << p2[92] << " |" << "   " <<  p1[91] << p2[91] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "81   " << "|  " << "82  " << "|  " << "83  "  << "|  " << "84  " << "|  " << "85  " << "|  " << "86  " << "|  " << "87  " << "|  " << "88  " << "|  " << "89  " << "|  " << "90  |" <<endl;
cout << "|"   << " " <<  p1[81] << p2[81]  << "  |"  << " " <<  p1[82] << p2[82]  << " |"  << " " <<  p1[83] << p2[83]  << " |"  << " " <<  p1[84] << p2[84]  << " |"  << " " <<  p1[85] << p2[85]  << " |"  << " " <<  p1[86] << p2[86] << " |"  << " " <<  p1[87] << p2[87]<< " |"  << " " <<  p1[88] << p2[88]<< " |"  << " " <<  p1[89] << p2[89] << " |"  << " " <<  p1[90] << p2[90] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "80   " << "|  " << "79  " << "|  " << "78  "  << "|  " << "77  " << "|  " << "76  " << "|  " << "75  " << "|  " << "74  " << "|  " << "73  " << "|  " << "72  " << "|  " << "71  |" <<endl;
cout << "|"   << " " <<  p1[80] << p2[80]  << "  |"   << " " <<  p1[79] << p2[79]  << " |"  << " " <<  p1[78] << p2[78]  << " |"   << " " <<  p1[77] << p2[77]  << " |"  << " " <<  p1[76] << p2[76]  << " |"  << " " <<  p1[75] << p2[75] << " |"  << " " <<  p1[74] << p2[74]<< " |" << " " <<  p1[73] << p2[73]<< " |"  << " " <<  p1[72] << p2[72] << " |"  << " " <<  p1[71] << p2[71] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "61   " << "|  " << "62  " << "|  " << "63  "  << "|  " << "64  " << "|  " << "65  " << "|  " << "66  " << "|  " << "67  " << "|  " << "68  " << "|  " << "69  " << "|  " << "70  |" <<endl;
cout << "|"  << " " <<  p1[61] << p2[61]  << "  |"   << " " <<  p1[62] << p2[62]  << " |"   << " " <<  p1[63] << p2[63]  << " |"  << " " <<  p1[64] << p2[64]  << " |"  << " " <<  p1[65] << p2[65]  << " |"  << " " <<  p1[66] << p2[66] << " |"  << " " <<  p1[67] << p2[67]<< " |"  << " " <<  p1[68] << p2[68]<< " |"  << " " <<  p1[69] << p2[69] << " |"  << " " <<  p1[70] << p2[70] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "60   " << "|  " << "59  " << "|  " << "58  "  << "|  " << "57  " << "|  " << "56  " << "|  " << "55  " << "|  " << "54  " << "|  " << "53  " << "|  " << "52  " << "|  " << "51  |" <<endl;
cout << "|"   << " " <<  p1[60] << p2[60]  << "  |"   << " " <<  p1[59] << p2[59]  << " |"   << " " <<  p1[58] << p2[58]  << " |"   << " " <<  p1[57] << p2[57]  << " |"  << " " <<  p1[56] << p2[56]  << " |"  << " " <<  p1[55] << p2[55] << " |"   << " " <<  p1[54] << p2[54]<< " |"  << " " <<  p1[53] << p2[53]<< " |"  << " " <<  p1[52] << p2[52] << " |"  << " " <<  p1[51] << p2[51] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "41   " << "|  " << "42  " << "|  " << "43  "  << "|  " << "44  " << "|  " << "45  " << "|  " << "46  " << "|  " << "47  " << "|  " << "48  " << "|  " << "49  " << "|  " << "50  |" <<endl;
cout << "|"  << " " <<  p1[41] << p2[41]  << "  |"   << " " <<  p1[42] << p2[42]  << " |"  << " " <<  p1[43] << p2[43]  << " |"  << " " <<  p1[44] << p2[44]  << " |"  << " " <<  p1[45] << p2[45]  << " |"  << " " <<  p1[46] << p2[46] << " |"  << " " <<  p1[47] << p2[47]<< " |"   << " " <<  p1[48] << p2[48]<< " |"  << " " <<  p1[49] << p2[49] << " |"  << " " <<  p1[50] << p2[50] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "40   " << "|  " << "39  " << "|  " << "38  "  << "|  " << "37  " << "|  " << "36  " << "|  " << "35  " << "|  " << "34  " << "|  " << "33  " << "|  " << "32  " << "|  " << "31  |" <<endl;
cout << "|"   << " " <<  p1[40] << p2[40]  << "  |"  << " " <<  p1[39] << p2[39]  << " |"   << " " <<  p1[38] << p2[38]  << " |"  << " " <<  p1[37] << p2[37]  << " |"  << " " <<  p1[36] << p2[36]  << " |"  << " " <<  p1[35] << p2[35] << " |"  << " " <<  p1[34] << p2[34]<< " |"  << " " <<  p1[33] << p2[33]<< " |"  << " " <<  p1[32] << p2[32] << " |"  << " " <<  p1[31] << p2[31] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "21   " << "|  " << "22  " << "|  " << "23  "  << "|  " << "24  " << "|  " << "25  " << "|  " << "26  " << "|  " << "27  " << "|  " << "28  " << "|  " << "29  " << "|  " << "30  |" <<endl;
cout << "|"  << " " <<  p1[21] << p2[21]  << "  |"  << " " <<  p1[22] << p2[22]  << " |" << " " <<  p1[23] << p2[23]  << " |" << " " <<  p1[24] << p2[24]  << " |"  << " " <<  p1[25] << p2[25]  << " |"  << " " <<  p1[26] << p2[26] << " |"  << " " <<  p1[27] << p2[27]<< " |"  << " " <<  p1[28] << p2[28]<< " |"  << " " <<  p1[29] << p2[29] << " |"  << " " <<  p1[30] << p2[30] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "20   " << "|  " << "19  " << "|  " << "18  "  << "|  " << "17  " << "|  " << "16  " << "|  " << "15  " << "|  " << "14  " << "|  " << "13  " << "|  " << "12  " << "|  " << "11  |" <<endl;
cout << "|"  << " " <<  p1[20] << p2[20]  << "  |"  << " " <<  p1[19] << p2[19]  << " |" << " " <<  p1[18] << p2[18]  << " |"  << " " <<  p1[17] << p2[17]  << " |"  << " " <<  p1[16] << p2[16]  << " |"  << " " <<  p1[15] << p2[15] << " |"   << " " <<  p1[14] << p2[14]<< " |"  << " " <<  p1[13] << p2[13]<< " |"  << " " <<  p1[12] << p2[12] << " |"  << " " <<  p1[11] << p2[11] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "1    " << "|  " << "2   " << "|  " << "3   "  << "|  " << "4   " << "|  " << "5   " << "|  " << "6   " << "|  " << "7   " << "|  " << "8   " << "|  " << "9   " << "|  " << "10  |" <<endl;
cout << "|"  << " " <<  p1[1] << p2[1]  << "  |"  << " " <<  p1[2] << p2[2]  << " |" <<   " " <<  p1[3] << p2[3]  << " |"  << " " <<  p1[4] << p2[4]  << " |"  << " " <<  p1[5] << p2[5]  << " |"  << " " <<  p1[6] << p2[6] << " |"  << " " <<  p1[7] << p2[7]<< " |" << " " <<  p1[8] << p2[8]<< " |"  << " " <<  p1[9] << p2[9] << " |"  << " " <<  p1[10] << p2[10] << " |";
cout << endl << " ----------------------------------------------------------------------" << endl;

}
};



class p1 {
public:
	char Name[80];
	int  Position;
	bool Blocked;
public:
	p1() {
		Name[0] = '\0';
		Position = 0;
		Blocked = true;
	}
	void Set_Name(char nm[])
	{
		strcpy(Name, nm);
	}
	void Get_Name()
	{
		cin>>Name;
		//cin.get(Name, 80);
		fflush(stdin);
	}
	void Show_Position() {
		cout << Position;   fflush(stdout); 
	}
	void Show_Name() {
		cout << Name;			fflush(stdout); 
	}

};

class Snake_Game
{
private:
	Grid g1;
	Dice d1;
	p1 P1;
	p1 P2;
public:
	void gotoxy(int col, int line) {
		COORD pos = { col, line };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}
	void Play() {
		
		HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 0x5F); 
		cout << "youtube.com/rfchishti" << endl ;
		SetConsoleTextAttribute(hConsole, 15); // White color
		cout << "Enter The Name of First p1: "; 
		fflush(stdout); 
		SetConsoleTextAttribute(hConsole, 12); // red color
		P1.Get_Name();
		SetConsoleTextAttribute(hConsole, 15); // White color
		//fflush(stdout); fflush(stdin);
		cout << "Enter The Name of 2nd p1: "; 
		SetConsoleTextAttribute(hConsole, 10); // green color
		fflush(stdout);
		P2.Get_Name();
		SetConsoleTextAttribute(hConsole, 15); // White color
		//fflush(stdout); fflush(stdin);
		bool First = true;
		while (1) {
			system("cls");
			g1.Draw();
			gotoxy(0, 21);
			
			SetConsoleTextAttribute(hConsole, 15); // White color
			cout << "P1: " ;
			SetConsoleTextAttribute(hConsole, 12); // red color
			
			cout << P1.Name << "                                  " << endl;
			gotoxy(0, 22);
			SetConsoleTextAttribute(hConsole, 15); // White color
			cout << "Position: " ;
			SetConsoleTextAttribute(hConsole, 12); // red color
			cout << setw(3) << P1.Position << "                                  " << endl;
			gotoxy(25, 21);
			
			SetConsoleTextAttribute(hConsole, 15); // White color
			cout << "P2: " ;
			SetConsoleTextAttribute(hConsole, 10); // green color
			cout << P2.Name << endl;
			gotoxy(25, 22);
			SetConsoleTextAttribute(hConsole, 15); // White color
			cout << "Position: " ;
			SetConsoleTextAttribute(hConsole, 10); // green color
			cout << setw(3) << P2.Position << endl;
			SetConsoleTextAttribute(hConsole, 15); // White color

			///////////  p1 1 ////////////////////////

			if (First) {
				
				First = !First;
				SetConsoleTextAttribute(hConsole, 15); // White color
				cout << "Now it is " ;
				SetConsoleTextAttribute(hConsole, 12); // red color
				cout << P1.Name ;
				SetConsoleTextAttribute(hConsole, 15); 
				cout << "'s Turn" << endl;
				fflush(stdout);
				while (1) {
					gotoxy(0, 24);
					SetConsoleTextAttribute(hConsole, 15); 
					cout << "Press ";
					SetConsoleTextAttribute(hConsole, 12); // Red color
					cout << "[1]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to throw a dice";
					if (getch() == '1')
						break;
				}
				cout << "\nYou Got: ";
				SetConsoleTextAttribute(hConsole, 12); // Red color
				cout << d1.roll();
				SetConsoleTextAttribute(hConsole, 15); // White color
				
				if (d1.get_number() == 6 && P1.Blocked){
						d1.set_number(1);
						P1.Blocked = false;
				}
				if (P1.Blocked)
					cout << " You Can Not Move " << endl;
				
				
				else if (!P1.Blocked)
				{
					int Position1,Position2;
					Position1 = P1.Position;
					Position2 = Move(1, d1.get_number());
					
					if (Position1 == Position2)  {
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " You are Stopped at " ;
						SetConsoleTextAttribute(hConsole, 12); // Red color
						cout << Position2;
					}
					else {
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " You Moved from " ;
						SetConsoleTextAttribute(hConsole, 12); // Red color
						cout << Position1;
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " to ";
						SetConsoleTextAttribute(hConsole, 12); // Red color
						cout << Position2 << endl;
					}
					if (P1.Position == 100){
						SetConsoleTextAttribute(hConsole, 12); // Red color
						cout << P1.Name ;
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " is the Winner" << endl;
						system("PAUSE");
						exit(0);
					}
				}
//////////////////////////////////////
				
				while (1) {
					gotoxy(0, 26);
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << "Press ";
					SetConsoleTextAttribute(hConsole, 12); // Red color
					cout << "[Space Bar]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to Switch p1 and ";
					SetConsoleTextAttribute(hConsole, 12); // Red color
					cout << "[e]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to exit";
					char choice;
					choice = getch();
					if (choice == ' ')
						break;
					if (choice == 'e')
						exit(0);
				}
			}

			else {
				First = !First;
				SetConsoleTextAttribute(hConsole, 15); // White color
				cout << "Now it is "; 
				SetConsoleTextAttribute(hConsole, 10); // green color
				cout << P2.Name ;
				SetConsoleTextAttribute(hConsole, 15); // White color
				cout << "'s Turn" << endl;
				fflush(stdout);
				while (1) {
					gotoxy(0, 24);
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << "Press ";
					SetConsoleTextAttribute(hConsole, 10); // green color
					cout << "[0]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to throw a dice";
					if (getch() == '0')
						break;
				}
				cout << "\nYou Got: "; 
				SetConsoleTextAttribute(hConsole, 10); // green color
				cout << d1.roll();
				SetConsoleTextAttribute(hConsole, 15); // White color
				if (d1.get_number() == 6 && P2.Blocked){
						d1.set_number(1);
						P2.Blocked = false;
				}
				///////////////////////////////////////////////////////////////////////////////////////////	
				if (P2.Blocked)
					cout << " You Can Not Move " << endl;
				
				
				else if (!P2.Blocked)
				{
					int Position1,Position2;
					Position1 = P2.Position;
					Position2 = Move(2, d1.get_number());
					
					if (Position1 == Position2) {
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " You are Stopped at " ;
						SetConsoleTextAttribute(hConsole, 10); // Red color
						cout << Position2;
					}
					else {
						cout << " You Moved from " ;
						SetConsoleTextAttribute(hConsole, 10); // green color
						cout << Position1;
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " to ";
						SetConsoleTextAttribute(hConsole, 10); // green color
						cout << Position2 << endl;
					}
					if (P2.Position == 100){
						SetConsoleTextAttribute(hConsole, 10); // green color
						cout << P2.Name ;
						SetConsoleTextAttribute(hConsole, 15); // White color
						cout << " is the Winner" << endl;
						system("PAUSE");
						exit(0);
					}
				}
								
				while (1) {
					gotoxy(0, 26);
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << "Press ";
					SetConsoleTextAttribute(hConsole, 10); // green color
					cout << "[Space Bar]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to Switch p1 and ";
					SetConsoleTextAttribute(hConsole, 10); // green color
					cout << "[e]";
					SetConsoleTextAttribute(hConsole, 15); // White color
					cout << " to exit";
					char choice;
					choice = getch();
					if (choice == ' ')
						break;
					if (choice == 'e')
						exit(0);
				}
			}
		}
	}
	int Move(int p1, int Number) {
		if (p1 == 1)
		{
			if (P1.Position + Number == 99)
				P1.Position = 4;
			else if (P1.Position + Number == 92)
				P1.Position = 76;
			else if (P1.Position + Number == 67)
				P1.Position = 50;
			else if (P1.Position + Number == 59)
				P1.Position = 37;
			else if (P1.Position + Number == 41)
				P1.Position = 20;
			else if (P1.Position + Number == 31)
				P1.Position = 14;
			
			else if (P1.Position + Number == 2)
				P1.Position = 23;
			else if (P1.Position + Number == 17)
				P1.Position = 93;
			else if (P1.Position + Number == 29)
				P1.Position = 54;
			else if (P1.Position + Number == 39)
				P1.Position = 80;
			else if (P1.Position + Number == 70)
				P1.Position = 89;
							
			else if (P1.Position + Number > 100)
				P1.Position = P1.Position;
			else
				P1.Position += Number;
			
			return P1.Position;
		}

		else
		{
			if (P2.Position + Number == 99)
				P2.Position = 4;
			else if (P2.Position + Number == 92)
				P2.Position = 76;
			else if (P2.Position + Number == 67)
				P2.Position = 50;
			else if (P2.Position + Number == 59)
				P2.Position = 37;
			else if (P2.Position + Number == 41)
				P2.Position = 20;
			else if (P2.Position + Number == 31)
				P2.Position = 14;
			
			else if (P2.Position + Number == 2)
				P2.Position = 23;
			else if (P2.Position + Number == 17)
				P2.Position = 93;
			else if (P2.Position + Number == 29)
				P2.Position = 54;
			else if (P2.Position + Number == 39)
				P2.Position = 80;
			else if (P2.Position + Number == 70)
				P2.Position = 89;
							
			else if (P2.Position + Number > 100)
				P2.Position = P2.Position;
			else
				P2.Position += Number;
			
			return P2.Position;
		}

	}
};


int main() {
	//Grid gg;
	//gg.Draw();
	Dice dd;
	dd.display(	dd.roll());
	
	//Snake_Game SG1;
	//SG1.Play();
	
	system("PAUSE");
	return 0;
}

