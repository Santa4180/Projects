  #include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class hostel {
private:
    string name;
    int rent, bed;
public:
    hostel(string name, int rent, int bed) {
        this->name = name;
        this->rent = rent;
        this->bed = bed;
    }
    string getname() { return name; }
    int getrent() { return rent; }
    int getbed() { return bed; }

    void reserve() {
        ifstream in("D:/Hostel.txt");
        ofstream out("D:/HostelTemp.txt");

        string line;
        while (getline(in, line)) {
            int pos = line.find("KINGS PALACE");
            if (pos != string::npos) {
                int newBed = this->bed - 1;
                this->bed = newBed;  // Update object's state
                stringstream ss;
                ss << newBed;
                string strbed = ss.str();

                int bedPos = line.find_last_of(":");
                line.replace(bedPos + 1, string::npos, strbed);
            }
            out << line << endl;
        }
        out.close();
        in.close();

        remove("D:/Hostel.txt");
        rename("D:/HostelTemp.txt", "D:/Hostel.txt");
        cout << "\tBed Reserved Successfully!" << endl;
    }
};

class student {
private:
    string Name, RollNo, Address;
public:
    student() : Name(""), RollNo(""), Address("") {}

    void setName(string Name) { this->Name = Name; }
    void setRollNo(string RollNo) { this->RollNo = RollNo; }
    void setAddress(string Address) { this->Address = Address; }

    string getName() { return Name; }
    string getRollNo() { return RollNo; }
    string getAddress() { return Address; }
};

int main() {
    hostel h("KINGS PALACE", 5000, 2);
    ofstream out("D:/Hostel.txt");
    out << "\t" << h.getname() << ":" << h.getrent() << ":" << h.getbed() << endl << endl;
    out.close();
    cout << "Hostel data saved" << endl;

    student s;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to Hostel Accommodation System" << endl;
        cout << "\t*************************************" << endl;
        cout << "\t1. Reserve A Bed" << endl;
        cout << "\t2. Exit" << endl;
        cout << "\tEnter choice:" << endl;
        cin >> val;

        if (val == 1) {
            system("cls");
            string name, rollno, address;
            cout << "\tEnter name of student:" << endl;
            cin >> name;
            s.setName(name);

            cout << "Enter RollNo Of Student:";
            cin >> rollno;
            s.setRollNo(rollno);

            cout << "\tEnter address of student:";
            cin >> address;
            s.setAddress(address);

            if (h.getbed() > 0) {
                h.reserve();
                h = hostel("KINGS PALACE", h.getrent(), h.getbed() - 1); // Update object
            } else {
                cout << "No beds available" << endl;
            }

            ofstream outfile("student.txt", ios::app);
            outfile << s.getName() << ":" << s.getRollNo() << ":" << s.getAddress() << endl << endl;
            Sleep(5000);
        }
        else if (val == 2) {
            system("cls");
            exit = true;
            cout << "Good Luck" << endl;
            Sleep(3000);
        }
    }
}
   
    

