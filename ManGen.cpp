#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream> // Required for file operations

using namespace cv;
using namespace std;

// Function to convert grayscale value to ASCII character
char grayscaleToAscii(int grayscaleValue) {
    // ASCII characters ranging from dark to light
    char asciiChars[] = { '@', '#', '8', '&', 'o', ':', '*', '.', ' ' };
    // Map grayscale value to ASCII character
    int index = grayscaleValue * sizeof(asciiChars) / 256;
    // Ensure index stays within bounds
    if (index >= sizeof(asciiChars)) {
        index = sizeof(asciiChars) - 1;
    }
    return asciiChars[index];
}

int imageProcessor() {
    string path;
    cout << endl;
    cout << "Enter the name of image file with extension if at the same location or the path of the image file" << endl;
    cout << "Enter the path of the image: ";
    cin >> path;
    // Load image
    Mat image = imread(path, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        cout << "Please check the path and try again" << endl;
        Sleep(2000);
        path.clear();
        return -1;
    }

    cout << "Image loaded successfully" << endl;
    cout << "Processing image...0%";

    // Open a text file for writing the ASCII representation
    ofstream outFile("ascii_art.txt");
    if (!outFile.is_open()) {
        cout << "Failed to open file for writing" << endl;
        cout<< "Please check the file permissions and try again" << endl;
        Sleep(2000);
        path.clear();
        return -1;
    }

    system("cls");
    cout << "Processing image...25%";

    // Print ASCII representation of the image to the text file
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            // Get grayscale value of pixel
            int grayscaleValue = image.at<uchar>(y, x);
            // Map grayscale value to ASCII character
            char asciiChar = grayscaleToAscii(grayscaleValue);
            // Write ASCII character to the text file
            outFile << asciiChar;
        }
        // Newline after each row
        outFile << endl;
    }

    system("cls");
    cout << "Processing image...50%";

    // Close the text file
    outFile.close();

    // Open the ASCII text file for reading
    ifstream inFile("ascii_art.txt");
    if (!inFile.is_open()) {
        cout << "Failed to open file for reading" << endl;
        path.clear();
        return -1;
    }

    // Read the ASCII representation from the text file and calculate dimensions
    vector<string> lines;
    string line;
    int maxLineLength = 0;
    while (getline(inFile, line)) {
        lines.push_back(line);
        maxLineLength = max(maxLineLength, (int)line.length());
    }
    inFile.close();

    // Calculate dimensions of the output image
    int imageWidth = maxLineLength * 10; // Each character occupies 10 pixels
    int imageHeight = lines.size() * 20; // Each line occupies 20 pixels

    system("cls");
    cout << "Processing image...75%";

    // Create a blank canvas for drawing ASCII characters
    Mat asciiImage(imageHeight, imageWidth, CV_8UC1, Scalar(255));

    // Draw ASCII characters onto the canvas
    for (int y = 0; y < lines.size(); ++y) {
        const string& line = lines[y];
        for (int x = 0; x < line.length(); ++x) {
            char asciiChar = line[x];
            // Draw ASCII character onto the canvas
            putText(asciiImage, string(1, asciiChar), Point(x * 10, (y + 1) * 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0), 1, LINE_AA);
        }
    }

    // Save the ASCII image as a PNG file
    imwrite("ascii_image.png", asciiImage);

    system("cls");
    cout << "Processing image...100%" << endl;
    cout << "Done" << endl;
    cout << "ASCII image saved as 'ascii_image.png'" << endl;

    system("ascii_image.png");
    system("ascii_art.txt");
    path.clear();
    cout << "Exiting Program" << endl;
    Sleep(2000);
    return 0;
}
void artMenu() {
    //Change Console Color
    HANDLE outputHandle;
    outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(outputHandle, 3);

    cout << "MMMMMMMM               MMMMMMMM                                              GGGGGGGGGGGGG" << endl;
    cout << "M:::::::M             M:::::: M                                            GGG::::::::::::G" << endl;
    cout << "M::::::::M           M::::::::M                                           GG:::::::::::::: : G" << endl;
    cout << "M:::::::: : M         M:::::::M                                          G:::: : GGGGGGGG::::G" << endl;
    cout << "M::::::::::M       M::::::::::M  aaaaaaaaaaaaa       nnnn  nnnnnnnn    G:::: : G       GGGGGG      eeeeeeeeeeee       nnnn  nnnnnnnn" << endl;
    cout << "M:::::::::: : M     M:::::::::M  a::::::::::::a      n:: : nn:::::::n  G:::: : G                  ee::::::::::::ee    n:: : nn::::::nn" << endl;
    cout << "M:::::: : M::::M   M::::M:::::M  aaaaaaaaa:::: a     n::::::::::::::n  G:::: : G                 e::::::eeeee::::ee   n::::::::::::::nn" << endl;
    cout << "M::::::M M::::M M::::M M::::::M           a::::a     n::::::::::::::n  G:::: : G    GGGGGGGGGG  e::::::e     e::::e   nn::::::::::::::n" << endl;
    cout << "M::::::M  M::::M::::M  M::::::M    aaaaaaa:::: a     n:::: : nnnn:::n  G:::: : G    G::::::::G  e:::::: : eeeee:::e   n:::: : nnnn:::n" << endl;
    cout << "M::::::M   M:::::: : M   M::::M  aa::::::::::::a     n::::n    n::::n  G:::: : G    GGGGG::::G  e::::::::::::::::e    n::::n    n::::n" << endl;
    cout << "M::::::M    M:::: : M    M::::M  a::::aaaa::::::a    n::::n    n::::n  G:::: : G        G::::G  e::::::eeeeeeeeeee    n::::n    n::::n" << endl;
    cout << "M::::::M     MMMMM     M::::::M a::::a    a:::: : a  n::::n    n::::n   G:::: : G       G::::G  e:::::: : e           n::::n    n::::n" << endl;
    cout << "M::::::M               M::::::M a::::a    a:::: : a  n::::n    n::::n    G:::: : GGGGGGGG::::G  e::::::::e            n::::n    n::::n" << endl;
    cout << "M::::::M               M::::::M a:::: : aaaa::::::a  n::::n    n::::n     GG:::::::::::::: : G   e::::::::eeeeeeee    n::::n    n::::n" << endl;
    cout << "M::::::M               M::::::M a::::::::::aa:: : a  n::::n    n::::n       GGG::::::GGG:: : G    ee:::::::::::: e    n::::n    n::::n" << endl;
    cout << "MMMMMMMM               MMMMMMMM    aaaaaaaaaa  aaaa  nnnnnn    nnnnnn          GGGGGG   GGGG       eeeeeeeeeeeeee     nnnnnn    nnnnnn" << endl;
    cout << endl;
    cout << "Created by : Manav Marmat" << endl;
    cout << endl;
    cout << "A program to convert images to ASCII art" << endl;
    cout << "Press the up and down arrow keys to navigate the menu" << endl;
    cout << "Press the enter key to select an option" << endl;
    cout << "Press the 'Esc' key to exit the program" << endl;
    cout << endl;
    cout << endl;
}

int main() {

    // Function to display the menu
    const int numOptions = 2;
    int selectedOption = 0;

    while (true) {
        system("cls"); // clear the console
        artMenu();
        // Display menu options
        for (int i = 0; i < numOptions; ++i) {
            if (i == selectedOption) {
                cout << ">> ";
            }
            else {
                cout << "   ";
            }

            // Display menu option
            if (i == 0) {
                cout << "Proceed" << endl;
            }
            else if (i == 1) {
                cout << "Exit" << endl;
            }
        }

        // Wait for user input
        int key = _getch();

        // Handle user input
        switch (key) {
        case 72:
            // Move selection up
            selectedOption = (selectedOption - 1 + numOptions) % numOptions;
            break;

        case 80:
            // Move selection down
            selectedOption = (selectedOption + 1) % numOptions;
            break;

        case 13: // Enter key
            // Perform action based on the selected option
            if (selectedOption == 0) {
                imageProcessor();
            }
            else if (selectedOption == 1) {
                return 1;
            }

        default:
            // Ignore other keys
            break;
        }
    }
	return 0;
}
