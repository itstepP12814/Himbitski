#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>
#include <direct.h>

using namespace std;
const int size = 1024;

bool CopyF(const char *s, const char *d){
	FILE *source, *destination;
	if (!(source = fopen(s, "rb"))){
		return false;
	}
	int handle = _fileno(source);
	char *data = new char[size];
	if (!data){
		return false;
	}
	if (!(destination = fopen(d, "wb"))){
		delete[]data;
		return false;
	}
	int realsize;
	while (!feof(source)){
		realsize = fread(data, sizeof(char), size, source);
			fwrite(data, sizeof(char), realsize, destination);
	}
	fclose(source);
	fclose(destination);
	return true;
}
bool Copy(string s, string d){
	_finddata_t *fileinfo = new _finddata_t;
	long done = _findfirst((s + "*.*").c_str(), fileinfo);
	int MayWeWork = done;
	int count = 0;
	while (MayWeWork != -1){
		if (fileinfo->attrib == _A_SUBDIR) {
			if (fileinfo->name[0] == '.') {
				MayWeWork = _findnext(done, fileinfo);
				continue;
			}
			if (_mkdir((d + fileinfo->name + "\\").c_str())) {
				_mkdir((d + fileinfo->name + "\\.").c_str());
				_mkdir((d + fileinfo->name + "\\..").c_str());
			}
			Copy(s + fileinfo->name + "\\", d + fileinfo->name + "\\");
		}
		else
		{
			_finddata_t *file = new _finddata_t;
			long well = _findfirst((d + fileinfo->name).c_str(), file);
			if (well != -1) {
				if (count == 0 || count == 1 || count == 3) {
					cout << "The file:" << endl << file->name << endl << "size: " << file->size << endl << "already exists" << endl;
					cout << "1. Replace with " << file->name << endl << "size: " << file->size << "." << endl;
					cout << "2. Replace all." << endl;
					cout << "3. Skip this file." << endl;
					cout << "4. Skip all." << endl;
					cout << "5. Cancel." << endl;
					cin >> count;
				}
				_findclose(well);
				delete file;
				switch (count)
				{
				case 1:
					cout << "Copying from:" << endl << s + fileinfo->name << endl << "To:" << d + fileinfo->name << endl;
					if (CopyF((s + fileinfo->name).c_str(), (d + fileinfo->name).c_str())) {
						cout << "Ok" << endl;
					}
					else {
						cout << "File copy failed" << endl;
					}
					break;
				case 2:
					cout << "Copying from:" << endl << s + fileinfo->name << endl << "To:" << d + fileinfo->name << endl;
					if (CopyF((s + fileinfo->name).c_str(), (d + fileinfo->name).c_str())) {
						cout << "Ok" << endl;
					}
					else {
						cout << "File copy failed" << endl;
					}
					break;
				case 3:
					MayWeWork = _findnext(done, fileinfo);
					continue;
					break;
				case 4:
					MayWeWork = _findnext(done, fileinfo);
					continue;
					break;
				case 5:
					return false;
					break;
				}
			}
		}
		MayWeWork = _findnext(done, fileinfo);
	}
	_findclose(done);
	delete fileinfo;
	return true;
}


bool Del(char *path)  
	{
		char* temp_path = new char[strlen(path) + 1];       
		strcpy(temp_path, path);                            
		strcat(temp_path, "*");                             
		_finddata_t* fileinfo = new _finddata_t;            
		long done;                                          
		long there_is_a_file;                              
		int count = 0;                                     
		done = _findfirst(temp_path, fileinfo);          
		there_is_a_file = done;                            
		while (there_is_a_file != -1)                        
		{
			if (fileinfo->attrib == _A_SUBDIR && strcmp(fileinfo->name, ".") != 0 && strcmp(fileinfo->name, "..") != 0)           
			{
				cout << fileinfo->name <<" delete" <<endl;
				remove(path);
			}
			else                                                                        
			{
				cout << fileinfo->name <<" delete" << endl;
				remove(path);
			}
			there_is_a_file = _findnext(done, fileinfo);
		}
		delete fileinfo;
		_findclose(done);
		return true;
}



bool Move(string s, string d){
	_finddata_t *fileinfo = new _finddata_t;
	long done = _findfirst((s + "*.*").c_str(), fileinfo);
	int MayWeWork = done;
	int count = 0;
	while (MayWeWork != -1){
		if (fileinfo->attrib == _A_SUBDIR) {
			if (fileinfo->name[0] == '.') {
				MayWeWork = _findnext(done, fileinfo);
				continue;
			}
			if (rename((s + fileinfo->name + "\\").c_str(), (d + fileinfo->name + "\\").c_str()))
			{
				Move(s + fileinfo->name + "\\", d + fileinfo->name + "\\");
				rename((s + fileinfo->name + "\\").c_str(), (d + fileinfo->name + "\\").c_str());
			}
		}
		else
		{
			if (fileinfo->attrib == _A_RDONLY) {
				if (count == 0 || count == 1 || count == 3) {
					cout << "The file:" << endl << fileinfo->name <<" is READ only" << endl;
					cout << "Choose a variant to do:" << endl;
					cout << "1. Move." << endl;
					cout << "2. Move all ." << endl;
					cout << "3. Skip this file." << endl;
					cout << "4. Skip all" << endl;
					cout << "5. Cancel." << endl;
					cin >> count;
				}
				switch (count) {
					case 1:
					cout << "Moving from: " <<s + fileinfo->name <<" to " <<d + fileinfo->name << endl;
					if (!rename((s + fileinfo->name).c_str(), (d + fileinfo->name).c_str())){
						cout << "ok" << endl;
					}
						break;
					case 2:
					cout << "Moving from: " <<s + fileinfo->name <<" to " <<d + fileinfo->name << endl;
					if (!rename((s + fileinfo->name).c_str(), (d + fileinfo->name).c_str())){
						cout << "ok" << endl;
					}
						break;
					case 3:
						MayWeWork = _findnext(done, fileinfo);
						continue;
						break;
					case 4:
						MayWeWork = _findnext(done, fileinfo);
						continue;
						break;
					case 5:
						return false;
				}
			}
			else
			{
				cout << "Moving from: " <<s + fileinfo->name << " to " <<d + fileinfo->name << endl;
				if (!rename((s + fileinfo->name).c_str(), (d + fileinfo->name).c_str())){
					cout << "ok" << endl;
				}
			}
		}
		MayWeWork = _findnext(done, fileinfo);
	}
	_findclose(done);
	delete fileinfo;
	rename(s.c_str(), d.c_str());
	return true;
}

int main(int argc, char *argv[]){
	////Copy
	/*if (argc >= 3) {
		if (Copy(argv[1], argv[2])){
			cout << endl << "Files are copied" << endl;
		}
	}
	else {
		if (argc == 2) {
			cout << "Enter the destination folder to copy to:" << endl;
			string destination;
			cin >> destination;
			if (Copy(argv[1], destination)){
				cout << endl << "Files are copied" << endl;
			}
			else {
				cout << "Enter the source folder:" << endl;
				string source;
				cin >> source;
				cout << "Enter the destination folder:" << endl;
				string destination;
				cin >> destination;
				if (Copy(source, destination)){
					cout << endl << "All files are copied" << endl;
				}
			}
		}
	}*/


	/////Delete
	/*if (argc >= 2) {
		if (Del(argv[1])){
			cout << "Files are deleted" << endl;
		}
	}
	else {
		cout << "Enter the source to delete:" << endl;
		char source[size];
		gets(source);
		if (Del(source))
		cout << "All files deleted" << endl;
	}*/

	////Move
	if (argc >= 3) {
		if (Move(argv[1], argv[2])){
			cout << endl << "All files are moved" << endl;
		}
	}
	else {
		if (argc == 2) {
			cout << "The source folder is: " << argv[1] << endl;
			cout << "Enter the destination folder to move to:" << endl;
			string destination;
			cin >> destination;
			if (Move(argv[1], destination)){
				cout << endl << "Files are moved" << endl;
			}
		}
		else {
			cout << "Enter the source: " << endl;
			string source;
			cin >> source;
			cout << "Enter the destination: " << endl;
			string destination;
			cin >> destination;
			if (Move(source, destination)){
				cout << endl << "Files are moved" << endl;
			}
		}
	}
	return 0;
}