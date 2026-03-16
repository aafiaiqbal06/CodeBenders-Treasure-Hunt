#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class SecondFloorECE {
private:
    struct Classroom {
        int roomNumber;
        string name;
        int capacity;
        bool hasProjector;
        bool hasAC;
        string incharge;
    };
    
    vector<Classroom> classrooms;
    
public:
    SecondFloorECE() {
        // Initialize the 10 classrooms on second floor
        initializeClassrooms();
    }
    
    void initializeClassrooms() {
        classrooms = {
            {201, "Digital Electronics Lab", 40, true, true, "Dr. Sharma"},
            {202, "Microprocessor Lab", 35, true, true, "Prof. Verma"},
            {203, "VLSI Design Lab", 30, true, true, "Dr. Gupta"},
            {204, "Communication Systems", 45, true, true, "Prof. Singh"},
            {205, "Embedded Systems Lab", 25, true, true, "Dr. Kumar"},
            {206, "Signal Processing Lab", 30, true, false, "Prof. Reddy"},
            {207, "Control Systems", 40, true, true, "Dr. Patil"},
            {208, "Project Lab", 20, true, false, "Prof. Menon"},
            {209, "Seminar Hall", 60, true, true, "Dr. Joshi"},
            {210, "Faculty Research Lab", 15, true, true, "Prof. Desai"}
        };
    }
    
    void displayAllClassrooms() {
        cout << "\n" << string(80, '=') << endl;
        cout << "      SECOND FLOOR - ELECTRONICS & COMMUNICATION ENGINEERING" << endl;
        cout << "            (10 Classrooms in ECE Block - 2nd Floor)" << endl;
        cout << string(80, '=') << endl;
        
        cout << left 
             << setw(10) << "Room No."
             << setw(30) << "Classroom Name"
             << setw(10) << "Capacity"
             << setw(12) << "Projector"
             << setw(10) << "AC"
             << "Incharge" << endl;
        cout << string(80, '-') << endl;
        
        for (const auto& room : classrooms) {
            cout << left
                 << setw(10) << room.roomNumber
                 << setw(30) << room.name
                 << setw(10) << room.capacity
                 << setw(12) << (room.hasProjector ? "✅ Yes" : "❌ No")
                 << setw(10) << (room.hasAC ? "✅ Yes" : "❌ No")
                 << room.incharge << endl;
        }
        cout << string(80, '-') << endl;
        cout << "Total Classrooms: " << classrooms.size() << " on Second Floor" << endl;
        cout << string(80, '=') << endl;
    }
    
    void displayFloorMap() {
        cout << "\n🏛️  SECOND FLOOR MAP - ECE BLOCK 🏛️\n";
        cout << string(50, '-') << endl;
        cout << "   STAIRS   ";
        cout << "\n┌──────┬──────┬──────┬──────┬──────┐";
        cout << "\n│ 201  │ 202  │ 203  │ 204  │ 205  │";
        cout << "\n│Digital│Micro │ VLSI │ Comm │Embed-│";
        cout << "\n│ Lab  │ Lab  │ Lab  │System│ ded  │";
        cout << "\n├──────┼──────┼──────┼──────┼──────┤";
        cout << "\n│ 206  │ 207  │ 208  │ 209  │ 210  │";
        cout << "\n│Signal│Control│Project│Semi- │Faculty│";
        cout << "\n│Proc. │System│ Lab  │narHall│Research│";
        cout << "\n└──────┴──────┴──────┴──────┴──────┘";
        cout << "\n   ELEVATOR    ";
        cout << "\n" << string(50, '-') << endl;
    }
    
    void getRoomDetails(int roomNo) {
        for (const auto& room : classrooms) {
            if (room.roomNumber == roomNo) {
                cout << "\n📋 ROOM " << roomNo << " DETAILS:" << endl;
                cout << string(30, '-') << endl;
                cout << "Name: " << room.name << endl;
                cout << "Capacity: " << room.capacity << " students" << endl;
                cout << "Projector: " << (room.hasProjector ? "Available" : "Not Available") << endl;
                cout << "Air Conditioning: " << (room.hasAC ? "Yes" : "No") << endl;
                cout << "Incharge: " << room.incharge << endl;
                return;
            }
        }
        cout << "❌ Room " << roomNo << " not found on second floor!" << endl;
    }
    
    void countByFacility() {
        int withProjector = 0, withAC = 0;
        for (const auto& room : classrooms) {
            if (room.hasProjector) withProjector++;
            if (room.hasAC) withAC++;
        }
        
        cout << "\n📊 FACILITY SUMMARY (2nd Floor):" << endl;
        cout << string(30, '-') << endl;
        cout << "Total Classrooms: " << classrooms.size() << endl;
        cout << "Rooms with Projector: " << withProjector << "/" << classrooms.size() << endl;
        cout << "Rooms with AC: " << withAC << "/" << classrooms.size() << endl;
    }
};

int main() {
    SecondFloorECE eceSecondFloor;
    int choice, roomNo;
    
    cout << "\n⭐ WELCOME TO ECE DEPARTMENT - SECOND FLOOR ⭐" << endl;
    
    do {
        cout << "\n📌 MENU:" << endl;
        cout << string(30, '-') << endl;
        cout << "1. Show all 10 classrooms (2nd Floor)" << endl;
        cout << "2. Display floor map" << endl;
        cout << "3. Get specific room details" << endl;
        cout << "4. Facility summary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                eceSecondFloor.displayAllClassrooms();
                break;
                
            case 2:
                eceSecondFloor.displayFloorMap();
                break;
                
            case 3:
                cout << "Enter room number (201-210): ";
                cin >> roomNo;
                eceSecondFloor.getRoomDetails(roomNo);
                break;
                
            case 4:
                eceSecondFloor.countByFacility();
                break;
                
            case 5:
                cout << "\n👋 Exiting... Thank you!" << endl;
                break;
                
            default:
                cout << "❌ Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 5);
    
    return 0;
}
