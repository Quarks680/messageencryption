#include<iostream>
#include<string>

int main() {
    std::string alphabet{"{ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key{" [XZNLWEBGJHQDYVTKFUOMMPCIARxzlwebgjhqdyvtfuompciasr"};
    std::string secret_message {};
    
    std::cout << "Enter your secret message: " << std::endl;
    std::getline(std::cin, secret_message); // Added "std::" before "cin"
    
    std::string encrypted_message {};
    
    std::cout << "\nEncrypting message..." << std::endl;
    
    for (char c : secret_message) {
        size_t position = alphabet.find(c);
        if (position != std::string::npos) {
            char new_char = key.at(position);
            encrypted_message += new_char;
        } else {
            encrypted_message += c; // Fixed the typo in "encrypted"
        }
    }
    
    std::cout << "\nEncrypted message: " << encrypted_message << std::endl; // Moved the cout outside of the loop
    
    std::string decrypted_message{};
    std::cout<<"\nDecrypting message......"<<std::endl;
    
    for(char c : encrypted_message){ // Fixed the variable name "encryted_message" to "encrypted_message"
        size_t position = key.find(c);
        if(position != std::string::npos){
            char new_char = alphabet.at(position);
            decrypted_message += new_char; // Fixed the variable name "decrypted>messaage" to "decrypted_message"
        }
        else{
            decrypted_message += c;
        }
    }
    
    std::cout<<"\nDecrypted message: "<<decrypted_message<<std::endl;
    
    return 0; // Added to indicate successful program execution
}

