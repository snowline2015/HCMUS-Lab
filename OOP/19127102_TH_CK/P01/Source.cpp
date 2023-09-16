#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

class SoNguyen {
private:
	int v;
public:
	SoNguyen() { v = 0; }
	SoNguyen(int val) { v = val; }
	int getValue() { return this->v; }
	friend bool operator>(SoNguyen a, SoNguyen b) {
		if (a.getValue() > b.getValue()) return true;
		return false;
	}
	friend bool operator<(SoNguyen a, SoNguyen b) {
		if (a.getValue() < b.getValue()) return true;
		return false;
	}
	friend std::ostream& operator << (std::ostream& os, SoNguyen& a) {
		return os << a.v << std::endl;
	}
	friend std::istream& operator >> (std::istream& is, SoNguyen& a) {
		std::cout << "Nhap so nguyen: ";
		return is >> a.v;
	}

};

int SearchBinary(std::vector<SoNguyen> list, int begin, int end, int val)
{
	if (end >= begin) {
		int mid = begin + (end - begin) / 2;
		if (list.at(mid).getValue() == val) return mid;
		if (list.at(mid).getValue() > val)
			return SearchBinary(list, begin, mid - 1, val);
		return SearchBinary(list, mid + 1, end, val);
	}
}

int main() {
	SoNguyen num;
	std::vector<SoNguyen> lst;
	int n, x;
	std::cout << "Nhap so phan tu so nguyen: ";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		lst.push_back(num);
	}
	sort(lst.begin(), lst.end());
	for (std::vector<SoNguyen>::iterator p = lst.begin(); p != lst.end(); p++) {
		std::cout << p->getValue() << " ";
	}
	std::cout << "\nNhap phan tu can tim: ";
	std::cin >> x;
	std::cout << "Phan tu nam o vi tri: " << SearchBinary(lst, 0, n - 1, x) + 1;
	return 0;
}