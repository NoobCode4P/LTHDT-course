/* Write a program to split and join file. The source code must have OOP design:

[Splitter]

Enter the size (S) of a piece and a file name (F). Split the file in to n piece, each piece's size is S:

F.001 => MyMovie.mp4.001

F.002 => MyMovie.mp4.002

F.003 => ...

...

[Joiner]

Enter the first piece name (F.001), find the remaining parts and join to restore the original file => MyMovie.mp4 */

#include "File.h"

int main(){
    ull size;
    cout << "Enter the size of each chunk: ";
    cin >> size;

    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    File file1(filename);
    
    vector <File> subfiles1;
    try{
        spilt(file1, size, subfiles1);
        cout << file1;
        cout << "Splitting " << file1.getFileName() << " successfully!!!" << endl;

        string file;
        cout << "Enter the name of the first chunk (format: [filename].[ext].001): ";
        cin >> file;
        
        try {
            int i;
            for (i = 0; i < subfiles1.size(); i++)
                if (file == subfiles1[i].getFileName())
                    break;
            if (i == subfiles1.size()){
                throw (string)"No subfile exists!!";
            }
            try {
                File piece(file);
                File joined = join(subfiles1);
                cout << "Small chunks have been joined successfully!!!" << endl;
                cout << "The original file has been restored." << endl;
                cout << joined;
        
            }catch(string msg){
                cout << "Error 3: " << msg << endl;
            }
                        
        } catch(string s){
            cout << "Error 2: " + s << endl;
            exit(1);
        }

    }
    catch(string message){
        cout << "Error 1: " << message << endl;
        exit(1);
    }

    return 0;
}