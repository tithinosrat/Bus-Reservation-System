#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 5
#define MAX_SEATS 32

const char *buses[MAX_BUSES] = {"Mangalore Express", "Karwar Express", "Airavat Express", "SeaBird Express", "Newport Express"};
char passengerNames[MAX_SEATS][100] = {0};
int seatStatus[MAX_SEATS] = {0};
int selectedBus;

void showBusList();
void bookTickets();
void cancelBooking();
void showStatus();
void login();

int main() {
    login();
    int choice;

    do {
        system("cls");
        printf("\n====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n");
        printf("[1] View Bus List\n");
        printf("[2] Book Tickets\n");
        printf("[3] Cancel Booking\n");
        printf("[4] Bus Status Board\n");
        printf("[5] Exit\n");
        printf("===============================================================================================================\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: showBusList(); break;
            case 2: bookTickets(); break;
            case 3: cancelBooking(); break;
            case 4: showStatus(); break;
            case 5: break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }
        if (choice != 5) {
            printf("Press any key to continue...");
            getch();
        }
    } while (choice != 5);

    printf("\nThank You For Using This System\n");
    return 0;
}

void showBusList() {
    system("cls");
    printf("\n=========================================== BUS LIST ============================================\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        printf("[%d] %s\n", i + 1, buses[i]);
    }
}

void bookTickets() {
    int tickets, seatNumber;

    system("cls");
    showBusList();
    printf("Enter the Bus number: ");
    scanf("%d", &selectedBus);
    selectedBus--;

    if (selectedBus < 0 || selectedBus >= MAX_BUSES) {
        printf("Invalid bus number!\n");
        return;
    }

    system("cls");
    printf("=========================================== BOOKING ============================================\n");
    printf("Your Bus: %s\n", buses[selectedBus]);

    printf("Number of Tickets: ");
    scanf("%d", &tickets);

    if (tickets > MAX_SEATS) {
        printf("Not enough seats available.\n");
        return;
    }

    for (int i = 0; i < tickets; i++) {
        printf("Enter seat number for ticket %d: ", i + 1);
        scanf("%d", &seatNumber);
        if (seatNumber < 1 || seatNumber > MAX_SEATS || seatStatus[seatNumber - 1] == 1) {
            printf("Invalid or already booked seat number. Please try again.\n");
            i--;
            continue;
        }
        printf("Enter name for seat %d: ", seatNumber);
        scanf("%s", passengerNames[seatNumber - 1]);
        seatStatus[seatNumber - 1] = 1;
    }

    printf("Total booking amount is %d\n", 200 * tickets);
}

void cancelBooking() {
    int seatNumber;

    system("cls");
    printf("Enter the bus number: ");
    scanf("%d", &selectedBus);
    selectedBus--;

    if (selectedBus < 0 || selectedBus >= MAX_BUSES) {
        printf("Invalid bus number!\n");
        return;
    }

    showStatus();

    printf("Enter the seat number to cancel: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS || seatStatus[seatNumber - 1] == 0) {
        printf("Invalid seat number!\n");
        return;
    }

    seatStatus[seatNumber - 1] = 0;
    strcpy(passengerNames[seatNumber - 1], "");

    printf("Your 200 rupees has been returned.\n");
}

void showStatus() {
    system("cls");
    printf("=========================================== BUS STATUS ============================================\n");
    printf("Bus: %s\n", buses[selectedBus]);
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seatStatus[i] == 0 ? "Empty" : passengerNames[i]);
    }
}

void login() {
    char uname[10], pword[10];
    const char user[] = "user";
    const char pass[] = "pass";
    int attempts = 0;

    while (attempts < 3) {
        system("cls");
        printf("\n========================= LOGIN FORM =========================");
        printf("\nENTER USERNAME: ");
        scanf("%s", uname);
        printf("ENTER PASSWORD: ");
        scanf("%s", pword);

        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            printf("WELCOME TO OUR SYSTEM! LOGIN SUCCESSFUL\n");
            break;
        } else {
            printf("SORRY! LOGIN UNSUCCESSFUL\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many failed attempts. Exiting...\n");
        exit(0);
    }
}
