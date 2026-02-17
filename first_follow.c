#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

char production[MAX][MAX];
char first[MAX], follow[MAX];
int count, n;

void findFirst(char c) {
    if(!isupper(c)) {
        printf("%c ", c);
        return;
    }

    for(int i=0;i<n;i++) {
        if(production[i][0]==c) {
            if(production[i][2]=='$') {
                printf("$ ");
            }
            else {
                findFirst(production[i][2]);
            }
        }
    }
}

void findFollow(char c) {
    if(production[0][0]==c)
        printf("$ ");

    for(int i=0;i<n;i++) {
        for(int j=2;j<strlen(production[i]);j++) {
            if(production[i][j]==c) {

                if(production[i][j+1]!='\0') {
                    findFirst(production[i][j+1]);
                }

                if(production[i][j+1]=='\0' && c!=production[i][0]) {
                    findFollow(production[i][0]);
                }
            }
        }
    }
}

int main() {

    printf("Enter number of productions: ");
    scanf("%d",&n);

    printf("Enter productions (Example: E=TR):\n");
    for(int i=0;i<n;i++)
        scanf("%s",production[i]);

    char choice;

    do {
        char c;
        printf("\nFind FIRST and FOLLOW of: ");
        scanf(" %c",&c);

        printf("FIRST(%c) = { ",c);
        findFirst(c);
        printf("}\n");

        printf("FOLLOW(%c) = { ",c);
        findFollow(c);
        printf("}\n");

        printf("\nContinue? (y/n): ");
        scanf(" %c",&choice);

    } while(choice=='y');

    return 0;
}