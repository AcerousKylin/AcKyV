#include <iostream>
using namespace std;

const int N = 1e6 + 10;
const int SPARE = 10;

typedef struct Linear_List {
	double *zero;
	int length;
	int max;
	int size = sizeof(double);
} LList;

bool Init_LList(LList &a) {
	a.zero = (double *) malloc (SPARE * sizeof(double));
	if (!a.zero)
		exit(-1);
	a.length = 0;
	a.max = SPARE;
	return true;
}

bool Insert_LList(LList &a, double num, int pos) {
	double *newzero;
	if (pos < 0 || pos > a.length)
		return false;
	if (a.length >= a.max) {
		newzero = (double *) realloc (a.zero, (a.max + SPARE) * sizeof(double));
		if (!newzero)
			exit(1);
		a.zero = newzero;
		a.max += SPARE;
	}
	for (int i = a.length; i >= pos; i--)
		*(a.zero + i + 1) = *(a.zero + i);
	*(a.zero + pos) = num;
	a.length++;
	return true;
}

bool Delete_LList(LList &a, int pos, int &d) {
	if (pos < 0 || pos >= a.length)
		return false;
	d = *(a.zero + pos);
	for (int i = pos; i < a.length; i++)
		*(a.zero + i) = *(a.zero + i + 1);
	a.length--;
	return true;
}

LList Merge_LList(LList a, LList b) {
	LList t;
	Init_LList(t);
	double *pa = a.zero, *pb = b.zero;
	t.max = t.length = a.length + b.length;
	double *pt = (double *) malloc (t.max * t.size);
	if (!pt)
		exit(-1);
	t.zero = pt;
	while (pa <= a.zero + a.length - 1 && pb <= b.zero + b.length - 1) {
		if (*pa <= *pb)
			*pt++ = *pa++;
		else
			*pt++ = *pb++;
	}
	while (pa <= a.zero + a.length - 1)
		*pt++ = *pa++;
	while (pb <= b.zero + b.length - 1)
		*pt++ = *pb++;
	return t;
}

int Select_LList() {
	cout << "Which list you wanna change (must enter, 1/2)?\n";
	int which;
	cin >> which;
	if (which == 1)
		return 0;
	else if (which == 2)
		return 1;
	else {
		cout << "Please enter a legal value!\n";
		return Select_LList();
	}
}

int main(void) {
	LList list[2];
	Init_LList(list[0]);
	Init_LList(list[1]);
	int s = -1;

	bool tri = true;
	while (tri == true) {
		cout << "\nChange you wanna do:\n" << "i - Insert\nd - Delete\nm - Merge list1 & list2\nq - Quit without Save\n";
		char demand;
		cin >> demand;

		switch (demand) {
			case 'q':
				tri = false;
				break;
			case 'i':
				s = Select_LList();
				int n;
				cout << "Enter the numebr of input, as n.\n";
				cin >> n;
				cout << "Enter n numbers with insert position(recommand you use enter as partition).\n";
				for (int i = 0 ; i < n; i++) {
					double temp_n;
					int temp_p;
					cin >> temp_n >> temp_p;
					if (!Insert_LList(list[s], temp_n, temp_p))
						cout << "Invalid values or input\n";
				}
				break;

			case 'd':
				s = Select_LList();
				int pos;
				cout << "Enter the position of the number you wanna delete.\n";
				cin >> pos;
				int de;
				if (!Delete_LList(list[s], pos, de))
					cout << "Invalid value, delete failed.\n";
				else
					cout << "You've deleted the element " << de << " on position " << pos << ".\n";
				break;

			case 'm':
				s = 0;
				list[0] = Merge_LList(list[0], list[1]);
				break;

			default:
				cout << "Invalid option, program error!\n";
				tri = false;
		}
		if (tri) {
			cout << "\nList's Information:\n";
			cout << "List's length is " << list[s].length << ".\n";
			cout << "List contains element below:\n";
			for (int i = 0; i < list[s].length; i++)
				cout << *( list[s].zero + i ) << " ";
			cout << "\n\n";

			char quit;
			cout << "Though you've tried, do you wanna continue(y/n)?\n";
			cin >> quit;
			if (quit == 'y');
			else if (quit == 'n')
				break;
			else
				cout << "Invalid value, run as default 'y'.\n";
		}
	}
	cout << "Program ended.\n";
	return 0;
}