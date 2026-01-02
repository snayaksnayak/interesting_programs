/* Program for testing behavior of diamond shape inheritance */
/* Date: 30 Nov 2005 */
/* Author: Srinivas Nayak */
/* Compile using g++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */

//add other necessary parts to make the program complete!

class Top
{
	public:
	int top_1;
    	int top_2;
    	int top_3;
        virtual int func(){top_1=3; return 0;}
	    virtual int hunc(){top_1=1; return 0;}
    	virtual int tunc(){top_2=4; return 0;}
    	virtual int munc(){top_3=5; return 0;}
};
class Base1 : virtual public Top
{
	public:
	int base1_1;
    int base1_2;
            	int func(){base1_1=3; return 0;}
    	virtual int tunc(){base1_2=5; return 0;}
    	virtual int punc(){base1_2=5; return 0;}
    	virtual int runc(){base1_2=5; return 0;}
};
class Base2 : virtual public Top
{
	public:
	int base2_1;
    int base2_2;
	            int func(){base2_1=5; return 0;}
	            int hunc(){base2_2=3; return 0;}
                int tunc(){base2_2=5; return 0;}
	    virtual int gunc(){base2_1=1; return 0;}
    	virtual int munc(){base2_2=5; return 0;}
};
class Derived : public Base2, public Base1
{
	public:
	int derived_1;
    int derived_2;
    int derived_3;
	            int func(){derived_1=7;return 0;}
	            int gunc(){derived_2=1; return 0;}
                int tunc(){derived_3=3; return 0;}
    	virtual int junc(){derived_3=3; return 0;}
    	virtual int lunc(){derived_3=3; return 0;}

};
class DBase1 : virtual public Derived
{
    public:
    int dbase1;
};
class DBase2 : virtual public Derived
{
    public:
    int dbase2;
};
class DDerived : public DBase1, public DBase2
{
    public:
    int dderived;
};

int main()
{
	Top objtop,*ptrtop=&objtop;
	Base1 objbase1,*ptrbase1=&objbase1;
	Base2 objbase2,*ptrbase2=&objbase2;
	Derived objderived,*ptrderived=&objderived;
    DBase1 objdbase1,*ptrdbase1=&objdbase1;
    DBase2 objdbase2,*ptrdbase2=&objdbase2;
    DDerived objdderived,*ptrdderived=&objdderived;

    objtop.top_1=1;
    objtop.top_2=2;
    objtop.top_3=3;

    objbase1.top_1=4;
    objbase1.top_2=5;
    objbase1.top_3=6;
    objbase1.base1_1=7;
    objbase1.base1_2=8;

    objbase2.top_1=9;
    objbase2.top_2=10;
    objbase2.top_3=11;
    objbase2.base2_1=12;
    objbase2.base2_2=13;

    objderived.top_1=14;
    objderived.top_2=15;
    objderived.top_3=16;
    objderived.base1_1=17;
    objderived.base1_2=18;
    objderived.base2_1=19;
    objderived.base2_2=20;
    objderived.derived_1=21;
    objderived.derived_2=22;
    objderived.derived_3=23;

    objdbase1.top_1=1;
    objdbase1.top_2=2;
    objdbase1.top_3=3;
    objdbase1.base1_1=4;
    objdbase1.base1_2=5;
    objdbase1.base2_1=6;
    objdbase1.base2_2=7;
    objdbase1.derived_1=8;
    objdbase1.derived_2=9;
    objdbase1.derived_3=10;
    objdbase1.dbase1=255;

    objdbase2.top_1=1;
    objdbase2.top_2=2;
    objdbase2.top_3=3;
    objdbase2.base1_1=4;
    objdbase2.base1_2=5;
    objdbase2.base2_1=6;
    objdbase2.base2_2=7;
    objdbase2.derived_1=8;
    objdbase2.derived_2=9;
    objdbase2.derived_3=10;
    objdbase2.dbase2=255;

    objdderived.top_1=1;
    objdderived.top_2=2;
    objdderived.top_3=3;
    objdderived.base1_1=4;
    objdderived.base1_2=5;
    objdderived.base2_1=6;
    objdderived.base2_2=7;
    objdderived.derived_1=8;
    objdderived.derived_2=9;
    objdderived.derived_3=10;
    objdderived.dbase1=14;
    objdderived.dbase2=15;
    objdderived.dderived=255;

/*
    objderived.junc();
    objderived.lunc();

    ptrtop=&objtop;
    ptrbase1=&objbase1;
    ptrbase2=&objbase2;
    ptrderived=&objderived;
    ptrdbase1=&objdbase1;
    ptrdbase2=&objdbase2;
    ptrdderived=&objdderived;

    ptrtop = &objbase1;
    ptrtop->func();
    ptrtop->hunc();
    ptrtop->tunc();
    ptrtop->munc();

    ptrtop = &objbase2;
    ptrtop->func();
    ptrtop->hunc();
    ptrtop->tunc();
    ptrtop->munc();

    ptrtop = &objderived;
    ptrtop->func();
    ptrtop->hunc();
    ptrtop->tunc();
    ptrtop->munc();

    ptrbase1=&objderived;
    ptrbase1->func();
    ptrbase1->hunc();
    ptrbase1->tunc();
    ptrbase1->munc();
    ptrbase1->punc();
    ptrbase1->runc();

    ptrbase2=&objderived;
    ptrbase2->func();
    ptrbase2->hunc();
    ptrbase2->tunc();
    ptrbase2->munc();
    ptrbase2->gunc();
*/
    return 0;
}
