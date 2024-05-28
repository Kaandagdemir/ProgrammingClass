#include <iostream>
#include <fstream>
#include <cstdint>

const int ARRAY_SIZE = 10;

void saveArrayToFile(int arr[], const char* filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(arr), sizeof(int) * ARRAY_SIZE);
    file.close();
}

void readArrayFromFile(int arr[], const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }
    file.read(reinterpret_cast<char*>(arr), sizeof(int) * ARRAY_SIZE);
    file.close();
}

int searchFirstOccurrence(const char* filename, int value) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        return -1;
    }
    int arr[ARRAY_SIZE];
    file.read(reinterpret_cast<char*>(arr), sizeof(int) * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == value) {
            file.close();
            return i;
        }
    }
    file.close();
    return -1;
}

int searchLastOccurrence(const char* filename, int value) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading." << std::endl;
        return -1;
    }
    int arr[ARRAY_SIZE];
    file.read(reinterpret_cast<char*>(arr), sizeof(int) * ARRAY_SIZE);
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (arr[i] == value) {
            file.close();
            return i;
        }
    }
    file.close();
    return -1;
}

void replaceByIndex(const char* filename, int index, int newValue) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error opening file for reading and writing." << std::endl;
        return;
    }
    file.seekp(sizeof(int) * index);
    file.write(reinterpret_cast<const char*>(&newValue), sizeof(int));
    file.close();
}

void replaceByValue(const char* filename, int oldValue, int newValue) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error opening file for reading and writing." << std::endl;
        return;
    }
    int arr[ARRAY_SIZE];
    file.read(reinterpret_cast<char*>(arr), sizeof(int) * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == oldValue) {
            file.seekp(sizeof(int) * i);
            file.write(reinterpret_cast<const char*>(&newValue), sizeof(int));
        }
    }
    file.close();
}

int main() {
    int arr[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    saveArrayToFile(arr, "data.bin");

    int readArr[ARRAY_SIZE];
    readArrayFromFile(readArr, "data.bin");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << readArr[i] << " ";
    }
    std::cout << std::endl;

    int index = searchFirstOccurrence("data.bin", 5);
    if (index != -1) {
        std::cout << "First occurrence of 5 found at index " << index << std::endl;
    }
    else {
        std::cout << "5 not found in file." << std::endl;
    }

    index = searchLastOccurrence("data.bin", 5);
    if (index != -1) {
        std::cout << "Last occurrence of 5 found at index " << index << std::endl;
    }
    else {
        std::cout << "5 not found in file." << std::endl;
    }

    replaceByIndex("data.bin", 4, 20);
    readArrayFromFile(readArr, "data.bin");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << readArr[i] << " ";
    }
    std::cout << std::endl;

    replaceByValue("data.bin", 2, 30);
    readArrayFromFile(readArr, "data.bin");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << readArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}