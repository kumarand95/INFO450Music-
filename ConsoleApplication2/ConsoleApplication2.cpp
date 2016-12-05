

#include "stdafx.h"

#include<iostream>

#include<fstream>

#include <sstream>

#include <string>

using namespace std;



stringstream MyMusicList;

string MySongs;

int songN = 1;

class Node

{

	string Data;

	Node* type;

public:

	Node() {};

	void SetSong(string aFile) { Data = aFile; };

	void SetNextSong(Node* aType) { type = aType; };

	string File() { return Data; };

	Node* Type() { return type; };

};

class List

{

	Node *head;

public:

	List() { head = NULL; };

	void DisplayListSongs();

	void playMyList();

	void addSong(string Data);

	void deleteSongFromList(string Data);

	void DeleteTheSong(int delNum);

	void nextSong(int num);

};

void List::DisplayListSongs()

{

	Node *tmp = head;

	int i = 1;

	if (tmp == NULL)

	{

		cout << "The Play List is EMPTY" << endl;

		return;

	}

	if (tmp->Type() == NULL)

	{

	}

	else

	{

		do

		{

			cout << i;

			cout << ": \t";

			cout << tmp->File() << endl;

			tmp = tmp->Type();

			i++;

		}

		while (tmp != NULL);

	}

}

void List::playMyList()

{

	Node *tmp = head;

	int i = 1;

	if (tmp == NULL)

	{

		cout << "The Play List is EMPTY" << endl;

		return;

	}

	if (tmp->Type() == NULL)

	{

	}

	else

	{

		do

		{

			if (songN == i)

			{

				cout << " Currently playing Song " << endl;

				cout << i;

				cout << ":";

				cout << tmp->File() << endl;

				cout << endl << endl;

			}

			tmp = tmp->Type();

			i++;

		}

		while (tmp != NULL);

	}

}

void List::addSong(string Data)

{

	Node* newNode = new Node();

	newNode->SetSong(Data);

	newNode->SetNextSong(NULL);

	Node *tmp = head;

	if (tmp != NULL)

	{

		while (tmp->Type() != NULL)

		{

			tmp = tmp->Type();

		}



		tmp->SetNextSong(newNode);

	}

	else

	{

		head = newNode;

	}

}

void List::deleteSongFromList(string Data)

{

	Node *tmp = head;

	if (tmp == NULL)

		return;

	if (tmp->Type() == NULL)

	{

		delete tmp;

		head = NULL;

	}

	else

	{

		Node *prev = NULL;

		do

		{

			if (tmp->File() == Data) break;

			prev = tmp;

			tmp = tmp->Type();

		} while (tmp != NULL);

		prev->SetNextSong(tmp->Type());

		delete tmp;

	}

}

void List::DeleteTheSong(int delNum)

{

	Node *tmp = head;

	int i = 1;

	if (tmp == NULL)

		return;

	if (tmp->Type() == NULL)

	{

		delete tmp;

		head = NULL;

	}

	else

	{

		Node *prev = NULL;

		do

		{

			if (i == delNum)

			{

				cout << "Current song has been deleted";

				break;

			}

			prev = tmp;

			tmp = tmp->Type();

			i++;

		} while (tmp != NULL);

		prev->SetNextSong(tmp->Type());

		delete tmp;

	}

}

void List::nextSong(int num)

{

	cout << endl;

	cout << endl;

	Node *tmp = head;

	int i = 1;

	if (tmp == NULL)

	{

		cout << "The Play List is EMPTY" << endl;

		return;

	}





	if (tmp->Type() == NULL)

	{

		cout << "No Song on the list" << endl;

	}

	else

	{

		do

		{

			if (i == num)

			{

				cout << "currently Song playing: \t";

				cout << tmp->File() << endl;

			}

			tmp = tmp->Type();

			i++;

		}

		while (tmp != NULL);

	}

}

int main()

{

	List list;

	int length = 0;

	ifstream myReadFile;

	//this need to be changed to your text file. Add the text file to your project folder and make sure you name it same as below. do not add txt to the end it will automatically adds it. once you 

	// change the file make sure you delet this comment both line in green.

	myReadFile.open("YourList.txt");

	string temp;

	while (getline(myReadFile, temp))

	{

		length++;

		list.addSong(temp);

	}

	list.DisplayListSongs();

	cout << endl << endl;

	char ans;

	int skipnum = 0;

	do

	{

		cout << "\nI: Play a Song \nII: Skip a Song \nIII: Delete a Song\nIV: Play Next\nV: Display Play List\nVI: Exit play List " << endl;

		cin >> ans;

		if (ans == 'I')

		{

			if (songN>length)

				songN = 1;

			list.playMyList();

		}

		if (ans == 'II')

		{

			cout << "Please enter the number of song you want to skip :";

			cin >> skipnum;

			if (skipnum <= length)

			{

				list.nextSong(skipnum);

				songN = skipnum;

			}

			else

			{

				cout << "The number you entered is not in the current play list.";

			}

		}

		if (ans == 'III') {

			list.DeleteTheSong(songN);

		}

		if (ans == 'IV')

		{

			songN++;

			if (songN>length)

			{

				songN = 1;

			}

			list.playMyList();

		}

		if (ans == 'V')

		{

			list.DisplayListSongs();

		}

	}

	while (ans != 'VI');

}