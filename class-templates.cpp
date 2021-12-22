// Week 51 22 Dec 2021
// Class templates


#include <iostream>

class Account
{
public:
    explicit Account(double amount=0.0) :balance(amount) {}

    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        balance -= amount;
    }
    double getBalance() const{
        return balance;
    }

private:
    double balance;
};

template<typename T, int N>
class Array{

public:
    Array()=default;
    int getSize() const;
private:
    T elem[N];
};

template<typename T, int N>
int Array<T, N>::getSize() const 
{
    return N;
}

int main()
{
    Array<double, 10> doubleArray;
    std::cout << "\ndoubleArray.getSize() " << doubleArray.getSize();

    Array<Account, 5> accountArray;
    std::cout << "\naccountArray.getSize() " << accountArray.getSize();

}