#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;
void main_menu();
void add_book();
void view_all_books();
void edit_book();
void delete_book();
void search_book();
void add_library_user();
void view_library_user();
void delete_library_user();
void edit_library_user();
void issuse_book();
void delete_issue_book();
void search_library_user();
void view_all_issused_books();
void clear_data();
struct book
{
	char book_name[100];
	int ISBN;
	char author_name[100];
	int no_of_copies;
	string date_of_issue;
	char publisher_name[100];
};
struct user_st
{
	char user_name[100];
	int user_id;
	char user_L_name[100];
	string date_brith;
	string student = "Student";
	string Empolyer = "Empolyer";
};
struct book_issue
{
	char book_name[100];
	int isbn;
	int user_id;
	char book_author[100];
	char user_name[100];
	char user_L_name[100];

};
int main()
{
	main_menu();
}
void main_menu()
{
	system("color 2F ");
	book obj;
	user_st obj1;
	system("cls");
	int i, j, k;
	i = j = k = 0;
	//    here while loop is use to represent the data in file mean total number of books etc
	ifstream filedata("book_data.txt");
	while (filedata >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		i++;
	}
	filedata.close();
	ifstream user("library_user.txt ");
	while (user >> obj1.user_id >> obj1.user_name >> obj1.user_L_name >> obj1.Empolyer >> obj1.date_brith)
	{
		j++;
	}
	user.close();
	book_issue obj3;
	ifstream iss("issue_books.txt");

	while (iss >> obj3.isbn >> obj3.book_name >> obj3.user_id >> obj3.user_name >> obj3.user_L_name)
	{
		k++;
	}
	iss.close();
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Muhammad Abdullah " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "Press option key to activate that function  " << endl << endl << endl;
	cout << "\t(0). To view all book" << endl;
	cout << "\t(1).  Add New Book " << "( Total # of books = " << i << " )" << endl;
	cout << "\t(2).  Edit Book" << endl;
	cout << "\t(3).  Delete Book " << endl;
	cout << "\t(4).  Search Book " << endl;
	cout << "\t(5).  Add Library User  " << "(Total # of user = " << j << " )" << endl;
	cout << "\t(6).  View all Library User" << endl;
	cout << "\t(7).  Edit Library User" << endl;
	cout << "\t(8).  Delete Library User" << endl;
	cout << "\t(9).  Search Library User" << endl;
	cout << "\t(10).  Issue Book " << "( Total # of issue books = " << k << " )" << endl;
	cout << "\t(11). Delete Issued Book " << endl;
	cout << "\t(12).  View all Issused books " << endl;
	cout << "\t(13).  Delete All Data ( reset ) " << endl;
	cout << "\t(14). About Creater and designer " << endl;
	cout << "\t(15). Exit from programme" << endl << endl << endl;
	i = j = k = 0;

	int sel;
	cout << "Enter Your Choice ! " << endl;
	cin >> sel;
	while (sel < 0 || sel>15)
	{
		cout << "WRONG INPUT...!  PLEASE Select from Above ! " << endl;
		cin >> sel;
	}
	switch (sel)
	{
	case 0: {         view_all_books();

		break;
	}
	case 1: {        add_book();

		break;
	}
	case 2: {        edit_book();

		break;
	}
	case 3: {           delete_book();

		break;
	}
	case 4: {            search_book();

		break;
	}
	case 5: {            add_library_user();

		break;
	}
	case 6: {            view_library_user();

		break;
	}
	case 7: {          edit_library_user();

		break;
	}
	case 8: {          delete_library_user();
		break;
	}
	case 9: {           search_library_user();

		break;
	}
	case 10: {         issuse_book();

		break;
	}
	case 11: {        delete_issue_book();

		break;
	};
	case 12: {        view_all_issused_books();

		break;
	};
	case 13: {        clear_data();
		break;
	}
	case 14: { system("cls");
		cout << "\t\tThe Library mangement system";
		cout << "\n\n\t\tThis Project is made by Muhammad Abdullah \n\t\tBSCS 1ST SELF\tBSC51F21S015\n\t\tfor any qurries TEXT me\t|03464965745|" << endl;
		cout << endl << endl << endl << "Press 0 to goback" << endl;
		cin >> sel;
		if (sel == 0)
			main_menu();
		break;
	}
	case 15: { exit(0);
		break;
	}
	}
}
void add_book()
{
loop:
	char ch;
	book obj, abj;
	system("cls");
	system("color 3D");
	bool flag = false;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	ifstream oldfile("book_data.txt");
	cout << "Enter book name :\t";
	cin >> obj.book_name;
	cout << "Enter  ISBN number :\t";
	cin >> obj.ISBN;
	cout << "Enter Author name :\t";
	cin >> obj.author_name;
	cout << "Enter publisher name :\t";
	cin >> obj.publisher_name;
	cout << "Enter Year of publish : \t";
	cin >> obj.date_of_issue;
	cout << "Enter Totals number of copies :\t";
	cin >> obj.no_of_copies;
	while (oldfile >> abj.ISBN >> abj.book_name >> abj.author_name >> abj.publisher_name >> abj.date_of_issue >> abj.no_of_copies)
	{
		if (obj.ISBN == abj.ISBN)
		{
			flag = true;
		}
	}
	oldfile.close();
	cout << endl << endl << endl;
	cout << endl << endl << "Do want to save book information Y/N" << endl;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		if (flag == true)
		{
			cout << "The book with this ISBN is already exist so this data is not added" << endl;
		}
		else if (flag != true) {
			ofstream myfile("book_data.txt", ios::app);
			myfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
			myfile.close();
			cout << "The book is not dublicate " << endl;
			cout << "\nThe book information is successfully added" << endl;
		}
		cout << "\n\nPress Y to add more book or N to go main menu " << endl;
		cin >> ch;
		flag = false;
		if (ch == 'y' || ch == 'Y')
			goto loop;
		if (ch == 'n' || ch == 'N')
			main_menu();
	}
	if (ch == 'n' || ch == 'N')
	{
		cout << "\nThe book data is not added " << endl;
		cout << "\n\nPress Y to add new book or N to go main menu " << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			goto loop;
		if (ch == 'n' || ch == 'N')
			main_menu();
	}

}
void view_all_books()
{
	system("cls");
	system("color 4B");
	book obj;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "\n\n___________________ALL BOOKS_________________" << endl << endl;
	cout << "ISBN|" << setw(15) << "Book_name|" << setw(15) << "Author_name|" << setw(15) << "Publisher_name|" << setw(15) << "Year_of_publish|" << setw(15) << "Total coppies #  | " << endl << endl;

	ifstream filedata("book_data.txt");
	while (filedata >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		cout << obj.ISBN << "|" << setw(15) << obj.book_name << "|" << setw(15) << obj.author_name << "|" << setw(15) << obj.publisher_name << "|" << setw(15) << obj.date_of_issue << "|" << setw(15) << obj.no_of_copies << "|" << endl;
	}
	filedata.close();
	int ch;
	cout << "\n\n\nPress 0 to go back or want to want new book Press 1 " << endl;
	cin >> ch;
	if (ch == 0)
		main_menu();
	if (ch == 1)
		add_book();

}
void edit_book()
{
	system("cls");
	system("color 5E");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
loop:
	bool flag = false;

	int ch;
	book obj;
	char s1[100];
	cout << "Press option to access book by its \t(1). By ISBN \t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		int isbn;
		ifstream myfile("book_data.txt");  //note name must be same
		ofstream newfile("new.txt");
		cin >> isbn;
		while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
		{
			if (isbn == obj.ISBN)
			{
				cout << "Enter book new name :\t";
				cin >> obj.book_name;
				cout << "Enter  ISBN new number :\t";
				cin >> obj.ISBN;
				cout << "Enter Author name :\t";
				cin >> obj.author_name;
				cout << "Enter publisher name :\t";
				cin >> obj.publisher_name;
				cout << "Enter date of published : \t";
				cin >> obj.date_of_issue;
				cout << "Enter Totals number of copies :\t";
				cin >> obj.no_of_copies;
				flag = true;

			}
			newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;

		}
		newfile.close();
		myfile.close();
		if (flag != true)
		{
			cout << "The book Does not exist" << endl;
			remove("new.txt");
		}
		if (flag == true) {

			if (remove("book_data.txt") != 0) {
				cout << "File not removed " << endl;
			}
			else if (rename("new.txt", "book_data.txt") != 0) {
				cout << "File not renamed " << endl;
			}
			else {
				cout << "The book data is succeefully Edited" << endl << endl;
				flag = false;
			}
		}

	}
	if (ch == 2)
	{
		ifstream myfile("book_data.txt");  //note name must be same
		cout << "Please Enter book name : ";
		cin >> s1;
		int counter = 0;

		while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
		{
			if (strcmp(obj.book_name, s1) == 0)
			{
				++counter;
			}
		}
		myfile.close();
		if (counter == 0)
		{
			cout << "The book with this name is not exist sorry " << endl;
		}
		if (counter == 1)
		{
			ofstream newfile("new.txt");
			ifstream myfile("book_data.txt");  //note name must be same
			while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (strcmp(obj.book_name, s1) == 0)
				{

					cout << "Enter book new name :\t";
					cin >> obj.book_name;
					cout << "Enter  ISBN new number :\t";
					cin >> obj.ISBN;
					cout << "Enter Author name :\t";
					cin >> obj.author_name;
					cout << "Enter publisher name :\t";
					cin >> obj.publisher_name;
					cout << "Enter date of published : \t";
					cin >> obj.date_of_issue;
					cout << "Enter Totals number of copies :\t";
					cin >> obj.no_of_copies;
					flag = true;
				}
				newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;

			}
			newfile.close();
			myfile.close();

		}
		if (counter > 1)
		{
			flag = false;
			ofstream newfile("new.txt");
			ifstream myfile("book_data.txt");  //note name must be same

			cout << "ISBN|" << setw(15) << "Book_name|" << setw(15) << "Author_name|" << setw(15) << "Publisher_name|" << setw(15) << "Year_of_publish|" << setw(15) << "Total coppies #  | " << endl << endl;
			while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (strcmp(obj.book_name, s1) == 0)
				{
					cout << obj.ISBN << "|" << setw(15) << obj.book_name << "|" << setw(15) << obj.author_name << "|" << setw(15) << obj.publisher_name << "|" << setw(15) << obj.date_of_issue << "|" << setw(15) << obj.no_of_copies << "|" << endl;
				}
			}
			myfile.close();
			int number;
			cout << "________________________________________________________________________________________________________________" << endl;
			cout << endl << endl << "PLease Enter ISBN number from above : ";
			cin >> number;
			ifstream myfile3("book_data.txt");  //note name must be same
			while (myfile3 >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (number == obj.ISBN)
				{
					cout << "Enter book new name :\t";
					cin >> obj.book_name;
					cout << "Enter  ISBN new number :\t";
					cin >> obj.ISBN;
					cout << "Enter Author name :\t";
					cin >> obj.author_name;
					cout << "Enter publisher name :\t";
					cin >> obj.publisher_name;
					cout << "Enter date of published : \t";
					cin >> obj.date_of_issue;
					cout << "Enter Totals number of copies :\t";
					cin >> obj.no_of_copies;
					flag = true;
				}
				newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
			}

			newfile.close();
			myfile.close();

		}

	}
	if (flag == true)
	{

		if (remove("book_data.txt") != 0)
		{
			cout << "File not removed " << endl;
		}
		else if (rename("new.txt", "book_data.txt") != 0)
		{
			cout << "file not renamed " << endl;
		}
		else {
			cout << "The book data is succeefully Edited" << endl << endl;
		}
	}
	cout << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
	cin >> ch;
	if (ch == 0)
		main_menu();
	if (ch == 1)
		goto loop;
}
void delete_book()
{

loop:
	system("cls");
	system("color 3E");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int ch;
	bool flag = false;
	book obj;
	int isbn;
	char s1[100];
	char book_n[100];
	cout << "Press option to access book by its \t(1). By ISBN \t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		cin >> isbn;


		ifstream myfile("book_data.txt");  //note name must be same
		ofstream newfile("new.txt");
		while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
		{
			if (isbn != obj.ISBN)
			{
				newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
			}
			if (isbn == obj.ISBN)
			{
				flag = true;
			}

		}

		if (flag != true)
		{
			cout << "The data against this book is not found" << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
			cin >> ch;
			if (ch == 0)
				main_menu();
			if (ch == 1)
				goto loop;
		}

		else {
			newfile.close();
			myfile.close();
			if (remove("book_data.txt") != 0)
				cout << "File not removed " << endl;
			if (rename("new.txt", "book_data.txt") != 0)

				cout << "file not renamed " << endl;
			else {
				cout << "The book data is succeefully Deleted" << endl << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
				cin >> ch;
				if (ch == 0)
					main_menu();
				if (ch == 1)
					goto loop;
			}
		}
	}
	if (ch == 2)
	{
		ifstream myfile("book_data.txt");  //note name must be same
		cout << "Please Enter book name : ";
		cin >> s1;
		int counter = 0;

		while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
		{
			if (strcmp(obj.book_name, s1) == 0)
			{
				++counter;
			}
		}
		myfile.close();
		if (counter == 0)
		{
			cout << "The book with this name is not exist sorry " << endl;
		}
		if (counter == 1)
		{
			ofstream newfile("new.txt");
			ifstream myfile("book_data.txt");  //note name must be same
			while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (strcmp(obj.book_name, s1) != 0)
				{
					newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
					flag = true;
				}

			}
			newfile.close();
			myfile.close();

		}
		if (counter > 1)
		{
			flag = false;
			ofstream newfile("new.txt");
			ifstream myfile("book_data.txt");  //note name must be same

			cout << "ISBN|" << setw(15) << "Book_name|" << setw(15) << "Author_name|" << setw(15) << "Publisher_name|" << setw(15) << "Year_of_publish|" << setw(15) << "Total coppies #  | " << endl << endl;
			while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (strcmp(obj.book_name, s1) == 0)
				{
					cout << obj.ISBN << "|" << setw(15) << obj.book_name << "|" << setw(15) << obj.author_name << "|" << setw(15) << obj.publisher_name << "|" << setw(15) << obj.date_of_issue << "|" << setw(15) << obj.no_of_copies << "|" << endl;
				}
			}
			myfile.close();
			int number;
			cout << "________________________________________________________________________________________________________________" << endl;
			cout << endl << endl << "PLease Enter ISBN number from above of book which want to delete : ";
			cin >> number;
			ifstream myfile3("book_data.txt");  //note name must be same
			while (myfile3 >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
			{
				if (number != obj.ISBN)
				{
					newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;

					flag = true;
				}
			}

			newfile.close();
			myfile.close();

		}


		if (flag == true)
		{

			if (remove("book_data.txt") != 0)
			{
				cout << "File not removed " << endl;
			}
			else if (rename("new.txt", "book_data.txt") != 0)
			{
				cout << "file not renamed " << endl;
			}

		}
		cout << "The book data is succeefully Deleted" << endl << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
		cin >> ch;
		if (ch == 0)
			main_menu();
		if (ch == 1)
			goto loop;

	}
}
void search_book()
{
loop:
	bool flag = false;
	system("cls");
	system("color 6B");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int ch;
	book obj;
	int isbn;
	char s1[100];
	cout << "Press option to access book by its \n\t(1). By ISBN \n\t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		cin >> isbn;
	}
	if (ch == 2) {
		cout << "Enter book name " << endl;
		cin >> s1;
	}
	ifstream myfile("book_data.txt");  //note name must be same
	while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		if (isbn == obj.ISBN || strcmp(obj.book_name, s1) == 0)
		{
			flag = true;
			cout << "ISBN|" << setw(15) << "Book_name|" << setw(15) << "Author_name|" << setw(15) << "Publisher_name|" << setw(15) << "Year_of_publish|" << setw(15) << "Total coppies #  | " << endl << endl;
			cout << obj.ISBN << "|" << setw(15) << obj.book_name << "|" << setw(15) << obj.author_name << "|" << setw(15) << obj.publisher_name << "|" << setw(15) << obj.date_of_issue << "|" << setw(15) << obj.no_of_copies << "|" << endl;

		}
	}
	myfile.close();
	if (flag == false)
	{
		cout << "The data against this book is not found" << endl << endl;
	}

	cout << endl << endl << "Press 0 to go back to main menu OR Press 1  to search again book" << endl;
	cin >> ch;
	if (ch == 0)
		main_menu();
	if (ch == 1)
		goto loop;

}
void add_library_user()
{
loop1:

	system("cls");
	system("color 7C");
	int pass = 12345;
	int word;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "Enter password Keys to add user " << endl;
	cin >> word;
	if (word == 0)
		main_menu();
	if (pass == word)
	{
	loop:
		bool flag = false;

		int ch;
		user_st obj, abj;
		cout << "(1). for student" << endl << "(2). for Empolyer" << endl;
		cin >> ch;
		if (ch == 1)
		{
			system("cls");
			cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
			cout << "************************************************************************************************\n\n" << endl;
			ifstream datafile("library_user.txt");
			cout << "Please enter requried information " << endl << endl;
			cout << "Enter Student first name :  \t";
			cin >> obj.user_name;
			cout << "Enter Student Last name : \t ";
			cin >> obj.user_L_name;
			cout << "Enter Library ID : \t";
			cin >> obj.user_id;
			cout << "Enter student Age :\t";
			cin >> obj.date_brith;
			while (datafile >> abj.user_id >> abj.user_name >> abj.user_L_name >> abj.student >> abj.date_brith)
			{
				if (abj.user_id == obj.user_id)
				{
					flag = true;
				}
			}
			datafile.close();
			if (flag != true)
			{
				ofstream library_user("library_user.txt", ios::app);
				library_user << obj.user_id << "\t" << obj.user_name << " " << obj.user_L_name << "\t" << obj.student << "\t" << obj.date_brith << endl;
				library_user.close();
				cout << "The user has successfully added" << endl;
			}
			if (flag == true)
			{
				cout << "The against this ID is already Exist " << "\tThe data is not added" << endl;
			}
			cout << "\n\nPress (1) to add again  or press (0) to go back to main menu" << endl;
			cin >> ch;
			if (ch == 1)
				goto loop;
			if (ch == 0)
				main_menu();
		}
		else if (ch == 2)
		{
			flag = false;

			system("cls");
			cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
			cout << "************************************************************************************************\n\n" << endl;
			ifstream datafile("library_user.txt");

			cout << "Please enter requried information " << endl << endl;
			cout << "Enter Employer first name :  \t";
			cin >> obj.user_name;
			cout << "Enter Empolyer Last name : \t ";
			cin >> obj.user_L_name;
			cout << "Enter Library ID : \t";
			cin >> obj.user_id;
			cout << "Enter Empolyer Age :\t";
			cin >> obj.date_brith;
			while (datafile >> abj.user_id >> abj.user_name >> abj.student >> abj.date_brith)
			{
				if (abj.user_id == obj.user_id)
				{
					flag = true;
				}
			}
			datafile.close();
			if (flag != true)
			{
				ofstream library_user("library_user.txt", ios::app);
				library_user << obj.user_id << "\t" << obj.user_name << " " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;
				library_user.close();
				cout << "The user has successfully added" << endl;
			}
			if (flag == true)
			{
				cout << "The against this ID is already Exist " << "\tThe data is not added" << endl;
			}
			flag = false;
			cout << "\n\nPress (1) to add again  or press (0) to go back to main menu" << endl;
			cin >> ch;
			if (ch == 1)
				goto loop;
			if (ch == 0)
				main_menu();

		}
	}
	else if (word != pass)
	{
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}
}
void view_library_user()
{
	system("cls");
	system("color 3F");
	int pass = 12345;
	user_st obj;
	int word;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "Enter password Keys to View all user " << endl;
loop1:
	cin >> word;
	if (pass == word) {
		system("cls");
		cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
		cout << "************************************************************************************************\n\n" << endl;
		ifstream user("library_user.txt ");
		cout << " ID#" << setw(15) << "Name" << setw(30) << "Student or Empolyer" << setw(15) << "Age# |" << endl << endl;
		while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
		{
			cout << obj.user_id << setw(15) << obj.user_name << " " << obj.user_L_name << setw(20) << obj.Empolyer << setw(15) << obj.date_brith << " |" << endl;
		}
		user.close();
		int ch;
		cout << "\n\n\nPress 0 to go back or want to add new user Press 1 " << endl;
		cin >> ch;
		if (ch == 0)
			main_menu();
		if (ch == 1)
			add_library_user();

	}
	else if (pass != word)
	{
		system("cls");
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}
}
void delete_library_user()
{
	system("cls");
	system("color 8F");
	int pass = 12345;
	user_st obj;

	int word;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "Enter password Keys to Delete user " << endl;
loop1:
	cin >> word;
	if (word == 0)
		main_menu();
	if (pass == word) {
		system("cls");
		bool flag = false;
		cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
		cout << "************************************************************************************************\n\n" << endl;
		int ch3;
		cout << "Access User by its \n\t(1). ID\n\t(2). Name " << endl;
		cin >> ch3;
		if (ch3 == 1)
		{
		    		int user_id;
			cout << "Please Enter user id which you want remove user" << endl;
			cin >> user_id;
			ifstream user("library_user.txt ");
			ofstream newfile("new.txt");
			while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
			{
				if (obj.user_id != user_id )
				{
					newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;
				}
				if (obj.user_id == user_id)
				{
					flag = true;

				}
			}
			newfile.close();
			user.close();


			if (flag == true)
			{
				if (remove("library_user.txt") != 0)
					cout << "File not removed " << endl;
				else if (rename("new.txt", "library_user.txt") != 0)

					cout << "file not renamed " << endl;

				cout << "The Data of this is succeefully deleted" << endl;
			}
			if (flag != true)
			{
				cout << "The record against this data is not found" << endl;
			}
			int ch;

			cout << "\n\n\nPress 0 to go back or want to want new User Press 1 " << endl;
			cin >> ch;
			if (ch == 0)
				main_menu();
			if (ch == 1)
				add_library_user();
		}
		else if(ch3==2)
		{
			cout << "Please Enter First user name :\t";
			char name[100];
			cin >> name;
			int counter = 0;
			ifstream user("library_user.txt");
			while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
			{
				if (strcmp(name, obj.user_name) == 0)
				{
					counter++;
				}
			}
			user.close();
			if (counter == 0)
			{
				cout << "The user with This name is not found " << endl;
			}
			if (counter == 1)
			{
				ofstream newfile("new.txt");
				ifstream user1("library_user.txt");
				while (user1 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if ( strcmp(name, obj.user_name) != 0)
					{
						flag = true;
						newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

					}

				}
				newfile.close();
				user1.close();
			}
			if (counter > 1)
			{
				ifstream user2("library_user.txt ");
				cout << " ID#" << setw(15) << "Name" << setw(30) << "Student or Empolyer" << setw(15) << "Age# |" << endl << endl;
				while (user2 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if (strcmp(name, obj.user_name) == 0)
					{
						cout << obj.user_id << setw(15) << obj.user_name << " " << obj.user_L_name << setw(20) << obj.Empolyer << setw(15) << obj.date_brith << " |" << endl;
					}
				}
				user2.close();
				cout << endl << endl << "Please Enter user id from above which want you to Deleted" << endl;
				int user_id;
				cin >> user_id;
				ifstream user3("library_user.txt");
				ofstream newfile("new.txt");
				while (user3 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if (obj.user_id != user_id)
					{
						flag = true;
						newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

					}

				}
				newfile.close();
				user3.close();

			}

			if (flag == true)
			{

				if (remove("library_user.txt") != 0)
					cout << "File not removed " << endl;
				else if (rename("new.txt", "library_user.txt") != 0)
					cout << "file not renamed " << endl;

				cout << "The User data is succeefully Updated" << endl << endl;

			}
		}

			int ch4;
		cout << "\n\n\nPress 0 to go back or want to see all User Press 1 " << endl;
		cin >> ch4;
		if (ch4 == 0)
			main_menu();
		if (ch4 == 1)
			view_library_user();

	}
else if (pass != word)
	{

		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}

}
void search_library_user()
{
loop:
	system("cls");
	system("color 6E");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int ch;
	bool flag = false;
	user_st obj;
	int id;
	char s1[100];
	char book_n[100];
	cout << "Press option to delete user by its \n\t(1). By ID \n\t(2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter User iD " << endl;
		cin >> id;
	}
	if (ch == 2) {
		cout << "Enter user name " << endl;
		cin >> s1;
	}
	ifstream myfile("library_user.txt");  //note name must be same
	while (myfile >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
	{
		if (id == obj.user_id  ||  strcmp(s1,obj.user_name)==0)
		{
			cout << " ID#\t\t" << "Name\t\t" << "Student or Empolyer\t" << "Age#\t" << endl << endl;
			cout << obj.user_id << "\t\t" << obj.user_name << "   " << obj.user_L_name << "\t\t" << obj.Empolyer << "\t\t" << obj.date_brith << endl;
			flag = true;
		}
	}
	myfile.close();
	if (flag != true)
	{
		cout << "The record against this data is not found " << endl;
	}
	cout << endl << endl << "Press 0 to go back to main menu OR Press 1  to search again book" << endl;
	cin >> ch;
	if (ch == 0)
		main_menu();
	if (ch == 1)
		goto loop;
}
void edit_library_user()
{
	system("cls");
	system("color 4B");
	int pass = 12345;
	user_st obj;
	int word;
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	cout << "Enter password Keys to Edit user " << endl;
	loop:
	cin >> word;
	if (word == 0)
		main_menu();
	bool flag = false;
	if (pass == word) {
		system("cls");
		cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
		cout << "************************************************************************************************\n\n" << endl;
		cout << "\t(1). Edit by name /n/t(2). EDit by user id" << endl;
		int ch;
		cin >> ch;
		if (ch == 2)
		{

			ifstream user("library_user.txt ");
			ofstream newfile("new.txt");
			string student = "Student";
			int user_id;
			cout << "Please Enter user id which you want remove user" << endl;
			cin >> user_id;

			while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
			{
				if (obj.user_id == user_id)
				{
					flag = true;
					cout << "Enter  new first name :  \t";
					cin >> obj.user_name;
					cout << "Enter Last new name : \t ";
					cin >> obj.user_L_name;
					cout << "Enter Library new ID : \t";
					cin >> obj.user_id;
					cout << "Enter new Age :\t";
					cin >> obj.date_brith;
				}
				newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

			}
			newfile.close();
			user.close();
			if (flag != true)
			{
				cout << "The record this Data is not found" << endl;
			}
			if (remove("library_user.txt") != 0)
				cout << "File not removed " << endl;
			else if (rename("new.txt", "library_user.txt") != 0)
				cout << "file not renamed " << endl;
			else {
				cout << "The User data is succeefully Updated" << endl << endl;
				int ch;
				cout << "\n\n\nPress 0 to go back or want to see all User Press 1 " << endl;
				cin >> ch;
				if (ch == 0)
					main_menu();
				if (ch == 1)
					view_library_user();
			}
		}
		else
		{
			cout << "Please Enter First user name :\t";
			char name[100];
			cin >> name;
			int counter = 0;
			ifstream user("library_user.txt");
			while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
			{
				if (strcmp(name, obj.user_name) ==0 )
				{
					counter++;
				}
			}
			user.close();
			if (counter == 0)
			{
				cout << "The user with This name is not found " << endl;
			}
			if (counter == 1)
			{
				ofstream newfile("new.txt");
				ifstream user1("library_user.txt");
				while (user1 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if (strcmp( name, obj.user_name )==0 )
					{
						flag = true;
						cout << "Enter  new first name :  \t";
						cin >> obj.user_name;
						cout << "Enter Last new name : \t ";
						cin >> obj.user_L_name;
						cout << "Enter Library new ID : \t";
						cin >> obj.user_id;
						cout << "Enter new Age :\t";
						cin >> obj.date_brith;
					}
					newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

				}
				newfile.close();
				user1.close();
			}
			if (counter > 1)
			{
				ifstream user2("library_user.txt ");
				cout << " ID#" << setw(15) << "Name" << setw(30) << "Student or Empolyer" << setw(15) << "Age# |" << endl << endl;
				while (user2 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if ( strcmp(name, obj.user_name) == 0 )
					{
						cout << obj.user_id << setw(15) << obj.user_name << " " << obj.user_L_name << setw(20) << obj.Empolyer << setw(15) << obj.date_brith << " |" << endl;
					}
				}
				user2.close();
				cout << endl << endl << "Please Enter user id from above which want you to edited" << endl;
				int user_id;
				cin >> user_id;
				ifstream user3("library_user.txt");
				ofstream newfile("new.txt");
				while (user3 >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
				{
					if (obj.user_id == user_id)
					{
						flag = true;
						cout << "Enter  new first name :  \t";
						cin >> obj.user_name;
						cout << "Enter Last new name : \t ";
						cin >> obj.user_L_name;
						cout << "Enter Library new ID : \t";
						cin >> obj.user_id;
						cout << "Enter new Age :\t";
						cin >> obj.date_brith;
					}
					newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

				}
				newfile.close();
				user3.close();

			}

			if (flag == true)
			{

				if (remove("library_user.txt") != 0)
					cout << "File not removed " << endl;
				else if (rename("new.txt", "library_user.txt") != 0)
					cout << "file not renamed " << endl;

				cout << "The User data is succeefully Updated" << endl << endl;

			}

		}


		int ch4;
		cout << "\n\n\nPress 0 to go back or want to see all User Press 1 " << endl;
		cin >> ch;
		if (ch4 == 0)
			main_menu();
		if (ch4 == 1)
			view_library_user();
	}



	else if (pass != word)
	{
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop;

	}
}
void issuse_book()
{

	system("cls");
	system("color 7D");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int USER_ID;
loop:
	cout << "Enter user ID to issue book or Enter 0 to goback:\t";
	cin >> USER_ID;
	user_st obj;
	if (USER_ID == 0)
	{
		main_menu();
	}
	bool flag = false;
	ifstream user("library_user.txt");
	while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
	{
		if (USER_ID == obj.user_id)
		{
			flag = true;
			break;
		}
	}
	user.close();
	if (flag != true)
	{
		cout << "The data against this ID is not found" << endl;
		goto loop;
	}
	if (flag == true)
	{
		bool flag2 = false;
		book books;
		cout << "ISBN|" << setw(15) << "Book_name|" << setw(15) << "Author_name|" << setw(15) << "Publisher_name|" << setw(15) << "Year_of_publish|" << setw(15) << "Total coppies #  | " << endl << endl;

		ifstream filedata("book_data.txt");
		while (filedata >> books.ISBN >> books.book_name >> books.author_name >> books.publisher_name >> books.date_of_issue >> books.no_of_copies)
		{
			cout << books.ISBN << "|" << setw(15) << books.book_name << "|" << setw(15) << books.author_name << "|" << setw(15) << books.publisher_name << "|" << setw(15) << books.date_of_issue << "|" << setw(15) << books.no_of_copies << "|" << endl;
		}
		filedata.close();
	loop2:

		int BOOK_ISBN;
		cout << "Please Enter Book ISBN number from above" << endl;
		cin >> BOOK_ISBN;
		ifstream filedata2("book_data.txt");
		while (filedata2 >> books.ISBN >> books.book_name >> books.author_name >> books.publisher_name >> books.date_of_issue >> books.no_of_copies)
		{
			if (BOOK_ISBN == books.ISBN)
			{
				flag2 = true;
				break;
			}
		}
		filedata.close();
		if (flag2 != true)
		{
			cout << "Please enter valid ISBN from below or enter 0 to go back " << endl;
			goto loop2;
		}
		if (flag2 == true)
		{
			ofstream iss("issue_books.txt", ios::app);
			iss << books.ISBN << "\t" << books.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;
			cout << "The book " << books.book_name << " has been issused to user " << obj.user_name << obj.user_L_name << " successfully " << endl;
			iss.close();
			int ch;
			cout << "\n\nEnter 0 to go back or 1 to issuse book again :\t";
			cin >> ch;
			if (ch == 1)
			{
				issuse_book();
			}
			else
			{
				main_menu();
			}
		}

	}

}
void delete_issue_book()
{
	system("cls");
	system("color 6E");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int USER_ID;
	cout << "Enter user id or enter 0 to go back : ";
	cin >> USER_ID;
	bool flag;

	if (USER_ID == 0)
	{
		main_menu();
	}
	book_issue obj;
	ifstream iss("issue_books.txt");
	while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
	{
		if (USER_ID == obj.user_id)
		{
			flag = true;
			break;

			cout << obj.isbn << "\t" << obj.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;

			ofstream newfile("new.txt", ios::app);


			while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
			{
				if (USER_ID != obj.user_id)
				{
					newfile << obj.isbn << "\t" << obj.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;

				}
			}

		}
		else
		{
			flag = false;
		}
	}
	iss.close();

	if (flag == false)
	{
		cout << "The data against this id not found!!!" << endl;
	}
	if (flag == true)
	{
		cout << "Do you really want to delete this data Y/N " << endl;
		char ch2;
		cin >> ch2;
		if (ch2 == 'y' || ch2 == 'Y')
		{
			if (remove("issue_books.txt") != 0)
				cout << "File not removed " << endl;
			else if (rename("new.txt", "issue_books.txt") != 0)
				cout << "file not renamed " << endl;
			else
			{
				cout << "The data against this id is successfully removed" << endl;

			}
		}
		else
		{
			remove("new.txt");
			cout << "The data not deleted" << endl;

		}
	}
	cout << "Press 1 to delete issuse book again or press 0 to to back" << endl;
	int ch;
	cin >> ch;
	if (ch == 1)
	{
		delete_issue_book();

	}
	else
	{
		main_menu();
	}
}
void view_all_issused_books()
{

	system("cls");
	system("color 7D");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	book_issue obj;
	ifstream iss("issue_books.txt");
	cout << "ISBN|\t" << "Book_Name|\t\t" << "User_ID #|\t" << "User_name" << endl;

	while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
	{
		cout << obj.isbn << "|\t" << obj.book_name << "|\t\t\t" << obj.user_id << "|\t\t" << obj.user_name << "  " << obj.user_L_name << endl;
	}
	iss.close();
	cout << "Press 1 to delete issuse book again or press 0 to to back" << endl;
	int ch;
	cin >> ch;
	if (ch == 1)
	{
		delete_issue_book();

	}
	else
	{
		main_menu();
	}
}

void clear_data()
{
loop:
	system("cls");
	system("color 9F");
	cout << "************************************************************************************************" << endl << "\t\tLibrary Mangemanent System" << endl << "\t\t By Chaudhry Ayaz " << endl;
	cout << "************************************************************************************************\n\n" << endl;
	int pass = 3232;
	int word;
	cout << "Enter The password" << endl;
	cin >> word;
	if (pass == word)
	{
		cout << "Do you really want to delete all data Y/N" << endl;
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			ofstream myfile1("book_data.txt", ios::trunc);
			ofstream myfile2("issue_books.txt", ios::trunc);
			ofstream myfile3("library_user.txt ", ios::trunc);
			myfile1.close();
			myfile2.close();
			myfile3.close();
			main_menu();
		}
	}
	else if (pass != word)
	{
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop;
	}
	else if (word == 0)
		main_menu();
}
