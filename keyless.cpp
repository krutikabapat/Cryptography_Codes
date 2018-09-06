#include <iostream>
#include <string>
using namespace std;


string encrypt(string data)
{
	string cipher ="";
	string col1 ="";
	string col2 ="";
	

	for(int i=0;i<data.length();i++)
	{
		
			if(i%2==0)
				col1+=data[i];
			else
				col2+=data[i];
	}
	return (col1+col2);
}

string decrypt(string data)
{
	string cipher ="";
	int j=0,k=0;
	int mid = (data.length()/2)+0.5;
	//cout<<data.length()<<endl;
	//cout<<mid<<endl;

	for(int i=0;i<data.length();i++)
	{
		if(i%2==0)
			{
				cipher+=data[j];
				j++;
			}
		else
			{
				cipher+=data[mid+j];
				k++;
			}
	}

	return cipher;
}

int main()
{
	string text,enc,dec;
	char f;		
	cout<<"Enter the text to encrypt : ";
	getline(cin,text);
			
	enc=encrypt(text);
	cout<<"Keyless Encrypt : "<<enc<<endl;
	cout<<"Decrypt Data [y/n] : ";
	cin>>f;
	if(f=='y')
		cout<<"Keyless Decrypt : "<<decrypt(enc)<<endl;
	return 0;
}