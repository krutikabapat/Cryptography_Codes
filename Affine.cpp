#include<bits/stdc++.h>
using namespace std;
 
//Key values of a and b
const int a = 5;
const int b = 8;
 
string encryptMessage(string msg)
{
    ///Cipher Text initialise
    string cipher = ""; 
    for (int i = 0; i < msg.length(); i++)
    {
        // Avoid space to be encrypted 
        if(msg[i]!=' ') 
           
            cipher = cipher + (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
           
            cipher += msg[i];    
    }
    return cipher;
}
 
string decryptCipher(string cipher)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;
     
   
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
         
        
        if (flag == 1)
        { 
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')
            /*Applying decryption formula a^-1 ( x - b ) mod m 
            {here x is cipher[i] and m is 26} and added 'A' 
            to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
            msg = msg + (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else
            //else simply append space characte
            msg += cipher[i]; 
    }
 
    return msg;
}
 
//Driver Program
int main(void)
{
    string msg = "AFFINE";
     
    //Calling encryption function
    string cipherText = encryptMessage(msg);
    cout << "Encrypted Message is : " << cipherText<<endl;
     
    //Calling Decryption function
    cout << "Decrypted Message is: " << decryptCipher(cipherText)<<endl;
 
    return 0;
}