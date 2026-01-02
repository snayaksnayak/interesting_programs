/* Program for calling base class function explicitly from derived class */
/* Date: 27 Sep 2005 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include <iostream.h>
class abc
{
    int a;

    public:
    virtual void func1(){cout<< "i am in func1 base\n";}
    void func(){func1();}
};
class def : public abc
{
    int b;
    public :
    void func1(){cout<<"ia m in func1 derived\n";}
    void func2(){abc::func();}
};
using namespace std;
int main()
{
    def obj;
    obj.func2();
    return 0;
}
