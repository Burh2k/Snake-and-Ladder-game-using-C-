#include<iostream>

#include<iomanip>

#include<cstdlib>

#include<ctime>

#include<string>

using namespace std;

int roll() {
  int num;
  num = rand() % (6) + 1;
  return num;
}
char player1[100];
char player2[100];

template <typename T> class Node
{
	public:
    T data; //the object information
    Node<T>* next; //pointer to the next node element
  	Node<T>* prenode;
  	Node() {
    this -> data = data;
    prenode = NULL;
    next = NULL;
  }
};

class stack
{
public:
Node<int> *top;
stack()
{
top = NULL;
}
int gettop()
{
return top->data;
}
void push(int num)
{
Node<int> *temp = new Node<int>;
temp->data=num;
temp->next=NULL;
if(top==NULL)
{
top = temp;
}
else
{
temp->next=top;
top = temp;
}
}
void display() {
Node<int> *temp=NULL;
temp = top;
while(temp!=NULL)
{
cout << temp->data << endl;
temp = temp->next;
}
}
void pop() {
Node<int> *temp=top;
top=top->next;
delete temp;
}
};

class Turns {
  public: 
  Node<string>* head;
  Node<string>* tail;
  Node<string>* current;
  stack st1;
	bool x, y;
	int p1,p2;
  Turns() {
    head = NULL;
    tail = NULL;
    current = NULL;
     p1 = 0; //p for position
     p2 = 0; //p for position
	x=true;
	y=false;
  }
  string getcurrent() {
    return current -> data;
  }
  void setcurrent(Node<string>* index) {
    current = index;
  }
  void sethead(Node<string>* Head) {
    head = Head;
  }
  void add(string num) {
    Node<string>* temp = new Node<string>;
    temp -> data = num;
    temp -> next = NULL;
    if (head == NULL) {
      temp -> prenode = NULL;
      sethead(temp);
      tail = temp;
      current = head;
    } else {
      tail -> next = temp;
      temp -> prenode = tail;
      tail = temp;
    }
  }
  void display() {
    setcurrent(head);

    while (current != NULL) {
      cout << "-> " << getcurrent() << endl;
      setcurrent(current -> next);
    }
    setcurrent(head);
  }
  void forward() {
    setcurrent
      (current -> next);
    cout << "-> " << getcurrent() << endl;
  }
  void backward() {
    setcurrent
      (current -> prenode);
    cout << "-> " << getcurrent() << endl;
  }
  void move() {
    srand(time(NULL));
    for (int i = 1; i <= 100; i++) { // Initially giving all position of P and C empty i.e ' ' .
      player1[i] = ' ';
      player2[i] = ' ';
    }
    //	board(); //display board
    char n; //cin from user for dice roll
    int r; //number from dice
    int c;

    //	int p2=0; 
    //		while(p1 != 100 || p2!= 100){
    player1[p1] = ' ';
    player2[p2] = ' ';

    //		if(getcurrent()=="Burhan"){ //check whose currently playing
    cout << "Press r to roll dice Player : " << getcurrent() << " ";
    cin >> n;
    if (n == 'r') {
      if (p1 > 100 || p2 > 100)
	  { //if dice generate a number that led to cross the 100th box in grid
        p1 = p1; //keep the present position
      p2 = p2;
  }
      else {
        r = roll();
        if (x==true) {
        st1.push(r);
          p1 = p1 + st1.gettop(); //update the position by adding new number generated from dice
          if (p1 > 100) {
            p1=p1- st1.gettop();
            st1.pop();
//          	st1.pop();
//            p1 = p1 - r; //remove the dice number from position and keep it at present
          }
          cout << "Player 1 "<<getcurrent()<<" got " << st1.gettop() << endl;
          if (r == 6) { //if dice give 6 then re-roll
            r = roll();
            st1.push(r);
            p1 = p1 + st1.gettop();
            if (p1 > 100) {
            p1=p1- st1.gettop();
            st1.pop();
//            	st1.pop();
//            	p1 = p1 - r;
            }
            cout << "Player 1 "<<getcurrent()<<" got " << st1.gettop() << " at 2nd turn" << endl;
            if (r == 6) {
            r = roll(); //roll for the third time
            st1.push(r);
            p1 = p1 + st1.gettop();
              if (p1 > 100 && r != 6) {
                p1=p1- st1.gettop();
              	st1.pop();
//              	st1.pop();
//                p1 = p1 - r;
              }
              if (r == 6) { //if 6 again, he stay where he is
              p1=p1- st1.gettop();
              st1.pop();
			  p1=p1- st1.gettop();
              st1.pop();
			  p1=p1- st1.gettop();
              st1.pop();
              
               // p1 = 6 - 6 - 6;
                cout << "Three consecutive 6's which is 0" << endl;
              } else
                cout << "Player 1 "<<getcurrent()<<" got " << r << " at 3rd turn" << endl;
            }
          }
        }
		 else {
		 st1.push(r);
          p2 = p2 + st1.gettop(); //update the position by adding new number generated from dice
          if (p2 > 100) {
          	p2=p2- st1.gettop();
            st1.pop();
           // p2 = p2 - r; //remove the dice number from position and keep it at present
          }
          cout << "Player 2 "<<getcurrent()<<" got " << r << endl;
          if (r == 6) { //if dice give 6 then re-roll
            r = roll();
            st1.push(r);
            p2 = p2 + st1.gettop();
            if (p2 > 100) {
            p2=p2  - st1.gettop();
            st1.pop();
            //  p2 = p2 - r;
            }
            cout << "Player 2 "<<getcurrent()<<" got " << r << " at 2nd turn" << endl;
            if (r == 6) {
              r = roll(); //roll for the third time
            st1.push(r);
              p2 = p2 + st1.gettop();
              if (p2 > 100 && r != 6) {
              	p2=p2- st1.gettop();
              	st1.pop();
               // p2 = p2 - r;
              }
              if (r == 6) { //if 6 again, he stay where he is
            	p2=p2- st1.gettop();
              	st1.pop();
			  	p2=p2- st1.gettop();
              	st1.pop();
			  	p2=p2- st1.gettop();
              	st1.pop();
				//p2 = 6 - 6 - 6;
                cout << "Three consecutive 6's which is 0" << endl;
              } else
                cout << "Player 2 "<<getcurrent()<<" got " << r << " at 3rd turn" << endl;
            }
          }
        }
      }
    }
    
    player1[p1] = 'A';
    player2[p2] = 'B';

	if (x == true && y==false) {
      y = true;
      x=false;
    } else {
      x = true;
      y=false;
    }
      if (p1 == 100) {
        cout << "Player 1 " <<getcurrent()<<" has Won!!!";
        exit(0);
      }
      if (p2 == 100) {
        cout << "Player 2 " <<getcurrent()<<" has Won!!!";
        exit(0);
      }
  }

};
void board() {
  cout << " ______________________________________________________________________" << endl;
  cout << "|  " << "100  " << "|  " << "99  " << "|  " << "98  " << "|  " << "97  " << "|  " << "96  " << "|  " << "95  " << "|  " << "94  " << "|  " << "93  " << "|  " << "92  " << "|  " << "91  |" << endl;
  cout << "|" << "   " << player1[100] << player2[100] << "  |" << "   " << player1[99] << player2[99] << " |" << "   " << player1[98] << player2[98] << " |" << "   " << player1[97] << player2[97] << " |" << "   " << player1[96] << player2[96] << " |" << "   " << player1[95] << player2[95] << " |" << "   " << player1[94] << player2[94] << " |" << "   " << player1[93] << player2[93] << " |" << "   " << player1[92] << player2[92] << " |" << "   " << player1[91] << player2[91] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "81   " << "|  " << "82  " << "|  " << "83  " << "|  " << "84  " << "|  " << "85  " << "|  " << "86  " << "|  " << "87  " << "|  " << "88  " << "|  " << "89  " << "|  " << "90  |" << endl;
  cout << "|" << "   " << player1[81] << player2[81] << "  |" << "   " << player1[82] << player2[82] << " |" << "   " << player1[83] << player2[83] << " |" << "   " << player1[84] << player2[84] << " |" << "   " << player1[85] << player2[85] << " |" << "   " << player1[86] << player2[86] << " |" << "   " << player1[87] << player2[87] << " |" << "   " << player1[88] << player2[88] << " |" << "   " << player1[89] << player2[89] << " |" << "   " << player1[90] << player2[90] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "80   " << "|  " << "79  " << "|  " << "78  " << "|  " << "77  " << "|  " << "76  " << "|  " << "75  " << "|  " << "74  " << "|  " << "73  " << "|  " << "72  " << "|  " << "71  |" << endl;
  cout << "|" << "   " << player1[80] << player2[80] << "  |" << "   " << player1[79] << player2[79] << " |" << "   " << player1[78] << player2[78] << " |" << "   " << player1[77] << player2[77] << " |" << "   " << player1[76] << player2[76] << " |" << "   " << player1[75] << player2[75] << " |" << "   " << player1[74] << player2[74] << " |" << "   " << player1[73] << player2[73] << " |" << "   " << player1[72] << player2[72] << " |" << "   " << player1[71] << player2[71] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "61   " << "|  " << "62  " << "|  " << "63  " << "|  " << "64  " << "|  " << "65  " << "|  " << "66  " << "|  " << "67  " << "|  " << "68  " << "|  " << "69  " << "|  " << "70  |" << endl;
  cout << "|" << "   " << player1[61] << player2[61] << "  |" << "   " << player1[62] << player2[62] << " |" << "   " << player1[63] << player2[63] << " |" << "   " << player1[64] << player2[64] << " |" << "   " << player1[65] << player2[65] << " |" << "   " << player1[66] << player2[66] << " |" << "   " << player1[67] << player2[67] << " |" << "   " << player1[68] << player2[68] << " |" << "   " << player1[69] << player2[69] << " |" << "   " << player1[70] << player2[70] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "60   " << "|  " << "59  " << "|  " << "58  " << "|  " << "57  " << "|  " << "56  " << "|  " << "55  " << "|  " << "54  " << "|  " << "53  " << "|  " << "52  " << "|  " << "51  |" << endl;
  cout << "|" << "   " << player1[60] << player2[60] << "  |" << "   " << player1[59] << player2[59] << " |" << "   " << player1[58] << player2[58] << " |" << "   " << player1[57] << player2[57] << " |" << "   " << player1[56] << player2[56] << " |" << "   " << player1[55] << player2[55] << " |" << "   " << player1[54] << player2[54] << " |" << "   " << player1[53] << player2[53] << " |" << "   " << player1[52] << player2[52] << " |" << "   " << player1[51] << player2[51] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "41   " << "|  " << "42  " << "|  " << "43  " << "|  " << "44  " << "|  " << "45  " << "|  " << "46  " << "|  " << "47  " << "|  " << "48  " << "|  " << "49  " << "|  " << "50  |" << endl;
  cout << "|" << "   " << player1[41] << player2[41] << "  |" << "   " << player1[42] << player2[42] << " |" << "   " << player1[43] << player2[43] << " |" << "   " << player1[44] << player2[44] << " |" << "   " << player1[45] << player2[45] << " |" << "   " << player1[46] << player2[46] << " |" << "   " << player1[47] << player2[47] << " |" << "   " << player1[48] << player2[48] << " |" << "   " << player1[49] << player2[49] << " |" << "   " << player1[50] << player2[50] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "40   " << "|  " << "39  " << "|  " << "38  " << "|  " << "37  " << "|  " << "36  " << "|  " << "35  " << "|  " << "34  " << "|  " << "33  " << "|  " << "32  " << "|  " << "31  |" << endl;
  cout << "|" << "   " << player1[40] << player2[40] << "  |" << "   " << player1[39] << player2[39] << " |" << "   " << player1[38] << player2[38] << " |" << "   " << player1[37] << player2[37] << " |" << "   " << player1[36] << player2[36] << " |" << "   " << player1[35] << player2[35] << " |" << "   " << player1[34] << player2[34] << " |" << "   " << player1[33] << player2[33] << " |" << "   " << player1[32] << player2[32] << " |" << "   " << player1[31] << player2[31] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "21   " << "|  " << "22  " << "|  " << "23  " << "|  " << "24  " << "|  " << "25  " << "|  " << "26  " << "|  " << "27  " << "|  " << "28  " << "|  " << "29  " << "|  " << "30  |" << endl;
  cout << "|" << "   " << player1[21] << player2[21] << "  |" << "   " << player1[22] << player2[22] << " |" << "   " << player1[23] << player2[23] << " |" << "   " << player1[24] << player2[24] << " |" << "   " << player1[25] << player2[25] << " |" << "   " << player1[26] << player2[26] << " |" << "   " << player1[27] << player2[27] << " |" << "   " << player1[28] << player2[28] << " |" << "   " << player1[29] << player2[29] << " |" << "   " << player1[30] << player2[30] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "20   " << "|  " << "19  " << "|  " << "18  " << "|  " << "17  " << "|  " << "16  " << "|  " << "15  " << "|  " << "14  " << "|  " << "13  " << "|  " << "12  " << "|  " << "11  |" << endl;
  cout << "|" << "   " << player1[20] << player2[20] << "  |" << "   " << player1[19] << player2[19] << " |" << "   " << player1[18] << player2[18] << " |" << "   " << player1[17] << player2[17] << " |" << "   " << player1[16] << player2[16] << " |" << "   " << player1[15] << player2[15] << " |" << "   " << player1[14] << player2[14] << " |" << "   " << player1[13] << player2[13] << " |" << "   " << player1[12] << player2[12] << " |" << "   " << player1[11] << player2[11] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;
  cout << "|  " << "1    " << "|  " << "2   " << "|  " << "3   " << "|  " << "4   " << "|  " << "5   " << "|  " << "6   " << "|  " << "7   " << "|  " << "8   " << "|  " << "9   " << "|  " << "10  |" << endl;
  cout << "|" << "   " << player1[1] << player2[1] << "  |" << "   " << player1[2] << player2[2] << " |" << "   " << player1[3] << player2[3] << " |" << "   " << player1[4] << player2[4] << " |" << "   " << player1[5] << player2[5] << " |" << "   " << player1[6] << player2[6] << " |" << "   " << player1[7] << player2[7] << " |" << "   " << player1[8] << player2[8] << " |" << "   " << player1[9] << player2[9] << " |" << "   " << player1[10] << player2[10] << " |";
  cout << endl << " ----------------------------------------------------------------------" << endl;

}
int main() {
  Turns l1;
  char input;
  string user;
  cout << "Enter Name of PLayer 1" << endl;
  cin >> user;
  l1.add(user);
  cout << "Enter Name of PLayer 2" << endl;
  cin >> user;
  l1.add(user);
  l1.display();
  char x; //input to continue the loop
  while (true) {
    l1.move();
    l1.forward();
    board();
    l1.move();
    l1.backward();
    board();
    cout << "Enter C to continue : ";
    cin >> x;
    if (x == 'c' || x == 'C') {
      system("CLS");
    }
  }
  return 0;
}
