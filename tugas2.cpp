#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string currentText;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void ketik(const string& text) {
        undoStack.push(currentText);
        currentText += text;
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(currentText);
            currentText = undoStack.top();
            undoStack.pop();
        } else {
            cout << "Tidak ada tindakan untuk undo." << endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(currentText);
            currentText = redoStack.top();
            redoStack.pop();
        } else {
            cout << "Tidak ada tindakan untuk redo." << endl;
        }
    }

    bool isEmptyUndo() const {
        return undoStack.empty();
    }

    bool isEmptyRedo() const {
        return redoStack.empty();
    }

    string getText() const {
        return currentText;
    }
};

int main() {
    TextEditor editor;
    string command;
    string text;

    while (true) {
        cout << "(1)Ketik" << endl;
        cout << "(2)Undo" << endl;
        cout << "(3)Redo" << endl;
        cout << "(4)IsEmptyUndo" << endl;
        cout << "(5)IsEmptyRedo" << endl;
        cout << "(6)Keluar" << endl;
        cout << "Masukkan perintah : " ;
        cin >> command;

        if (command == "1") {
            cout << "Masukkan teks : ";
            cin.ignore();
            getline(cin, text);
            editor.ketik(text);
            cout << "Teks sekarang : " << editor.getText() << endl;
        } else if (command == "2") {
            editor.undo();
            cout << "Teks sekarang : " << editor.getText() << endl;
        } else if (command == "3") {
            editor.redo();
            cout << "Teks sekarang : " << editor.getText() << endl;
        } else if (command == "4") {
            if (editor.isEmptyUndo()) {
                cout << "Undo stack kosong." << endl;
            } else {
                cout << "Undo stack tidak kosong." << endl;
            }
        } else if (command == "5") {
            if (editor.isEmptyRedo()) {
                cout << "Redo stack kosong." << endl;
            } else {
                cout << "Redo stack tidak kosong." << endl;
            }
        } else if (command == "6") {
            break;
        } else {
            cout << "Perintah tidak dikenal." << endl;
        }
    }

    return 0;
}

