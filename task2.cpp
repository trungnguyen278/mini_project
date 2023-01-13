#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;



void insertLine(const char* file_name, int num_outlier);
// Ham xu ly du lieu task2.1
int data_processing(const char* inputfile, const char* outputfile);

int main(int argc, char *argv[]) {
    // Ten tep dau vao va dau ra mac dinh
    const char* input_filename = "dust_sensor.csv";
    const char* output_filename_1 = "dust_outliers.csv";
    const char* output_filename_2 = "dust_aqi.csv";
    const char* output_filename_3 = "dust_summary.csv";
    const char* output_filename_4 = "dust_statistics.csv";

    // If a command line argument is provided, use it as the input filename
    if (argc > 1) {
        input_filename = argv[1];
    }

    data_processing(input_filename, output_filename_1);


    return 0;
}


void insertLine(const char* file_name, int num_outlier){
    ifstream file(file_name);
    ofstream tempFile("temp.csv");

    // Ghi dong moi vao dau file tam thoi
    tempFile << "number of outliers: " << num_outlier << endl;

    string currentLine;

    // Sao chep cac dong con lai tu file goc sang file tam
    while (getline(file, currentLine)) {
        tempFile << currentLine << endl;
    }

    // Dong 2 file
    file.close();
    tempFile.close();

    // Xoa file goc doi ten file tam
    remove(file_name);
    rename("temp.csv", file_name);
}

int data_processing(const char* inputfile, const char* outputfile){
    ifstream in_file(inputfile);
    if (!in_file.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Open the output file
    ofstream out_file(output_filename);
    if (!out_file.is_open()) {
    cout << "Error: Unable to open output file." << endl;
    return 1;
    }

    

}