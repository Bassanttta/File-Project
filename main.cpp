#include <iostream>
#include<string>
#include<fstream>

using namespace std;

void menu () {
////////////////
cout << "***************************************************************************" << endl ;
cout << "1 - Add A New Student. " << endl ;
cout << "2 - Update A Student Data." << endl ;
cout << "3 - Remove A Student Data." << endl ;
cout << "4 - search About A Student Data." << endl ;
cout << "5 - search About A Level Data." << endl ;
cout << "6 - Print All Student Data." << endl ;
cout << "7 - Exit." << endl ;
cout << "***************************************************************************" << endl ;
////////////////
}

bool check_id( int real_id){

     ifstream f;
        f.open("data.txt", ios::in);
         int id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if (id == real_id) {
                f.close();
                return false;
            }
        }
        f.close();
return true;
}

void add_student()
{
      std::ofstream outfile;
      int num = 0;
      cout << " How Many Student You want to Add : " ; cin >> num ;
      cout << " Enter Student Data :\n  \"id, Name, level, Database, Algorithms, Math, English and Drawing\"\n ";
      ///////////////
      while(num--){
          int id , level , Database, Algorithms, Math, English, Drawing ;
          string Name ;
          ////////
          outfile.open("data.txt", std::ios_base::app);
          cin >> id >> Name >> level >> Database >>  Algorithms >> Math >>  English >> Drawing ;
          ////////
          if(check_id(id))
                outfile <<  id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
          else
                cout << "That Id is Found in The Data !" << endl;
          outfile.close();
      }
}


void file_updated(){
     ifstream f;
     std::ofstream outfile;
      int status = remove("data.txt");
     outfile.open("data.txt", std::ios_base::app);
     outfile.clear();
     ///////////////
     cout << endl ;
     /////////////////////////
     bool ok = false ;
        f.open("data_2.txt", ios::in);
         int pre_id=0 ,id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if(pre_id != id)
                 outfile <<  id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
            pre_id = id ;
        }
        f.close();
        outfile.close();

        ////////////////////////////////////////
}

void update_student(){
     ifstream f;
     std::ofstream outfile;
     outfile.open("data_2.txt", std::ios_base::app);
     ///////////////
     int find_id , pre_id =0;
     cout << "Enter the id that you Want to update it : " ; cin >> find_id ;
     cout << endl ;
     /////////////////////////
     bool ok = false ;
        f.open("data.txt", ios::in);
         int id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if(id == find_id && id != pre_id){
                cout << "Enter The New Data : " << endl ;
                cin >> id >> Name >> level >> Database >>  Algorithms >> Math >>  English >> Drawing ;
                outfile <<  id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
                ok = 1;
            }
            else
            {
                 outfile <<  id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
            }
            pre_id = id ;
        }
        f.close();
        outfile.close();
        file_updated();
        if(!ok)
            cout << "That ID is not found in the data ! " << endl ;
       int status = remove("data_2.txt");

}

void  remove_student(){
    ifstream f;
     std::ofstream outfile;
     outfile.open("data_2.txt", std::ios_base::app);
     ///////////////
     int find_id;
     cout << "Enter the id that you Want to remove it : " ; cin >> find_id ;
     cout << endl ;
     /////////////////////////
     bool ok = false ;
        f.open("data.txt", ios::in);
         int id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if(id == find_id ){
                outfile <<"" ;
                ok = 1;
            }
            else
            {
                 outfile <<  id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
            }
        }
        f.close();
        outfile.close();
        file_updated();
        if(!ok)
            cout << "That ID is not found in the data ! " << endl ;
       int status = remove("data_2.txt");

}

void search_student(){
     ifstream f;
     int find_id ;
     cout << "Enter the id that you Want to search about it : " ; cin >> find_id ;
     cout << endl ;
     /////////////////////////
     bool ok = false ;
        f.open("data.txt", ios::in);
         int pre_id =0, id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if(id == find_id && pre_id != id){
                cout << "******************** ALL THE STUDENT DATA *****************"<< endl ;
                cout << id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
                ok = 1;
            }
            pre_id = id ;
        }
        f.close();
        if(!ok)
            cout << "That ID is not found in the data ! " << endl ;
}

void search_level(){
    ifstream f;
     int find_id ;
     cout << "Enter the Level that you Want to search about it : " ; cin >> find_id ;
     cout << endl ;
     /////////////////////////
     bool ok = false ;
        f.open("data.txt", ios::in);
         int pre_id =0, id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
         cout << "******************** ALL THE STUDENT DATA *****************"<< endl ;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if(level == find_id && pre_id != id ){
                cout << id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
                ok = 1;
            }
            pre_id = id;
        }
        f.close();
        if(!ok)
            cout << "That LEVEL Has no students !!" << endl ;
}

void print_all_data(){

     ifstream f;
        f.open("data.txt", ios::in);
         int pre_id =0,id , level , Database, Algorithms, Math, English, Drawing ;
         string Name;
         cout << "******************** ALL THE STUDENTS DATA *****************"<< endl ;
        while (!f.eof())
        {
            f >> id >> Name >> level >> Database >> Algorithms >> Math >> English >> Drawing;
            if ( pre_id != id)
                cout << id << " " <<  Name << " " <<  level  << " " <<  Database << " " <<  Algorithms << " " <<  Math << " " <<  English << " " <<  Drawing << " \n"  ;
            pre_id = id;
        }
        f.close();
}

int main()
{
    ////////////////
    int option = 1 ;
    ////////////////
    while(option)
    {
        menu();
        ////////
        cout << "Enter Your Option Please : " ; cin >> option ;
        //////////
        if(option == 1 )
            add_student();
        else if(option == 2 )
            update_student();
        else if(option == 3)
            remove_student();
        else if(option == 4)
            search_student();
        else if(option == 5)
            search_level();
        else if(option == 6)
            print_all_data();
        else if ( option == 7 || option == -1)
            return cout << "***********************Thanks For Using The Application ^_^ ***********************\n***********************Good Bye*********************************" << endl ,0;
        else
            cout << "Please Make A Right choice from the Menu ! " << endl ;
    }

    return 0;
}
