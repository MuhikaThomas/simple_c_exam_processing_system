//Alias Mossein King //M.k
/*
you are required to dev an exam processing system for a sec school using c++. The system should
	-->Capture stud details per class
	-->capture all subjects a part. student is taking
	-->capture all marks for all subjects a student is taking
	--->grade each stident
	-->print a report card for the student
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class student{
public:
//60 is the maximumpossible number of students per class by law
string name[60], reg_no[60], stud_class, comment[60], grade[60]; 
int marks[60], avg[60], num, English[60],Kiswahili[60],Physics[60],Mathematics[60],Biology[60],Chemistry[60],History[60],Computer[60];
double mean;
public:
int studentdetails();
void marksentry();
void grading();
void reportcard();
//functions in class student
};

int main(){
	student obj;
	//obj = object for class student
	obj.studentdetails();
	obj.marksentry();
	obj.grading();
	obj.reportcard();
	
	return 0;
}

int student::studentdetails(){	
	cout<<"\n****Capture student details:**** \nClass..eg FORM 1A: \n";
	getline(cin, stud_class);
	
	cout<<"How many students are in that class: \n";
	cin>>num;
	cout<<"********\n";
	cin.ignore();//ignore the \n occuring due to use of cin>>> and getline
	for(int k=1; k<=num; k++){
		cout<<"Enter the name of student "<<k<<" :\n";
		getline(cin, name[k]);
		reg_no[k]=k;
		cout<<"Student registration number is: Stud 000"<<k<<".\n********\n";	
		
	}
	cout<<"\nThe students will be sitting for:\n1.English\t\t2.Kiswahili\n3.Physics\t\t4.Mathematics\n5.Biology\t\t6.Chemistry\n7.History\t\t8.Computer studies\n";
}

void student::marksentry(){
	cout<<"\n****Marks Entry****\n";
	for(int k =1; k<=num; k++){
		cout<<"Student name: "<<name[k]<<"\nStudent Registration: Stud 000"<<k<<"\n";
		cout<<"1. English Marks: ";
		cin>>English[k];
		cout<<"2. Kiswahili Marks: ";
		cin>>Kiswahili[k];
		cout<<"3. Physics Marks: ";
		cin>>Physics[k];
		cout<<"4. Mathematics Marks: ";
		cin>>Mathematics[k];
		cout<<"5. Biology Marks: ";
		cin>>Biology[k];
		cout<<"6. Chemistry Marks: ";
		cin>>Chemistry[k];
		cout<<"7. History Marks: ";
		cin>>History[k];
		cout<<"8. Computer study Marks: ";
		cin>>Computer[k];
		//marks
		marks[k] = English[k] + Kiswahili[k] + Physics[k] + Mathematics[k] + Biology[k] + Chemistry[k] + History[k] + Computer[k];
		avg[k] = marks[k]/8;
		cout<<"\n\n";
	}
}

void student::grading(){
	cout<<"****Grdaing****\n";
	for(int k; k<=num; k++){
		if(avg[k] < 40){
			grade[k] = "Fail";
			comment[k] = "You have to work extra harder...kapish!!";
		}
		else if(avg[k] < 50){
			grade[k] = "D";
			comment[k] = "Pass";
		}
		else if(avg[k] < 60){
			grade[k] = "C";
			comment[k] = "Good";
		}
		else if(avg[k] < 70){
			grade[k] = "B";
			comment[k] = "Very Good";
		}	
		else if(avg[k] < 100){
			grade[k] = "A";
			comment[k] = "Excellent.. Keep up the good work";
		}
		else{
			grade[k]="You have an input error";
			comment[k]="You have an input error";
		}
}
}

void student::reportcard(){
	ofstream studentfile;
	studentfile.open("Report.txt");

	cout<<"****Report card****\n";
	cout<<"\n********\n";
	
	studentfile<<"Class: "<<stud_class<<"\nNumber of students: "<<num<<"\n********\n";
	
	for(int k=1; k<=num; k++){
		cout<<"Student name: "<<name[k]<<"\nRegistration number: Stud 000"<<k<<"\n\nMarks for Term 1\n";
		cout<<"1.English: "<<English[k]<<"\t2.Kiswahili: "<<Kiswahili[k]<<"\n3.Physics: "<<Physics[k]<<"\t4.Mathematics: "<<Mathematics[k]<<"\n5.Biology: "<<Biology[k]<<"\t6.Chemistry: "<<Chemistry[k]<<"\n7.History: "<<History[k]<<"\t8.Computer studies: "<<Computer[k]<<"\n";
		cout<<"Total marks: "<<marks[k]<<"\n";
		cout<<"Mean Grade: "<<grade[k]<<"\n";
		cout<<"Comment: "<<comment[k]<<"\n";
		cout<<"********\n\n";	
		studentfile<<"Student name: "<<"Student name: "<<name[k]<<"\nRegistration number: Stud 000"<<k<<"\n\nMarks for Term 1\n";
		studentfile<<"1.English: "<<English[k]<<"\t2.Kiswahili: "<<Kiswahili[k]<<"\n3.Physics: "<<Physics[k]<<"\t4.Mathematics: "<<Mathematics[k]<<"\n5.Biology: "<<Biology[k]<<"\t6.Chemistry: "<<Chemistry[k]<<"\n7.History: "<<History[k]<<"\t8.Computer studies: "<<Computer[k]<<"\n";
		studentfile<<"Total marks: "<<marks[k]<<"\n";
		studentfile<<"Mean Grade: "<<grade[k]<<"\n";
		studentfile<<"Comment: "<<comment[k]<<"\n";
		studentfile<<"********\n\n";
	}
		cout<<"Student report card printed to file. The file is saved into Report.txt\n";
	studentfile.close();
}
