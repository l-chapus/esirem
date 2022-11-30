
class Date{

private:
	int _day;
	int _month;
	int _year;
	bool isDate(int day, int month, int year);
public:
	Date(int day=1, int month=1, int year=2000);
	int year();
	int month();
	int day();
};