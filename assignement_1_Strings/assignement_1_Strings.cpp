#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;

int main(void)
{
	ifstream myfile("Test_Cases.txt");
	string str{};
	vector<string> vect;
	vector<int> vec;
	stringstream ss{};
	stringstream cc{};
	int num = 0,counter = 0,count = 0,vv = 0;
	int sizeofmusic =0,sizeofmovies =0,sizeofpicture =0,sizeofother =0; 
	if(myfile.is_open())
	{
		getline(myfile,str);
		ss << str;
		while(ss >> num)
		{
			vec.push_back(num);
		}
	}	
	if(myfile.is_open())
	{
		while (getline(myfile,str))
		{
			vect.push_back(str);
		}
	}
	for(int j = 0;j<vec[0];j++)
	{
		 for(int i = 0;i<vec[j+1];i++)
		 {
			 cc<<vect[count];
			 cc>>str;
			 replace(str.begin(),str.end(),'.',' ');
			 cc<<str;
			 while(cc.eof()!= true)
			 {
				 cc>>str;
				 if(str == "mp3" || str == "flac" || str == "aac")
				 {
					sizeofmusic += num;
				 }
				 else if(str == "mp4" || str == "avi" || str == "mkv")
				 {
					sizeofmovies += num;
				 }
				 else if(str == "jpg" || str == "bnp" || str == "gif")
				 {
					sizeofpicture += num;
				 }

				 else if(str == "txt" || str == "exe")
				 {
					sizeofother += num;
				 }
				 if((stringstream)str >> num){}
			 }
			 count++;
			 cc.clear();
		 }
		 cout<<"music "<<sizeofmusic<<"b"<<" images "<<sizeofpicture<<"b"<<" movies "<<sizeofmovies<<"b"<<" other "<<sizeofother<<"b"<<endl;
		 num = 0;
		 sizeofmusic =0;
		 sizeofpicture = 0;
		 sizeofmovies =0;
		 sizeofother = 0;
	}
	return 0;
}
