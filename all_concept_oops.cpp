#include <iostream>
using namespace std;
#include <fstream>


class Rectangle
{
    private:
    int length;
    int breadth;
    public:
    Rectangle()      //constructor name same as class name
    {                //non parameterized constructor
     length=0;
     breadth=0;
    }   
    Rectangle(int l,int b)   //parameterized constructor
    {
        setLength(l);
        setBreadth(b);
    }
    Rectangle(Rectangle &r)    //copy constructor
    {
      length=r.length;
      breadth=r.breadth;
    }
    int setLength(int l)
    {
        if(l>0)
         length=l;
         else
         length =0;                    
    }
    int setBreadth(int b)
    {
       if(b>0)                               
       breadth=b;
       else
       breadth=0;
    }
    int getLength()
    {
     return length;
    }
    int getBreadth()
    {
        return breadth;
    }
    int area()
    {
        return length*breadth;

    }
    int perimeter()
    {
        return 2*(length+breadth);
    }
    };
    


    //for inheritance
    
class cuboid:public Rectangle
{
private:
int height;
public:
cuboid(int h)     //parameterized constructor
{
 setHeight(h);                  //height=h;                 
}
void setHeight(int h)
{
 if(h>0)
 height=h;     //height=h; 
else
height=0;
}
int getHeight()
{
    return height;
}
int volume()
{
    return getLength()*getBreadth()*height;
}
};

//BASE CLASS POINTER AND DERIVED CLASS OBJECT

    class BasicCar
{
    public:
    void start()    {
        cout<<"Car started"<<endl;    
        }};
        class AdvanceCar: public BasicCar
        {public:void playMusic()
    {cout<<"Music Playing"<<endl;    }
    };



    //destructor and virtual destructor

    #include <iostream>
using namespace std;
class Base
{
    public:
    Base()
    {
        cout<<"constructor of base class"<<endl;
    }
    ~Base()
    {
        cout<<"destructor of base class"<<endl;
    }
};
class Derived:public Base
{
    public:
    Derived()
    {
        cout<<"constructor of derived class"<<endl;
    }
    ~Derived()
    {
        cout<<"Destructor of derived class"<<endl;
    }
};



//OPERATOR OVERLOADING

class Rational
{
    private:
    int p;
    int q;
    public:
    Rational()     //non parameterized constructor
    {
        p=1;
        q=1;
    }
    Rational(int p,int q)     //paramteterized constructor
{
this->p=p;
this->q=q;
}
Rational operator+(Rational r)
{
    Rational t;
    t.p=this->p*r.q+this->q*r.p;
    t.q=this->q*r.q;
    return t;
}
friend ostream & operator<<(ostream &os,Rational &r);

};
ostream & operator<<(ostream &os,Rational &r)
{
    os<<r.p<<"/"<<r.q;
    return os;
}




//POLYMORPHISM


#include <iostream>
using namespace std;
class Car
{
    public:
    virtual void start()=0;      //pure virtual function
    //{
        //cout<<"car started"<<endl;
   // }
};
class Innova:public Car{
    public:
    void start()
    {
        cout<<"Innova started"<<endl;
    }
};
class Swift:public Car{
    public:
    void start()
    {
        cout<<"swift started"<<endl;
    }

};

//TEMPLATE


template <class T,class R>
void add(T a,R b)
{
    cout<<a+b<<endl;
}

//MAIN FUNCTION

int main()
    {
        Rectangle r1(3,5);     //parameterized
        //Rectangle r1;     //non parameterized
        //Rectangle r2(r1);     //copy constructor
        cout<<"area of rectangle is:"<<r1.area()<<endl;
        cout<<r1.getLength();

        //for inheritance

         cuboid c(20);
c.setLength(30);
c.setBreadth(15);
cout<<"volume is:"<<c.volume()<<endl;

//base class pointer and derived class object

AdvanceCar a;
BasicCar *ptr=&a;
//ptr->playMusic();
ptr->start();

    //destructor and virtual destructor
Derived d1;

//operator overloading

Rational r4(5,2),r5(12,3),r6;
r6=r4+r5;
cout<<"sum of "<<r4<<"and"<<r5<<"is"<<r6<<endl;

//polymorphism

Car *ptr1=new Innova();
ptr1->start();            
 ptr1=new Swift();
 ptr1->start();
    

//IOSTREAM






    //writing in a file
ofstream of("My txt");
of<<"Aman"<<endl;
of<<25<<endl;
of<<"CSE"<<endl;
of.close();
//reading from a file

    ifstream ifs("My txt");
    string name;
    int roll;
    string branch;
    ifs>>name>>roll>>branch;
    cout<<"name is:"<<name<<endl<<"roll is:"<<roll<<endl<<"branch is"<<branch;
    ifs.close();
    
    //THROW AND CATCH

    int p=10,q=0,r;
try
{
    if(q==0)
    throw 1;
    r=p/q;
    cout<<r<<endl;
}
catch(int e)
{
    cout<<"Division by zero"<<endl;
}
cout<<"BYE";

//TEMPLATE

add(8,1.9f);

    } 