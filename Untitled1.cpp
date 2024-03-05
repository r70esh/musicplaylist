#include<iostream>
#include<string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

string temp;
Node* head = nullptr;
Node* current_node = nullptr;

void insert() {
    cout << "Enter Name of the song:" << endl;
    cin.ignore(); // clear the input buffer
    getline(cin, temp);

    Node* new_node = new Node;
    new_node->data = temp;

    if (head == nullptr) {
        new_node->next = new_node->prev = new_node;
        head = current_node = new_node;
        return;
    }

    Node* last = head->prev;
    new_node->prev = last;
    last->next = new_node;
    new_node->next = head;
    head->prev = new_node;
}

void deleteElement() {
    if (head == nullptr) {
        cout << "No song to delete!" << endl;
        return;
    }

    cout << "Enter Name  of the song to delete:" << endl;
    cin.ignore(); // clear the input buffer
    getline(cin, temp);

    Node* ptr = head;
    do {
        if (ptr->next == ptr && ptr->data == temp) {
            cout << "One file deleted! Playlist is Empty Now!" << endl;
            head = nullptr;
            delete ptr;
            return;
        } else if (ptr->data == temp) {
            Node* prev = ptr->prev;
            Node* next = ptr->next;
            prev->next = next;
            next->prev = prev;
            head = next;
            delete ptr;
            cout << "Music deleted!" << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "No song is there to delete!" << endl;
}

void show() {
    if (head == nullptr) {
        cout << "Playlist is Empty!" << endl;
        return;
    }

    Node* show_ptr = head;
    cout << "\nDisplaying Playlist :" << endl;
    int i = 1;
    do {
        cout << "Song " << i << " : " << show_ptr->data << endl;
        i++;
        show_ptr = show_ptr->next;
    } while (show_ptr != head);
}

void nextNode() {
    if (current_node == nullptr) {
        cout << "No songs in Playlist!" << endl;
    } else {
        current_node = current_node->next;
        cout << "Playing Next Song : " << current_node->data << endl;
    }
}

void prevNode() {
    if (current_node == nullptr) {
        cout << "No songs in Playlist!" << endl;
    } else {
        current_node = current_node->prev;
        cout << "Playing Previous Song : " << current_node->data << endl;
    }
}

void firstNode() {
    if (head == nullptr) {
        cout << "Playlist is Empty!" << endl;
    } else {
        cout << "Playing First Music : " << head->data << endl;
    }
}

void lastNode() {
    if (head == nullptr) {
        cout << "Playlist is Empty!" << endl;
    } else {
        cout << "Playing Last Music : " << head->prev->data << endl;
    }
}

void specificData() {
    if (head == nullptr) {
        cout << "No music is there to be searched!" << endl;
        return;
    }

    cout << "Enter Music Name to search:" << endl;
    cin.ignore(); // clear the input buffer
    getline(cin, temp);

    Node* ptr = head;
    do {
        if (ptr->data == temp) {
            cout << "Music Found!" << endl;
            cout << "Playing Music : " << ptr->data << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "There is no Music file with this name!" << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n-----Song Playlist Application-----\n";
        cout << "1. Add Music\n";
        cout << "2. Remove Music\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play next file\n";
        cout << "5. Play previous file\n";
        cout << "6. Play first file\n";
        cout << "7. Play Last file\n";
        cout << "8. Play specific file\n";
        cout << "9. Exit\n\n";

        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                show();
                break;
            case 4:
                nextNode();
                break;
            case 5:
                prevNode();
                break;
            case 6:
                firstNode();
                break;
            case 7:
                lastNode();
                break;
            case 8:
                specificData();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
