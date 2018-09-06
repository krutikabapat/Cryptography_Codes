
#include <iostream>
#include <string>
using namespace std;


string encrypt(string data,int key[5])
{
	string cipher ="";
	for(int i=0;i<data.length()/5;i++)
	{
		for(int j=0;j<5;j++)
		{	
			if(key[j]<5 && key[j]>=0)
			 	cipher+=data[(5*i)+key[j]];
			else
				{
					cout<<"Errors in Key. ( N belongs to [0,4] )"<<endl;
					cipher.clear();
					break;
				}
		}
		cipher+=" ";
	}
	return cipher;
}

string decrypt(string data,int key[5])
{
	//cout<<"entered function";
	string cipher ="";
	for(int i=0;i<data.length()/5;i++)
	{

		for(int j=0;j<5;j++)//for tracing the index of key
		{
			for(int k=0;k<5;k++)//for tracing the value of key
				{
					if(j==key[k])//if value 
						cipher+=data[(5*i)+k];
		 		}
		 }
		cipher+=" ";
	}
	return cipher;
}

string remove(string text)
{
	string text_removed="";
	for(int i=0;i<text.length();i++)
	{
		if((int)(text[i])!=32)
			text_removed+=text[i];
	}
	return text_removed;
}

int main()
{
	string text,enc,dec;
	int key[5];
	int flag=0,k=0;
	char f;
	while(k<1)
		{
			if(flag==0)
			{
				cout<<"Enter the text to encrypt : ";
				flag++;
			}
			else
				cout<<"Enter the text to encrypt (multiple of 5) : ";
			getline(cin,text);
			text=remove(text);
			if(text.length()%5==0)
				k++;
			else
				text.clear();
		}
	//cout<<text<<endl;
	cout<<"Enter the Key : ";
	for(int i=0;i<5;i++)
		cin>>key[i];
	
	enc=encrypt(text,key);
	cout<<"Keyed Encrypt : "<<enc<<endl;
	dec=remove(enc);
	//cout<<dec<<endl;
	cout<<"Decrypt Data [y/n] : ";
	cin>>f;
	if(f=='y')
		cout<<"Keyed Decrypt : "<<decrypt(dec,key)<<endl;
	return 0;
}
