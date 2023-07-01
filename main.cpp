#include <iostream>
#include <ostream>
#include <fstream>
#include <conio.h>
#include "cusgraphics.h"
#include "user.h"
#include "loadingfnc.h"
#include "function.h"

using namespace std;

mygraphics maker;//mygraphics class is from cusgraphics.h header file

class travel{
    char title_of_itinerary[50];
    char starting_point[30];
    char destination[30];
    int days;
    int expenses;
public:
    void set_val();
    void show_val(int y);
    void create_itinerary();
    void list_itinerary();
    void search_itinerary();
    void edit_itinerary();
    void delete_itinerary();
    void admin_dashboard();
    void book_form();
};

//this function sets the value of an object when called
void travel::set_val(){
    gotoxy(35,7);
    std::cout<<"Title of Itinerary: "<<flush;
    cin>>ws;
    cin.getline(title_of_itinerary, sizeof(travel));
    gotoxy(35,9);
    std::cout<<"Starting Point: ";
    gets(starting_point);
    gotoxy(35,11);
    std::cout<<"Destination: ";
    gets(destination);
    gotoxy(35,13);
    std::cout<<"Days: ";
    std::cin>>days;
    gotoxy(35,15);
    std::cout<<"Expenses: ";
    std::cin>>expenses;
}

//this function shows the value in an object
void travel::show_val(int y){
    gotoxy(17,y);
    std::cout<<title_of_itinerary;
    gotoxy(44,y);
    std::cout<<starting_point;
    gotoxy(70,y);
    std::cout<<destination;
    gotoxy(88,y);
    std::cout<<days;
    gotoxy(100,y);
    std::cout<<expenses<<"\n";
}

//this function is used to create itinerary
void travel::create_itinerary(){
    travel t;
    ofstream createfile;
    createfile.open("itinerary.txt", std::ios::out|std::ios::app|std::ios::binary);
    gotoxy(35,3);
    std::cout<<"Create Itinerary";
    maker.box(30,80,5,20);
    t.set_val();
    createfile.write((char*)&t, sizeof(t));
    createfile.close();
}

//This function is used to List Itinerary
void travel::list_itinerary(){
    ifstream fileList;
    int n=0,i=0, l=11;
    maker.box(7,110,5,28);
    gotoxy(45,3);
    std::cout<<"Itinerary List";
    fileList.open("itinerary.txt", std::ios::in);
    gotoxy(11,9);
    maker.vr(15, 8, 20);
    maker.vr(42, 8, 20);
    maker.vr(68, 8, 20);
    maker.vr(86, 8, 20);
    maker.vr(93, 8, 20);
    fileList.seekg(0, std::ios::end);
    int filesize = fileList.tellg();
    int obj = filesize/sizeof(travel);
    std::cout<<obj;
    fileList.seekg(0, std::ios::beg);
    travel t;
    fileList.read((char*)&t, sizeof(t));
    gotoxy(10,9);
    std::cout<<"S.N.";
    gotoxy(20,9);
    std::cout<<"Title of Itinerary";
    gotoxy(48,9);
    std::cout<<"Starting Point";
    gotoxy(72,9);
    std::cout<<"Destination";
    gotoxy(88,9);
    std::cout<<"Days";
    gotoxy(98,9);
    std::cout<<"Expenses\n";
    while(fileList){
        n++;
        gotoxy(11,l);
        if(n == obj){
            break;
        }
        std::cout<<n<<"\t";
        fileList.read((char*)&t, sizeof(t));
        t.show_val(l);
        l++;
    }
    fileList.close();
}

//this function is used to Search Itinerary
void travel::search_itinerary(){
    travel t;
    std::string search_item;
    int position;
    int n=0, l=11;
    search_top:
    system("cls");
    maker.box(7,110,5,28);
    gotoxy(45,3);
    std::cout<<"Search Trip\n";
    gotoxy(3,8);
    gotoxy(9,7);
    std::cout<<"Enter the keyword: ";
    getline(std::cin>>ws ,search_item);
    std::ifstream filesearch;
    filesearch.open("itinerary.txt", std::ios::in);
    gotoxy(11,9);
    maker.vr(15, 8, 20);
    maker.vr(42, 8, 20);
    maker.vr(68, 8, 20);
    maker.vr(86, 8, 20);
    maker.vr(93, 8, 20);
    gotoxy(10,9);
    std::cout<<"S.N.";
    gotoxy(20,9);
    std::cout<<"Title of Itinerary";
    gotoxy(48,9);
    std::cout<<"Starting Point";
    gotoxy(72,9);
    std::cout<<"Destination";
    gotoxy(88,9);
    std::cout<<"Days";
    gotoxy(98,9);
    std::cout<<"Expenses\n";
    while(!filesearch.eof()){
        position = filesearch.tellg();
        filesearch.read((char*)this, sizeof(travel));
        if(title_of_itinerary == search_item||starting_point == search_item||destination == search_item){
            n++;
            gotoxy(11,l);
            std::cout<<n<<"\t";
            //filesearch.read((char*)this, sizeof(t));
            gotoxy(17,l);
            std::cout<<title_of_itinerary<<"\n";
            gotoxy(44,l);
            std::cout<<starting_point<<"\n";
            gotoxy(70,l);
            std::cout<<destination<<"\n";
            gotoxy(88,l);
            std::cout<<days<<"\n";
            gotoxy(100,l);
            std::cout<<expenses<<"\n";
            l++;
        }
    }
}

//this function is used to Edit Itinerary
void travel::edit_itinerary(){
    travel t;
    int flag=0;
    fstream editfile;
    string edit_item;
    long position;
    gotoxy(35,3);
    std::cout<<"Edit Itinerary";
    maker.box(30,80,5,25);
    gotoxy(35,7);
    std::cout<<"Enter Itinerary Title: ";
    getline(cin>>ws, edit_item);
    editfile.open("itinerary.txt", std::ios::in | std::ios::out | std::ios::binary);
    while(!editfile.eof()){
        position=editfile.tellg();
        editfile.read((char*)this, sizeof(travel));
        if(title_of_itinerary == edit_item){
            gotoxy(35,9);
            std::cout<<"Enter New Details: ";
            gotoxy(35,11);
			std::cout<<"Title of itenary: ";
			cin>>ws;
            cin.getline(title_of_itinerary, sizeof(travel));
            gotoxy(35,13);
            std::cout<<"Starting point: ";
            gets(starting_point);
            gotoxy(35,15);
            std::cout<<"Destination: ";
            gets(destination);
            gotoxy(35,17);
            std::cout<<"Days: ";
            std::cin>>days;
            gotoxy(35,19);
            std::cout<<"Expenses: ";
            std::cin>>expenses;
            gotoxy(35,21);
            editfile.seekp(position);
            editfile.write((char*)this, sizeof(travel));
            flag = 1;
            break;
        }
    }

    if(flag ==0){
        gotoxy(35,23);
        std::cout<<"Entered itinerary is not found";
    }
}

//this function is used to delete Itinerary
void travel::delete_itinerary(){
    int flag=0;
	char ch;
	gotoxy(35,3);
	std::cout<<"Delete Itinerary";
	std::string dec_title;
	maker.box(20,100,5,23);
    gotoxy(25,7);
	std::cout<<"Enter the Title of itinerary that is to be deleted: ";
	getline(cin>>ws, dec_title);
	std::ifstream fin("itinerary.txt",ios::in);
	std::ofstream fout("bin.txt",ios::out);
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(travel));
		if(title_of_itinerary == dec_title) {
            gotoxy(25,9);
			std::cout<<"Title of itinerary "<<title_of_itinerary;
            gotoxy(25,10);
			std::cout<<"starting point: "<<starting_point;
			gotoxy(25,11);
			std::cout<<"Destination: "<<destination;
			gotoxy(25,13);
			std::cout<<"Days: "<<days;
			gotoxy(25,15);
			std::cout<<"Expenses: "<<expenses;
			gotoxy(25,17);
			std::cout<<"Do you want to delete this Itinerary(y/n): ";
			std::cin>>ch;
			if(ch=='n'){
				fout.write((char*)this,sizeof(travel));
			}
			flag=1;
		}else{
			fout.write((char*)this,sizeof(travel));
		}
	}

	fin.close();
	fout.close();

	if(flag==0){
	    gotoxy(25,19);
		cout<<"Sorry the trip can't be found...!!";
	}else {
		remove("itinerary.txt");
		rename("bin.txt","itinerary.txt");
	}
}

//this function is used to show the admin dashboard after login
void travel::admin_dashboard(){
    system("cls");
    gotoxy(40, 5);
    admindashboardload();
    gotoxy(45, 9);
    loading();
    admin_top:
    int in;
    system("cls");
    maker.box(30,80,5,20);
    gotoxy(35,7);
    std::cout<<"Admin Dashboard:\n\n";
    gotoxy(35,9);
    std::cout<<"1.\t Create New Itinerary\n";
    gotoxy(35,11);
    std::cout<<"2.\t Edit Itinerary\n";
    gotoxy(35,13);
    std::cout<<"3.\t Delete Itinerary\n";
    gotoxy(35,15);
    std::cout<<"4.\t Logout\n";
    gotoxy(35,17);
    std::cout<<"Enter your option:(1-4): ";
    std::cin>>in;

    switch(in){
        case 1:
            system("cls");
            gotoxy(35, 5);
            loading();
            create_itinerary();
            gotoxy(35, 17);
            std::cout<<"Itinerary is created!!";
            getch();
            goto admin_top;
            break;
        case 2:
            system("cls");
            gotoxy(35, 5);
            loading();
            edit_itinerary();
            goto admin_top;
            break;
        case 3:
            system("cls");
            gotoxy(35, 5);
            loading();
            delete_itinerary();
            goto admin_top;
            break;
        case 4:
            system("cls");
            gotoxy(35, 5);
            loading();
            break;
        default:
            system("cls");
            gotoxy(35, 5);
            loading();
            gotoxy(35, 10);
            std::cout<<"Please enter correct input";
            system("cls");
            goto admin_top;
            break;
    }
}

//this function is used for booking a trip
void travel::book_form(){
    int flag = 0;
    book_top:
    std::string search_item;
    std::string book_item_title;
    std::string book_item_start_point;
    std::string book_item_destination;
    int book_item_days;
    int book_item_expenses;
    std::string customer_name;
    int number_of_people;
    long long unsigned int phone_number=0;
    int day, month, year;

    ifstream trip_det;
    std::cout<<"Enter title of itinerary: ";
    getline(std::cin>>ws ,search_item);
    trip_det.open("itinerary.txt", std::ios::in);
    trip_det.seekg(0, std::ios::beg);
    while(!trip_det.eof()){
        trip_det.read((char*)this, sizeof(travel));
        if(title_of_itinerary == search_item){
            book_item_title = title_of_itinerary;
            book_item_start_point = starting_point;
            book_item_destination = destination;
            book_item_days = days;
            book_item_expenses = expenses;
            flag=1;
            break;
        }
    }
    trip_det.close();
    if(flag == 0){
        std::cout<<"The Itinerary is not found";
    }else{
        system("cls");
        std::cout<<"Title of itinerary: "<<book_item_title<<"\n";
        std::cout<<"Starting point: "<<book_item_start_point<<"\n";
        std::cout<<"Destination: "<<book_item_destination<<"\n";
        std::cout<<"Days: "<<book_item_days<<"\n";
        std::cout<<"Expenses: "<<book_item_expenses<<"\n";
        std::cout<<"Enter your name: ";
        getline(std::cin>>ws ,customer_name);
        std::cout<<"Enter number of people: ";
        std::cin>>number_of_people;
        date_start:
        std::cout<<"Departure Date [Please use space as separator] (yyyy-mm-dd):";
        std::cin>>year>>month>>day;
        if(date_check(year, month, day) != 1){          //date check() function is defined in function.h header file, this function checks if the entered date is correct or not
            std::cout<<"Please Enter correct date";
            goto date_start;
        }
        phone_er:
        std::cout<<"Enter your phone number: ";
        std::cin>>phone_number;
        if(phone_check(phone_number) != 1){             //phone_check() function is defined in function.h header file, this function checks if the entered phone number is correct of not
            std::cout<<"Phone Number is not correct";
            goto phone_er;
        }

        ofstream bookrec;
        bookrec.open("bookrec.txt", ios::out|ios::app);
        bookrec<<"\n=============================================================\n";
        bookrec<<"Customer Name: "<<customer_name<<"\n";
        bookrec<<"Number of people: "<<number_of_people<<"\n";
        bookrec<<"Departure Date: "<<year<<"/"<<month<<"/"<<day<<"\n";
        bookrec<<"Phone number: "<<phone_number<<"\n";
        bookrec<<"Booked item detail:- \n";
        bookrec<<"\tTitle of itinerary: "<<book_item_title<<"\n";
        bookrec<<"\tStarting point: "<<book_item_start_point<<"\n";
        bookrec<<"\tDestination: "<<book_item_destination<<"\n";
        bookrec<<"\tDays: "<<book_item_days<<"\n";
        bookrec<<"\tExpenses: "<<book_item_expenses<<"\n";
        bookrec<<"=============================================================\n";
        bookrec.close();

        std::cout<<"Your Trip has been booked. Thank you!!";
        exit(0);
    }
}

int main(){
    gotoxy(40, 5);       // gotoxy(x,y) function is defined in cusgraphics.h function, this function is used to locate the cursor at the x and y coordinate
    firstload();        //this is defined in loading.h header file
    gotoxy(45,8);
    loading();          //this is defined in loading.h header file
    top:
    travel t;
    account user;       //account class is defined in user.h header file
    int input=0;
    char ch=NULL;
    system("cls");
    gotoxy(40, 3);
    std::cout<<"Travel Management System";
    maker.box(30,80,5,20);

    gotoxy(35,7);
    std::cout<<"Main Menu \n";
    gotoxy(35,9);
    std::cout<<"1.\t Search Itinerary\n";
    gotoxy(35,11);
    std::cout<<"2.\t List Itinerary\n";
    gotoxy(35,13);
    std::cout<<"3.\t login\n";
    gotoxy(35,15);
    std::cout<<"4.\t Exit Program\n";
    gotoxy(35,17);
    std::cout<<"Enter here: ";
    std::cin>>input;

    switch (input){
    case 1:
        system("cls");
        gotoxy(35, 5);
        loading();
        t.search_itinerary();
        gotoxy(11,26);
        std::cout<<"Do you want to book: ";
        std::cin>>ch;
        if(ch == 'y'||ch=='Y'){
            t.book_form();
        }
        getch();
        goto top;
        break;
    case 2:
        system("cls");
        gotoxy(35, 5);
        loading();
        t.list_itinerary();
        gotoxy(11,26);
        std::cout<<"Do you want to book: ";
        std::cin>>ch;
        if(ch == 'y'||ch=='Y'){
            t.book_form();
        }
        getch();
        goto top;
        break;
    case 3:
        system("cls");
        gotoxy(35, 5);
        loading();
        user.login();       //this function is defined in user.h header file
        getch();
        t.admin_dashboard();
        goto top;
        break;
    case 4:
        system("cls");
        gotoxy(45, 9);
        loading();
        gotoxy(45, 9);
        std::cout<<"Thank you for using this program";
        gotoxy(45, 20);
        exit(0);        //this function exits the program
        break;
    default:
        system("cls");
        gotoxy(40, 5);
        std::cout<<"Please enter correct input";
        gotoxy(45, 9);
        loading();
        system("cls");
        goto top;
    }
    getch();
    goto top;
    return 0;
}
