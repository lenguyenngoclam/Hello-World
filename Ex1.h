#include <iostream>
#include <cmath>

//This branch is using for Branch-for-exercise1

using namespace std;

class Fraction;
//Khai báo hàm đọc, ghi (Hai hàm này không phải là member của class Fraction)
istream &read(istream &, Fraction &);
ostream &print(ostream &, const Fraction &);

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

class Fraction{
    private :
        int numerator = 0, denominator = 1;
    
    public :
        //Khởi tạo mặc định phân số bằng 0
        Fraction() = default;
        //Khởi tạo giá trị từ tử và mẫu cho trước
        Fraction(int n, int d) : numerator(n), denominator(d) {}
        //Khởi tạo từ giá trị nguyên cho trước
        Fraction(int x) : numerator(x), denominator(1) {}
        //Khởi tạo giá trị từ phân số cho trước
        Fraction(const Fraction &f){
            numerator = f.getNumerator();
            denominator = f.getDenominator();
        }

        ~Fraction() {}

        int getNumerator() const{ return numerator; }
        int getDenominator() const{ return denominator; }

        void setNumerator(int n) {
            numerator = n;
        }
        void setDenominator(int d){
            try{
                denominator = d;
                if(denominator == 0)
                    throw runtime_error("Invalid input ! Denominator can not be 0");
            } catch (runtime_error err){
                cout << err.what() << endl;
            }
        }

        //Nghịch đảo phân số
        Fraction inverseFraction() const{
            Fraction temp = Fraction(denominator, numerator);
            return temp;
        }
        //Rút gọn phân số
        Fraction &simplify(){
            int GCD = gcd(denominator, numerator);
            denominator /= GCD;
            numerator /= GCD;
            return (*this);
        }

        //Khai báo các member function thực hiện các phép toán của phân số
        Fraction& add(const Fraction &);
        Fraction& sub(const Fraction &);
        Fraction& mul(const Fraction &);
        Fraction& div(const Fraction &);
        const Fraction& compareFraction(const Fraction &f1, const Fraction &f2);

    friend istream &read(istream &, Fraction &);
    friend ostream &print(ostream &, const Fraction &);
};

