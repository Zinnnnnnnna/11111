#include "Loan.h"
#include <cmath>
using namespace std;

// �L�Ѽƫغc�l
Loan::Loan() {
    yearrate = 2.5;
    number = 1;
    money = 1000;
	graceperiod = 0;
}

// ���Ѽƫغc�l
Loan::Loan(double rate, int years, double amount,int g) {
    yearrate = rate;
    number = years;
    money = amount;
	graceperiod = g;
}

// Getter ��@
double Loan::getYearrate() const {
    return yearrate;
}

int Loan::getNumber() const {
    return number;
}

double Loan::getMoney() const {
    return money;
}

int Loan::getGraceperiod()const {
    return graceperiod;
}

// Setter ��@
void Loan::setYearrate(double rate) {
    yearrate = rate;
}

void Loan::setNumber(int years) {
    number = years;
}

void Loan::setMoney(double amount) {
    money = amount;
}

void Loan::setGraceperiod(int g) {
    graceperiod = g;
}

// �\��G�C����ú���B�]���ϥ� pow�^
double Loan::getMonthpay() const {
    double monthlyRate = yearrate / 1200;
    int totalMonths = number * 12;

    // �ϥ� pow ��ƨӭp�� (1 + monthlyRate) �� totalMonths ����
    double denominator = pow(1 + monthlyRate, totalMonths);

    return money * monthlyRate * denominator / (denominator - 1);
}

// �\��G�`�ٴڪ��B
double Loan::getTotalpay() const {
    return getMonthpay() * number * 12;
}

double Loan::getGraceperiodpayin()const {
    return money * yearrate/100 / 12;
}

double  Loan::getGraceperiodpayout()const {
    double monthlyRate = yearrate / 1200;
    int remainingMonths = (number - graceperiod) * 12;
    double denominator = pow(1 + monthlyRate, remainingMonths);
    return money * monthlyRate * denominator / (denominator - 1);
}
double Loan::getGraceperiodtotalpay()const {
	return getGraceperiodpayin() * graceperiod * 12 + getGraceperiodpayout() * (number - graceperiod) * 12; 
}