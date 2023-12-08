#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define NC "\033[0m"

void usb() {
    printf("%sComming Soon%s\n", GREEN, NC);
}

void wireless() {
    sleep(2);
    
    char iport[150];
    printf("%sEnter %sPairing%s IP like this example (127.0.0.1): %s", YELLOW, RED, YELLOW, NC);
    scanf("%149s", iport);
    char code[150];
    printf("%sEnter pairing %sCODE: %s", YELLOW, RED, NC);
    scanf("%149s", code);
    char command[150]; 
    snprintf(command, sizeof(command), "adb pair %s %s", iport, code);
    int stat = system(command);
    if(stat!=0){
      exit(stat);;
    }

    char ciport[50];
    printf("%sENTER %sConnecting%s Ip and Port: %s", YELLOW, RED, YELLOW, NC);
    scanf("%49s", ciport);
    char commandb[100];
    sprintf(commandb, "adb connect %s", ciport);
    system(commandb);
    char uninstallCmd[100];
    while (1) {
        printf("%sEnter a package name to uninstall (or 'done' to finish, 'restart' to start again): %s", YELLOW, NC);
        char package[100];
        scanf("%99s", package);


        // Check if the package is not equal to "done"
        if (strcmp(package, "done") != 0) {
            // Uninstall the package
            sprintf(uninstallCmd, "adb shell pm uninstall --user 0 %s", package);
            printf("%sUninstalling %s%s\n", RED, CYAN, package);
            system(uninstallCmd);
        } else {
            printf("%s***%sThanks for using Piyush Debloat Script%s\n", RED, CYAN, NC);
            printf("%s                **%sNow Exiting%s**%s\n", RED, CYAN, RED, NC);
            system("adb disconnect > /dev/null 2>&1");
            break;
        }
    }
}


int main() {
    system("clear");
    printf("%s***%sWelcome to common debloat tool for all devices%s***%s\n", RED, CYAN, RED, NC);
    printf("%s          ***%sWritten By Piyush Verma%s***%s\n", RED, CYAN, RED, NC);
    printf("%s             **%sMADE FOR %sARM64/AARCH64%s**%s\n", RED, YELLOW, CYAN, RED, NC);
    sleep(2);

    printf("%s**[WARNING]**%s\n", RED, NC);
    printf("%sBoth options can be done in Linux and Termux, but if you are in a phone with Termux and you don't have USB and OTG, use the 2nd option. Now, if you don't have a PC, use a 2nd phone with OTG and put this script on the 2nd phone with Termux and start debloating on the first phone%s\n", YELLOW, NC);

    printf("%sSelect an option:\n", YELLOW);
    printf("1. Perform in Linux-GNU PC via USB\n");
    printf("2. Perform in Termux via Wireless debugging%s\n", NC);

    printf("%sEnter your choice (1 or 2): %s", CYAN, NC);

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%sYour choice is Linux.\n", YELLOW);
            printf("Connect device via Cable\n");
            printf("Waiting for Device%s\n", NC);
            usb();
            break;
        case 2:
            printf("%sYour choice is Termux.\n", YELLOW);
            printf("Make a floating window or split screen with setting and open setting enable wireless debugging and select pair device with pairing code%s\n", NC);
            wireless();
            break;
        default:
            printf("%sInvalid choice. Please enter 1 or 2.%s\n", RED, NC);
            break;
    }

    return 0;
}
