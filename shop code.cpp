#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

// this function is independent, hence, mentioned at the top
int rand_num(int l, int u)
{
    return rand()%(u-l+1);
}

/*
 parent class pointer can point to child class objects.
 child class will inherit all the properties of the parent,
 but without its own attributes and functions.

 See checking_class_properties.cpp for reference.
*/

class date
{
    public:

    int day;
    int mon;
    int year;

    date()
    {
        day=0;
        mon=0;
        year=0;
    }

    date(int day, int mon, int year)
    {
        this->day=day;
        this->mon=mon;
        this->year=year;
    }

    void enter()
    {
        cout<<"Enter the day: ";
        cin>>day;
        cout<<"Enter the month: ";
        cin>>mon;
        cout<<"Enter the year: ";
        cin>>year;
    }

    void display()
    {
        cout<<"Enter the day: "<<day<<endl;
        cout<<"Enter the month: "<<mon<<endl;
        cout<<"Enter the year: "<<year<<endl;
    }
};

class item
{
    public:

    int id;
    string name;
    float price;

    date dom; // date of manufacture
    date doe;  // date of expiry

    item()
    {
        this->id=0;
        this->name="n/a";
        this->price=0.0;

        this->dom.day=0;
        this->dom.mon=0;
        this->dom.year=0;

        this->doe.day=0;
        this->doe.mon=0;
        this->doe.year=0;
    }

    item(int id, string name, float price, date dom, date doe)
    {
        this->id=id;
        this->name=name;
        this->price=price;

        this->dom.day=dom.day;
        this->dom.mon=dom.mon;
        this->dom.year=dom.year;

        this->doe.day=dom.day;
        this->doe.mon=dom.mon;
        this->doe.year=dom.year;
    }

    void display()
    {
        cout<<"Item ID: "<<id<<endl;
        cout<<"Item name: "<<name<<endl;
        cout<<"Item price: "<<price<<endl;
        cout<<"Item manufacture date:\n";
        dom.display();
        cout<<endl;
        cout<<"Item expiry date:\n";
        doe.display();
    }

    int return_id()
    {
        return id;
    }
};

class food:public item
{
    public:

    static float ftax; // common tax for all food items
    float nv; // nutritional value, display this as a percentage

    food()
    {}

    food(int id, string name, float price, date dom, date doe, int nv)
    {
        this->id=id;
        this->name=name;
        this->price=price;

        this->dom.day=dom.day;
        this->dom.mon=dom.mon;
        this->dom.year=dom.year;

        this->doe.day=dom.day;
        this->doe.mon=dom.mon;
        this->doe.year=dom.year;

        this->nv=nv;
    }

    // cal_price is going to be called only while shopping
    float cal_price()
    {
        return price+(price*ftax);
    }

    void print_food()
    {
        display();
        cout<<endl;
        cout<<"Item type: Food"<<endl;
        cout<<"Item tax: "<<ftax<<"%"<<endl;
        cout<<"Item Nutritional Value: "<<nv<<endl;
    }
};

class cleaner:public item
{
    public:

    static float ctax; // common tax for all cleaner

    cleaner()
    {}

    /*
     there is no need for a MODIFIED parametrized constructor
     as there are no non-static attributes in this class
    */

    cleaner(int id, string name, float price, date dom, date doe)
    {
        this->id=id;
        this->name=name;
        this->price=price;

        this->dom.day=dom.day;
        this->dom.mon=dom.mon;
        this->dom.year=dom.year;

        this->doe.day=dom.day;
        this->doe.mon=dom.mon;
        this->doe.year=dom.year;
    }

    void print_cleaner()
    {
        display();
        cout<<endl;
        cout<<"Item type: Cleaner"<<endl;
        cout<<"Item tax: "<<ctax<<"%"<<endl;
    }

    // cal_price is going to be called only while shopping
    float cal_price()
    {
        return price+(price*ctax);
    }
};

class utensil:public item
{
    public:

    static float utax; // common tax for all utensils
    string tom; // type of material

    utensil()
    {}

    utensil(int id, string name, float price, date dom, date doe, string tom)
    {
        this->id=id;
        this->name=name;
        this->price=price;

        this->dom.day=dom.day;
        this->dom.mon=dom.mon;
        this->dom.year=dom.year;

        this->doe.day=dom.day;
        this->doe.mon=dom.mon;
        this->doe.year=dom.year;

        this->tom=tom;
    }

    // cal_price is going to be called only while shopping
    float cal_price()
    {
        return price+(price*utax);
    }

    void print_cleaner()
    {
        display();
        cout<<endl;
        cout<<"Item type: Utensil"<<endl;
        cout<<"Item tax: "<<utax<<"%"<<endl;
        cout<<"Item Material Type: "<<tom<<endl;
    }
};

class shop
{
    int id;
    string name;
    string city;
    date doc; // date of creation/opening

    //shop(int id, string name, string city, item item_list[])

    public:

    item item_list[5]; // 5 for simplicity

    // These variables have been made static
    // assuming only one shop

    static int noib; // no. of items bought
    static int noc; // no. of customers
    static int noie; // no. of items expired
    static int nooc; // no. of old customers
    static float sale; // total sale of the shop

    shop(int id, string name, string city, date doc)
    {
        this->id=id;
        this->name=name;
        this->city=city;
        this->doc.day=doc.day;
        this->doc.mon=doc.mon;
        this->doc.year=doc.year;

        /*
        This initialization should to be done outside all the classes.

        noib=0;
        noc=0;
        noie=0;
        nooc=0;
        */
    }

    void display()
    {
        cout<<"Shop ID: "<<id<<endl;
        cout<<"Shop name: "<<name<<endl;
        cout<<"Shop city: "<<city<<endl;
        cout<<"Date of creation of the shop:\n";
        doc.display();
        cout<<"List of items in the shop:\n\n";

        int i;

        for(i=0;i<5;i++)
        {
            cout<<"Item "<<i+1<<":"<<endl;
            item_list[i].display();
            cout<<endl<<endl;
        }
    }
};

int shop::noib=0;
int shop::noc=0;
int shop::nooc=0;
int shop::noie=0;
float shop::sale=0.0;

float food::ftax=5.0;
float cleaner::ctax=8.0;
float utensil::utax=12.0;

int search_item(item item_list[], int item_id)
{
    int i;

    for(i=0;i<5;i++)
    {
        if(item_list[i].return_id()==item_id)
            return item_id;
    }

    return -1; // item_id not found in the list of items
}

class customer
{
    protected:

    int id;
    date dob; // date of birth

    public:

    string name;
    int ib[5]; // ID's of the items bought

    customer(int id, string name, date dob)
    {
        this->id=id;
        this->name=name;

        this->dob.day=dob.day;
        this->dob.mon=dob.mon;
        this->dob.year=dob.year;

        int i;

        for(i=0;i<5;i++)
            ib[i]=0;
    }

    void display()
    {
        cout<<"Customer ID: "<<id<<endl;
        cout<<"Customer name: "<<name<<endl;
        cout<<"Customer date of birth:\n";
        dob.display();
    }

    int age()
    {
        int cur_year=2022;
        return cur_year-dob.year;
    }

    void shopping(shop s);

    void above_60();

    void items_bought(shop s);
};

class gold:public customer
{
    public:

    static float gdic;

    /*
     Why am I getting the error:
     No matching function call for customer()
     as well as gold() ?

     There was no error in a similar case of inheritance
     in 'understanding inheritance.cpp'

     Why is referring to the base class constructor required here?
    */

    gold(int id, string name, date dob, int ID, string NAME, date DOB):customer(ID,NAME,DOB)
    {
        this->id=id;
        this->name=name;

        this->dob.day=dob.day;
        this->dob.mon=dob.mon;
        this->dob.year=dob.year;

        int i;

        for(i=0;i<5;i++)
            ib[i]=0;
    }

    void display()
    {
        cout<<"Customer ID: "<<id<<endl;
        cout<<"Customer name: "<<name<<endl;
        cout<<"Customer date of birth:\n";
        dob.display();
        cout<<endl;
        cout<<"Gold Customer Discount: "<<gdic;
    }
};

class silver:public customer
{
    public:

    static float sdic;

   silver(int id, string name, date dob, int ID, string NAME, date DOB):customer(ID,NAME,DOB)
    {
        this->id=id;
        this->name=name;

        this->dob.day=dob.day;
        this->dob.mon=dob.mon;
        this->dob.year=dob.year;

        int i;

        for(i=0;i<5;i++)
            ib[i]=0;
    }

    void display()
    {
        cout<<"Customer ID: "<<id<<endl;
        cout<<"Customer name: "<<name<<endl;
        cout<<"Customer date of birth:\n";
        dob.display();
        cout<<endl;
        cout<<"Silver Customer Discount: "<<sdic;
    }
};

class platinum:public customer
{
    public:

    static float pdic;

    platinum(int id, string name, date dob, int ID, string NAME, date DOB):customer(ID,NAME,DOB)
    {
        this->id=id;
        this->name=name;

        this->dob.day=dob.day;
        this->dob.mon=dob.mon;
        this->dob.year=dob.year;

        int i;

        for(i=0;i<5;i++)
            ib[i]=0;
    }

    void display()
    {
        cout<<"Customer ID: "<<id<<endl;
        cout<<"Customer name: "<<name<<endl;
        cout<<"Customer date of birth:\n";
        dob.display();
        cout<<endl;
        cout<<"Platinum Customer Discount: "<<pdic;
    }
};

float gold::gdic=15.0;
float silver::sdic=10.0;
float platinum::pdic=5.0;

// the primary function
void customer::shopping(shop s) // nos is number of shops
{
    cout<<"Hello, "<<name<<"!\nWelcome to our shopping complex!\nHere, the details of the shop and what's in store!\n\n";

    int i;

    s.display();

    int item_id;

        item_id=rand_num(1,5); // the item ID has been generated randomly

        if(search_item(s.item_list,item_id)>0) // not equal to 0 and -1
        {
            s.sale=s.sale+s.item_list[item_id].price;
            cout<<"Great! The item has been bought!";
            s.noib++;
            s.noc++;

            if(age()>60)
                s.nooc++;

            for(i=0;i<5;i++)
            {
                if(ib[i]==0)
                    ib[i]=item_id;
            }
        }

    cout<<endl;
    above_60();
    cout<<endl;

}

void customer::above_60()
{
    if(age()>60)
        cout<<name<<" is an old customer of ours."<<endl;
}

void print_noc(shop s)
{
    cout<<"No. of customers: "<<s.noc<<endl;
}

void print_noib(shop s)
{
    cout<<"No. of items bought from the store: "<<s.noib<<endl;
}

void print_noie(shop s)
{
    cout<<"No. of expired items in the store: "<<s.noie<<endl;
}

void customer::items_bought(shop s)
{
    int i;

    for(i=0;i<5;i++)
    {
        if(ib[i]!=0 && search_item(s.item_list,ib[i])>0)
            s.item_list[ib[i]].display();

        cout<<endl;
    }
}

int expiry_date(date d)
{
    if(d.year<2022)
        if(d.mon<3)
            return 1; // 1 as in the item has expired

    return 0; // the item has not expired
}

void check_expired_items(shop s)
{
    int i;

    for(i=0;i<5;i++)
        if( expiry_date(s.item_list[i].doe)==1)
            s.noie++;
}

int main()
{
    /*
     In the item_list in shop, initialize each array element to an object of class
     detergent, utensil, clothes, food, etc.
    */

    /*
     There is supposed to be no user input.
     Initialize all the class members.
    */

    shop s(12345,"shop_name","shop_city",{4,5,19}); // creating the shop

    food f1(1,"item_fa",100.0,{1,1,2019},{1,1,2020},100.0);
    cleaner cl1(1,"item_ca",100.0,{1,1,2019},{1,1,2020});
    utensil u1(1,"item_ua",100.0,{1,1,2019},{1,1,2020},"Steel");

    /*
     The initialization of the first three elements of the item list is
     being replaced by initialization of them with objects.
    */

    s.item_list[0]=f1;
    s.item_list[1]=cl1;
    s.item_list[2]=u1;

    // s.item_list[0].id=1;
    // s.item_list[1].id=2;
    // s.item_list[2].id=3;
    s.item_list[3].id=4;
    s.item_list[4].id=5;

    // s.item_list[0].name="item_a";
    // s.item_list[1].name="item_b";
    // s.item_list[2].name="item_c";
    s.item_list[3].name="item_d";
    s.item_list[4].name="item_e";

    // s.item_list[0].price=100.0;
    // s.item_list[1].price=200.0;
    // s.item_list[2].price=300.0;
    s.item_list[3].price=400.0;
    s.item_list[4].price=500.0;

    // manufacture dates

    // s.item_list[0].dom.day=1;
    // s.item_list[1].dom.day=2;
    // s.item_list[2].dom.day=3;
    s.item_list[3].dom.day=4;
    s.item_list[4].dom.day=5;

    // s.item_list[0].dom.mon=1;
    // s.item_list[1].dom.mon=2;
    // s.item_list[2].dom.mon=3;
    s.item_list[3].dom.mon=4;
    s.item_list[4].dom.mon=5;

    // s.item_list[0].dom.year=2019;
    // s.item_list[1].dom.year=2019;
    // s.item_list[2].dom.year=2018;
    s.item_list[3].dom.year=2020;
    s.item_list[4].dom.year=2019;

    // expiry dates

    // s.item_list[0].doe.day=1;
    // s.item_list[1].doe.day=2;
    // s.item_list[2].doe.day=3;
    s.item_list[3].doe.day=4;
    s.item_list[4].doe.day=5;

    // s.item_list[0].doe.mon=1;
    // s.item_list[1].doe.mon=2;
    // s.item_list[2].doe.mon=3;
    s.item_list[3].doe.mon=4;
    s.item_list[4].doe.mon=5;

    // s.item_list[0].doe.year=2020;
    // s.item_list[1].doe.year=2021;
    // s.item_list[2].doe.year=2021;
    s.item_list[3].doe.year=2020;
    s.item_list[4].doe.year=2021;

    s.display();

    //customer c1(1,"customer_a",{1,1,1960});

    //customer c2(2,"customer_b",{2,2,1992});
    //customer c3(3,"customer_c",{3,3,1993});
    gold g1(1,"customer_a",{1,1,1960},1,"customer_a",{1,1,1960});
    silver s1(4,"customer_d",{4,4,1994},4,"customer_d",{4,4,1994});
    platinum p1(5,"customer_e",{5,5,1995},5,"customer_e",{5,5,1995});

    cout<<"MENU:\n";
    cout<<"\n1. Let's have a look around the shop!";
    cout<<"\n2. Let's go shopping!";
    cout<<"\n3. Other details of the shop....";
    cout<<"\n4. Exit from the menu....";

    int ch=rand_num(1,4);
    cout<<"\n\nEnter a choice: "<<ch<<endl<<endl;

    switch(ch)
    {
    case 1:
        s.display();
        break;

    case 2:
        g1.shopping(s);
        break;

    case 3:
        cout<<"Other details of the shop:\n";
        print_noc(s);
        print_noib(s);

        check_expired_items(s);
        print_noie(s);
        cout<<endl;

        cout<<"Total sale of the shop: "<<s.sale<<" Rupees.\n";
        break;

    case 4:
        cout<<endl;
        cout<<"Exiting......";
        exit(0);

    default:
        cout<<"\nInvalid choice.";
    }


    cout<<endl<<endl;
    return 0;
}
