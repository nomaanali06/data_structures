#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// FlightReservationSystem class encapsulates all flight reservation functionalities
class FlightReservationSystem {
    // Node structure representing each destination and flight information
    struct Node {
        string name;               // Destination or source name
        string date;               // Date of the flight
        string departure_time;     // Departure time of the flight
        string arrival_time;       // Arrival time of the flight
        string cost;               // Cost of the flight
        string flight;             // Flight name
        string hotelfair;          // Hotel charges per day at destination
        Node *next;                // Pointer to the next destination node

        // Constructor for source node
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

        // Constructor for destination node with flight information
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

    // Array to store source nodes (with linked destinations)
    int index;
    Node* array[10];

public:
    // Constructor to initialize the array and index
    FlightReservationSystem() {
        index = 0;
        for (int i = 0; i < 10; i++) {
            array[i] = nullptr;
        }
    }

    // Search for a source node by name and return its index, -1 if not found
    int search(string src) {
        for (int i = 0; i < index; i++) {
            if (array[i]->name == src)
                return i;
        }
        return -1;
    }

    // Insert a source node if it doesn't already exist
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

    // Insert a destination node in the linked list of a source node
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

    // Convert string to integer (for cost comparison)
    int stringToInt(string s) {
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }

    // Find the minimum price path from source to destination and store it in a file
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
                // Save the flight with the highest fare
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

    // Find the minimum time path from source to destination and store it in a file
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
                // Save the flight with the shortest duration (lowest cost assumed to represent time here)
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

    // Display all flights between a source and destination
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

    // Display flights on a specific date between a source and destination
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

    // Display flights from a specific airline between a source and destination
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

    // Display all direct flights from each source with their hotel charges
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

    // Load flight data from a file and populate the flight reservation system
    void loadFlightData(const string& filename) {
        ifstream in(filename);
        string input;
        while (getline(in, input)) {
            istringstream iss(input);
            string src, dst, dte, d_t, a_t, cst, flt;
            iss >> src >> dst >> dte >> d_t >> a_t >> cst >> flt;

            // Insert source and destination nodes
            sourceInsert(src);
            int index = search(src);
            Node* nd = new Node(dst, dte, d_t, a_t, cst, flt);
            insert(index, nd);
        }
        in.close();
    }

    // Helper function to display contents of a file
    void displayFile(const string& filename) {
        ifstream myfile(filename);
        string line;
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << endl;
            }
            myfile.close();
        }
    }
};

// Main function to demonstrate the flight reservation system
int main() {
    FlightReservationSystem system;

    // Load flight data from a file
    system.loadFlightData("flightdata.txt");

    // Example function calls
    system.minimumPricePath("NY", "LA");
    system.minimumTimePath("NY", "LA");
    system.path("NY", "LA");
    system.datePath("NY", "LA", "12-12-2024");
    system.flightPath("NY", "LA", "Delta");
    system.displayDirectFlights();

    return 0;
}
