#include <iostream>
#include <string>
#include <fstream>
//DO NOT change the code in md5.h and md5.cpp
using namespace std;

//This function is used to generate the flag,
//DO NOT change the code in this function otherwise you'll get wrong answer.

// These functions may help you find the correct password and key.
string password;
string key = "pass";
string CroissantEncrypt(string password, string key) {
 string cipher = "";
 for(int i=0;i<password.size();i++) {
  int sh = key[i%(key.size())]-'a';
  char encrypt = 'a' + (password[i]-'a'+sh)%26;
  cipher.push_back(encrypt);
 }
 return cipher;
}

string SaladDecrypt(string password,string key) {
 string cipher = "";
 for(int i=0;i<password.size();i++) {
  int sh = key[i%(key.size())]-'a';
  char decrypt = 'a' + (((password[i] - 'a')%26)-sh);
  cipher.push_back(decrypt);
 }
 return cipher;
}

bool checkPassword(string password,string key) {
 if(password.find("ovenbreak"))return true;
 else return false;
}

int main() {
 string ans;
 while(1){
  cin >> password;
  password = SaladDecrypt(password, key);
  if(checkPassword(password,key)){
   cout<<password;
   return 0;
  }
  else cout << "NOOOOO\n";
 }
}