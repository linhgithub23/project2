#include<iostream>
using namespace std;
class test2{

    private:
        int a = changeValue(a);

    public:
        void changeValue(){
            a = changeValue(a);
        }
        void printValue(){
            cout << a << endl;
        }

};
int main(){
    test2 obj;

    obj.changeValue();
    obj.printValue();

    
    return 0;




}