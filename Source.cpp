#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RandNum {
public:
	int num;
	string str;
	RandNum() {
		num = rand();
		str = "Ёлемент: " + to_string(num);
	}
	int return_num() {
		return num;
	}
	string return_str() {
		return str;
	}
};
ostream& operator<<(ostream& os, const RandNum& obj) {
	return os << obj.str;
}


template <class T>

class container
{
private:
	vector<T> Data;
public:
	void Add_Begin(T element)
	{
		Data.insert(Data.begin(), element);
	}

	void Add_Center(T element)
	{
		Data.insert(Data.begin() + ((int)(Data.size() / 2)), element);
	}

	void Add_End(T element)
	{
		Data.push_back(element);
	}

	void Remove_Index(int index)
	{
		if (index < Data.size())
			Data.erase(Data.begin() + index);
		else
			cout << "error, index not found!\n";
	}

	T Find(int index)
	{
		return Data.at(index);
	}

	void Change(int index, T element)
	{
		Remove_Index(index);
		Data.insert(Data.begin() + index, element);
	}

	int Size()
	{
		return Data.size();
	}
};

void main()
{

	setlocale(LC_ALL, "rus");

	srand(time(NULL));

	container <RandNum*> arr;
	clock_t start = clock();
	for (int i = 0; i < 1000; ++i) {
		arr.Add_End(new RandNum());
	}
	for (int i = 0; i < 1000; ++i) {
		switch (rand() % 6)
		{
		case 0:
			arr.Add_End(new RandNum());
			break;
		case 1:
			if (arr.Size()) {
				arr.Remove_Index(rand() % arr.Size());
			}
			break;
		case 2:
			arr.Add_Begin(new RandNum());
			break;
		case 3:
			arr.Find(rand() % arr.Size());
			break;
		case 4:
			arr.Change(rand() % arr.Size(), new RandNum());
			break;
		case 5:
			arr.Add_Center(new RandNum());
			break;
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	for (int i = 1; i < arr.Size(); ++i) {
		cout << *arr.Find(i);
		cout << '\n';
	}
	cout << '\n';
	cout << "¬рем€ работы:" << seconds << '\n';
		
}