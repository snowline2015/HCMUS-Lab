#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class MyString {
private:
	char* arr;
public:
	MyString() {}
	MyString(const char* a) {
		arr = new char[strlen(a) + 1];
		strcpy(arr, a);
	}
	~MyString() {}
	vector<MyString> Split(vector<char> a, bool b) {
		MyString temp1;
		vector<MyString> temp2;
		bool check;
		int count = 0;
		if (b == true) {
			for (int i = 0; i < strlen(this->arr); i++) {
				check = false;
				for (vector<char>::iterator j = a.begin(); j != a.end(); j++) {
					if (this->arr[i] == *j) {
						check = true;
						break;
					}
				}
				if (check == true && count != 0) {
					temp1.arr = new char[count + 1];
					int temp = count;
					for (int k = 0; k < count; k++) {
						temp1.arr[k] = this->arr[i - temp];
						temp--;
					}
					temp1.arr[count] = '\0';
					temp2.push_back(temp1);
					count = 0;
				}
				if (check == false) count++;
			}
		}
		else {
			for (int i = 0; i < strlen(this->arr); i++) {
				check = false;
				for (vector<char>::iterator j = a.begin(); j != a.end(); j++) {
					if (this->arr[i] == *j) {
						check = true;
						break;
					}
				}
				if (check == false) {
					temp1.arr = new char[2];
					temp1.arr[0] = this->arr[i]; temp1.arr[1] = '\0';
					temp2.push_back(temp1);
				}
			}
		}
		return temp2;
	}
	friend ostream& operator << (ostream& os, MyString& str) { return os << str.arr; };
	friend MyString operator +(const MyString str1, const MyString str2) {
		MyString temp;
		temp.arr = new char[strlen(str1.arr) + strlen(str2.arr) + 1];
		strcpy(temp.arr, str1.arr);
		strcat(temp.arr, str2.arr);
		return temp;
	}

};

void main()
{
	MyString ms1("abcdsf");
	MyString ms2 = "____" + ms1;
	MyString ms3 = ms1 + ms2;
	cout << "ms1= " << ms1 << endl;
	cout << "ms2= " << ms2 << endl;
	cout << "ms3= " << ms3 << endl << endl;
	MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
	vector<char> arrChar;
	arrChar.push_back(',');
	arrChar.push_back('.');
	arrChar.push_back(';');
	vector<MyString> vMs = ms.Split(arrChar, false);
	cout << "Split:" << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); itMS++)
	{
		cout << *itMS << " ";
	}
	cout << endl << "size= " << vMs.size() << endl << endl;
	vMs = ms.Split(arrChar, true);
	cout << "Split co loai bo empty:" << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); itMS++)
	{
		cout << *itMS << " ";
	}
	cout << endl << "size= " << vMs.size() << endl << endl;
}