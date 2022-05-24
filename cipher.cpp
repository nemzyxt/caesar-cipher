// Author : Nemuel Wainaina

#include <iostream>
#include <string>

using namespace std;

string encrypt(string, int);
string decrypt(string, int);

int main() {
    start:
    cout<<"Select the operation : "<<endl;
    cout<<"1. Encrypt\n2. Decrypt"<<endl;
    int op;
    cin>>op;

    string msg;
    int key;
    if(op == 1) {
        cout<<"Enter the message to encrypt : ";
        cin>>msg;
        cout<<"Enter the key to use : ";
        cin>>key;
        cout<<"CipherText :: "<<encrypt(msg, key)<<endl;
    } else if(op == 2) {
        cout<<"Enter the message to decrypt : ";
        cin>>msg;
        cout<<"Enter the key to use : ";
        cin>>key;
        cout<<"PlainText :: "<<decrypt(msg, key)<<endl;
    } else {
        cout<<"[!] Choose either 1 or 2"<<endl;
        goto start;
    }

    return 0;
}

// encrypt a string using the provided key and return the resultant ciphertext
string encrypt(string msg, int key) {
    char ch;

    for(int i = 0; i < msg.length(); i++) {
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z') {
            ch += key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch += key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }

    return msg;
}

// decrypt a string using the provided key and return the resultant plaintext
string decrypt(string msg, int key) {
    char ch;

    for(int i = 0; i < msg.length(); i++) {
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z') {
            ch -= key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch -= key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
    
    return msg;
}
