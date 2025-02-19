#include <stdio.h>
#include <string.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_SIZE 26

char shift_char(char c, int shift) {
    int index = c - 'A';
    index = (index + shift) % ALPHABET_SIZE;
    if (index < 0) index += ALPHABET_SIZE;
    return ALPHABET[index];
}

void encrypt(char *text, int rotor_positions[3], int original_positions[3]) {
    int i, j;
    int current_positions[3];
    // Save the current rotor positions to avoid altering original positions
    memcpy(current_positions, rotor_positions, sizeof(current_positions));

    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            for (j = 0; j < 3; j++) {
                text[i] = shift_char(text[i], current_positions[j]);
                current_positions[j] = (current_positions[j] + 1) % ALPHABET_SIZE;
            }
        }
    }
}

void decrypt(char *text, int rotor_positions[3], int original_positions[3]) {
    int i, j;
    int current_positions[3];
    // Save the original rotor positions to reset them during decryption
    memcpy(current_positions, rotor_positions, sizeof(current_positions));

    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            for (j = 0; j < 3; j++) {
                text[i] = shift_char(text[i], -current_positions[j]);
                current_positions[j] = (current_positions[j] + 1) % ALPHABET_SIZE;
            }
        }
    }
}

void view_rotor_positions(int rotor_positions[3]) {
    printf("Current rotor positions:\n");
    printf("Rotor 1: %d\n", rotor_positions[0]);
    printf("Rotor 2: %d\n", rotor_positions[1]);
    printf("Rotor 3: %d\n", rotor_positions[2]);
}

void set_rotor_positions(int rotor_positions[3]) {
    int i;
    printf("Enter the starting positions of the 3 rotors (0-25):\n");
    for (i = 0; i < 3; i++) {
        do {
            printf("Rotor %d position: ", i + 1);
            scanf("%d", &rotor_positions[i]);
            if (rotor_positions[i] < 0 || rotor_positions[i] >= ALPHABET_SIZE) {
                printf("Invalid position. Please enter a value between 0 and 25.\n");
            }
        } while (rotor_positions[i] < 0 || rotor_positions[i] >= ALPHABET_SIZE);
    }
}

int main() {
    char text[100];
    int rotor_positions[3], original_positions[3];
    int choice;

    printf("Welcome to the Enigma Machine Simulation!\n\n");

    set_rotor_positions(rotor_positions);  // Set the initial rotor positions
    memcpy(original_positions, rotor_positions, sizeof(rotor_positions));  // Store original positions for reference

    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. View current rotor positions\n");
        printf("4. Set or reset rotor positions\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the message (uppercase letters and spaces allowed): ");
            getchar();  // newline character from previous input
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0;  // Remove the newline character
            
            encrypt(text, rotor_positions, original_positions);
            printf("Encrypted message: %s\n", text);
        } else if (choice == 2) {
            printf("Enter the encrypted message (uppercase letters and spaces allowed): ");
            getchar();  // to consume newline character from previous input
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = 0;  // remove the newline character
            
            decrypt(text, rotor_positions, original_positions);
            printf("Decrypted message: %s\n", text);
        } else if (choice == 3) {
            view_rotor_positions(rotor_positions);
        } else if (choice == 4) {
            set_rotor_positions(rotor_positions);  // Option to set or reset rotor positions
            memcpy(original_positions, rotor_positions, sizeof(rotor_positions));  // Update original positions
        } else if (choice != 5) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
