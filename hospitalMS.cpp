#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int pid;
int did;

class Patient{
    public:
    string name;
    string gender;
    int age;
    int ID;
    Patient(string n,int a,string g){
        ID = pid;
        pid++;
        name = n;
        age = a;
        gender = g;
    }
};
class Doctor{
    public:
    string name;
    string gender;
    int age;
    int ID;
     Doctor(string n,int a,string g){
        ID = pid;
        pid++;
        name = n;
        age = a;
        gender = g;
    }
};
class Appointment{
    public:
    int patientID;
    int docterID;
    string Date;
    Appointment(int p,int d,string date){
        Date = date;
        patientID=p;
        docterID=d;
    }
};
     vector<Patient>allPatients;
     vector<Doctor>allDoctors;
     vector<Appointment>allAppointments;

bool isPatientpresent(int id){
    bool ans = false;
    for(int i=0;i<allPatients.size();i++){
        if(allPatients[i].ID == id){
            ans = true;
        }
    }
    return ans;
}
bool isDoctorpresent(int id){
    bool ans = false;
    for(int i=0;i<allDoctors.size();i++){
        if(allDoctors[i].ID == id){
            ans = true;
        }
    }
    return ans;
}
void addpatient(){
    string n,g;
    int a;

    cout<<"Give The patient name:"<<endl;
    cin>>n;
    cout<<"Give The patient Age:"<<endl;
    cin>>a;
    cout<<"Give The patient Gender:"<<endl;
    cin>>g;

    Patient temp(n,a,g);
    allPatients.push_back(temp);

}
void addDoctor(){
    string n,g;
    int a;

    cout<<"Give The Doctor name:"<<endl;
    cin>>n;
    cout<<"Give The Doctor Age:"<<endl;
    cin>>a;
    cout<<"Give The Doctor Gender:"<<endl;
    cin>>g;

    Doctor temp(n,a,g);
    allDoctors.push_back(temp);

}
void ScheduleAppointments(){
    int patientID;
    int doctorID;
    string Date;

    cout<<"Give the patient ID:"<<endl;
    cin>>patientID;
    cout<<"Give the Doctor ID:"<<endl;
    cin>>doctorID;
    cout<<"Give the Date in DD-MM-YYYY:"<<endl;
    cin>>Date;

    if(isPatientpresent(patientID)==false || isDoctorpresent(doctorID)==false){
        cout<<"Invalid Patient ID or Doctor ID"<<endl;
        cout<<"Appointment Schedule unsucessful"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        return;
    }
    Appointment temp(patientID,doctorID,Date);
    allAppointments.push_back(temp);
}
void viewpatient(){
    for(int i=0;i<allPatients.size();i++){
        cout<<"Patient Name :"<<allPatients[i].name<<endl;
    }
        cout<<endl;
        cout<<endl;
        cout<<endl;
}
void viewDoctor(){
    for(int i=0;i<allDoctors.size();i++){
        cout<<"Docter Name :"<<allDoctors[i].name<<endl;
    }
        cout<<endl;
        cout<<endl;
        cout<<endl;
}
void viewAppointments(){
    for(int i=0;i<allAppointments.size();i++){
    cout<<"Patient id:"<<" "<<allAppointments[i].patientID<<" "<<"has appointment with Doctor ID:"<<allAppointments[i].docterID<<" "<<"on Date :"<<allAppointments[i].Date<<endl;
    }
        cout<<endl;
        cout<<endl;
        cout<<endl;
}
int main(){

        pid=1;
        did=1;
        int choice;

        do{
            cout<<"1. Add Patient"<<endl;
            cout<<"2. Add Doctors"<<endl;
            cout<<"3. Schedule Appointment"<<endl;
            cout<<"4. View Patients"<<endl;
            cout<<"5. View Doctors"<<endl;
            cout<<"6. View Appointment"<<endl;
            cout<<"0. Exit"<<endl;
            cout<<"Give Your Choice :"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                addpatient();
                break;
                case 2:
                addDoctor();
                break;
                case 3:
                ScheduleAppointments();
                break;
                case 4:
                viewpatient();
                break;
                case 5:
                viewDoctor();
                break;
                case 6:
                viewAppointments();
                break;
                default:
                cout<<"Invalid Choice"<<endl;

                cout<<endl;
                cout<<endl;
                cout<<endl;
            }
        }while(choice!=0);

        return 0;
}