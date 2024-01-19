// FileEncryptionApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key)
{
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch + key);
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(const std::string& inputFilePath, const std::string &outputFilePath, int key)
{
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch - key);
    }

    inputFile.close();
    outputFile.close();
}


int main()
{
    std::string inputFilePath, outputFilePath;
    int choice, key;

    std::cout << "1. Encrypt file\n";
    std::cout << "2. Decrypt file\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "Enter key (integer): ";
    std::cin >> key;

    std::cout << "Enter input file path: ";
    std::cin >> inputFilePath;
    std::cout << "Enter output file path: ";
    std::cin >> outputFilePath;

    if (choice == 1)
    {
        encryptFile(inputFilePath, outputFilePath, key);
    }

    else if (choice == 2)
    {
        decryptFile(inputFilePath, outputFilePath, key);
    }
    else
    {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
