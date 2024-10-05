#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class FlightReservationSystem {
    struct Node {
        string name;
        string date;
        string departure_time;
        string arrival_time;
        string cost;
        string flight;
        string hotelfair;
        Node *next;

        Node(string source) {
            name = source;
            next = nullptr;
            date = "";
            departure_time = "";
            arrival_time = "";
            cost = "";
            flight = "";
            hotelfair = "";
        }

        Node(string destination, string dte, string d_t, string a_t, string cst, string flt) {
            name = destination;
            date = dte;
            departure_time = d_t;
            arrival_time = a_t;
            cost = cst;
            flight = flt;
            next = nullptr;
        }
    };

    int index;
    Node* array[10];

public:
    FlightReservationSystem() {
        index = 0;
        for (int i = 0; i < 10; i++) {
            array[i] = nullptr;
        }
    }

    int search(string src) {
        for (int i = 0; i < index; i++) {
            if (array[i]->name == src)
                return i;
        }
        return -1;
    }

    void sourceInsert(string abc) {
        if (index == 0) {
            array[index] = new Node(abc);
            index++;
        } else {
            int search_temp = search(abc);
            if (search_temp == -1) {
                array[index] = new Node(abc);
                index++;
            }
        }
    }

    void insert(int indx, Node* nd) {
        if (array[indx]->next == nullptr) {
            array[indx]->next = nd;
        } else {
            Node* ptr = array[indx]->next;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = nd;
        }
    }

    int stringToInt(string s) {
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }

    void minimumPricePath(string src, string dst) {
        int src_index = search(src);
        if (src_index == -1) {
            cout << "Source not found!" << endl;
            return;
        }
        int temp2 = 0;
        int fares;
        cout << "Source is " << array[src_index]->name << endl;
        Node* ptr = array[src_index]->next;
        while (ptr != nullptr) {
            if (ptr->name == dst) {
                fares = stringToInt(ptr->cost);
                if (fares > temp2) {
                    ofstream myfile;
                    myfile.open("minimumfare.txt");
                    myfile << array[src_index]->name << " " << ptr->name << " " << ptr->date << " "
                           << ptr->departure_time << " " << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
                    myfile.close();
                    temp2 = fares;
                }
            }
            ptr = ptr->next;
        }
        displayFile("minimumfare.txt");
    }

    void minimumTimePath(string src, string dst) {
        int src_index = search(src);
        if (src_index == -1) {
            cout << "Source not found!" << endl;
            return;
        }
        int temp2 = INT32_MAX;
        int fares;
        cout << "Source is " << array[src_index]->name << endl;
        Node* ptr = array[src_index]->next;
        while (ptr != nullptr) {
            if (ptr->name == dst) {
                fares = stringToInt(ptr->cost);
                if (fares < temp2) {
                    ofstream myfile;
                    myfile.open("minimumtime.txt");
                    myfile << array[src_index]->name << " " << ptr->name << " " << ptr->date << " "
                           << ptr->departure_time << " " << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
                    myfile.close();
                    temp2 = fares;
                }
            }
            ptr = ptr->next;
        }
        displayFile("minimumtime.txt");
    }

    void path(string src, string dst) {
        int src_index = search(src);
        if (src_index == -1) {
            cout << "Source not found!" << endl;
            return;
        }
        cout << "{Source: " << array[src_index]->name << "}" << endl;
        Node* ptr = array[src_index]->next;
        while (ptr != nullptr) {
            if (ptr->name == dst) {
                cout << "-Destination- " << ptr->name << " " << ptr->date << " " << ptr->departure_time << " "
                     << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
            }
            ptr = ptr->next;
        }
    }

    void datePath(string src, string dst, string dte) {
        int src_index = search(src);
        if (src_index == -1) {
            cout << "Source not found!" << endl;
            return;
        }
        int found = 0;
        cout << "{Source: " << array[src_index]->name << "}" << endl;
        Node* ptr = array[src_index]->next;
        while (ptr != nullptr) {
            if (ptr->name == dst && ptr->date == dte) {
                cout << "-Destination- " << ptr->name << " " << ptr->date << " " << ptr->departure_time << " "
                     << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
                found = 1;
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "No flights found on the specific date. Available options are: " << endl;
            path(src, dst);
        }
    }

    void flightPath(string src, string dst, string flt) {
        int src_index = search(src);
        if (src_index == -1) {
            cout << "Source not found!" << endl;
            return;
        }
        int found = 0;
        cout << "{Source: " << array[src_index]->name << "}" << endl;
        Node* ptr = array[src_index]->next;
        while (ptr != nullptr) {
            if (ptr->name == dst && ptr->flight == flt) {
                cout << "-Destination- " << ptr->name << " " << ptr->date << " " << ptr->departure_time << " "
                     << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
                found = 1;
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "No flights found for the specified airline. Available options are: " << endl;
            path(src, dst);
        }
    }

    void displayDirectFlights() {
        for (int i = 0; i < index; i++) {
            cout << "[Source] " << array[i]->name << " : Hotel fair/day = " << array[i]->hotelfair << endl;
            Node* ptr = array[i]->next;
            while (ptr != nullptr) {
                cout << "--Destination-- " << ptr->name << " " << ptr->date << " " << ptr->departure_time << " "
                     << ptr->arrival_time << " " << ptr->cost << " " << ptr->flight << endl;
                ptr = ptr->next;
            }
            cout << endl;
        }
    }

    void loadFlightData(const string& filename) {
        ifstream in(filename);
        string input;
        while (getline(in, input)) {
            istringstream iss(input);
            string word[7];
            for (int i = 0; i < 7; i++) {
                iss >> word[i];
            }
            sourceInsert(word[0]);
            Node* newnode = new Node(word[1], word[2], word[3], word[4], word[5], word[6]);
            insert(search(word[0]), newnode);
        }
        in.close();
    }

    void loadHotelCharges(const string& filename) {
        ifstream in(filename);
        string input;
        while (getline(in, input)) {
            istringstream iss(input);
            string word[2];
            for (int i = 0; i < 2; i++) {
                iss >> word[i];
            }
            if (search(word[0]) != -1) {
                array[search(word[0])]->hotelfair = word[1];
            }
        }
        in.close();
    }

private:
    void displayFile(const string& filename) {
        ifstream in(filename);
        string input;
        while (getline(in, input)) {
            cout << input << endl;
        }
        in.close();
    }
};

int main() {
    FlightReservationSystem system;

    system.loadFlightData("Flights.txt");
    system.loadHotelCharges("HotelCharges_perday.txt");

    cout << "************ FLIGHT RESERVATION SYSTEM ************" << endl;

