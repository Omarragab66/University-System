#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHOICE_RANGE 10
enum USER {dean = 1, professors, students};
enum SL {Soft_Link = 1, Hard_Link};

void Dean(int choice);
void Professors (int choice);
void Students (int choice);
void listF_D (int user);
void Ch_Permissions (int user);
void Update(int user_update, char* command);
void Make_Remove(int user);
void create_symlink(int user);
void Copy_F_D(int user);
void Move_F_D(int user);
void Redirection(int user);
void create_alias(int user);
void viewFileContent(int user);
void search_files(int user);

char deann [] = "dean";
char profs [] = "professors";
char studs [] = "students";

int main ()
{   
    int user;
    int choice;
    while (1) {
        printf ("__________________________________");

        printf ("\nLogin As: \n> 1: Dean\n> 2: Professors\n> 3: Students\n> 99: exit\n> ");
        scanf ("%i", &user);

        if (user == dean){
        printf ("\n"
        "> 1: List files/directories\n"
        "> 2: Change permissions of files/directories\n"
        "> 3: Make/delete files/directories\n"
        "> 4: Create symbolic link files\n"
        "> 5: Copy files/directories\n"
        "> 8: Set and use aliases for common tasks\n"
        "> 10: Find files or directories using find or grep\n"
        );
        printf ("> ");
        scanf ("%i", &choice);
        }

        else if (user == professors || user == students){
        printf ("\n"
            "> 1: List files/directories\n"
            "> 3: Make/delete files/directories\n"
            "> 5: Copy files/directories\n"
            "> 6: Move files/directories\n"
            "> 7: Use redirection to create or update files\n"
            "> 8: Set and use aliases for common tasks\n"
            "> 9: View file contents\n"
            "> 10: Find files or directories using find or grep\n"
            );
        printf ("> ");
        scanf ("%i", &choice);
        }

        if (user == 99){
            printf ("\n\nExiting..\n\n");
            return 0;
        }


    for (int i = 1; i <= CHOICE_RANGE; i++)
    {
        if (choice == i){
            if (user ==  dean  && (choice == 2 || choice == 4)){
                Dean(i);
            }

            else if (user == dean && (choice != 9 || choice != 6)){
                Dean(choice);
            }
            else if (user == professors){
                Professors(choice);
            }
            else if(user == students){
                Students(choice);
            }
        }
    }

    }
}

void Dean (int choice) {
    switch (choice){
        case 1:
            listF_D(dean);
            break;
        case 2:
            Ch_Permissions(dean);
            break;
        case 3:
            Make_Remove(dean);
            break;
        case 4:
            create_symlink(dean); 
            break;     
        case 5:
            Copy_F_D(dean);
            break;
        case 8:
            create_alias(dean);
            break;
        case 10:
            search_files(dean);
            break;

    }
}

void Professors (int choice) {
    switch (choice){
        case 1:
            listF_D(professors);
            break;
        case 3:
            Make_Remove(professors);
            break;
        case 5:
            Copy_F_D(professors);
            break;
        case 6:
            Move_F_D(professors);
            break;
        case 7:
            Redirection(professors);
            break;       
        case 8:
            create_alias(professors);
            break;    
        case 9:
            viewFileContent(professors);
            break;
        case 10:
            search_files(professors);
            break;
    }

}

void Students (int choice) {
    switch (choice){
        case 1:
            listF_D(students);
            break;
        case 3:
            Make_Remove(students);
            break;
        case 5:
            Copy_F_D(students);
            break;
        case 6:
            Move_F_D(students);
            break;
        case 7:
            Redirection(students);
            break;        
        case 8:
            create_alias(students);
            break; 
        case 9:
            viewFileContent(students);
            break;
        case 10:
            search_files(students);
            break;
    }
}

void listF_D (int user)
{
    switch(user){
        case dean: 
            system("su dean -c \"ls -l /home/dean\"");
        break;

        case professors:
            system("su professors -c 'ls -l /home/professors'");
            break;
   
        case students:
            system("su students -c 'ls -l /home/students'");
            break;
    }
}

void Update(int user_update, char* command) {
    char permissions[50];
    char F_D_N[50];
    printf("\n*(YOU CAN SET MORE THAN ONE PERMISSION BY ADDING THEM)*");
    printf("\n(1)execute\n(2)write\n(4)read\n(0) No permissions");

    printf("\nEnter The D_F Name: ");
    scanf("%s", F_D_N);

    printf("\nEnter The Permission: ");
    scanf("%s", permissions);
    
    if (user_update == dean) {
        printf ("Enter dean\n");
        snprintf(command, 200, "su dean -c 'cd /home/dean && sudo -S chmod %s %s;ls -l /home/dean'", permissions, F_D_N);
    }

    else if (user_update == professors) {
        printf ("Enter dean\n");
        snprintf(command, 200, "su dean -c \"cd /home/professors && sudo -S chmod %s %s;ls -l /home/professors\"", permissions, F_D_N);
        
    }

        else if (user_update == students) {
        printf ("Enter dean\n");
        snprintf(command, 200, "su dean -c \"cd /home/students && sudo -S chmod %s %s; ls -l /home/students\"", permissions, F_D_N);
    }
}

void Ch_Permissions(int user) {
    char command[200];
    char Listing[200];
    int user_update;
    printf("> Who you want to update?:\n> (1)dean\n> (2)professors\n> (3)students: ");
    scanf("%i", &user_update);
    switch (user_update)
        {
        case dean:
            system("echo Enter dean passoword to List before updating: ");
            snprintf(Listing, 200, "su dean -c 'ls -l /home/%s'", deann);
            system(Listing);
            break;

        case professors:
            system("echo Enter dean passoword to List before updating: ");
            snprintf(Listing, 200, "su dean -c 'ls -l /home/%s'", profs);
            system(Listing);
            break;

        case students:
            system("echo Enter dean passoword to List before updating: ");
            snprintf(Listing, 200, "su dean -c 'ls -l /home/%s'", studs);
            system(Listing);
        
        default:
            break;
        }
        
    Update(user_update, command);
    int check = system(command);
    if (check == 0)
    {
        printf ("\n");
        system("echo Directory has been updated.");
    }

    }

void Make_Remove(int user)
{
    int choice;
    char command[100];
    char file_name[50];
    char dir_name[50];
    int COMPLETION;
    switch (user)
    {
    case dean:

        printf("\n(1)create directory /professors\n(2)remove directory /professors\n> ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter the name of directory: \n> ");
            scanf("%s", &dir_name);
            snprintf(command, 100, "su dean -c\"cd /home/professors && mkdir %s;ls -l /home/professors\"", dir_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed created..\n", dir_name);
        }

        else if (choice == 2)
        {
            system("echo dean password for listing");
            system("su dean -c 'cd /home/professors;ls -l'");
            printf("\nEnter the name of directory: \n> ");
            scanf("%s", &dir_name);
            snprintf(command, 100, "su dean -c\"cd /home/professors &&rm -r %s;ls -l\"", dir_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed removed..\n", dir_name);
        }
        break;

    case professors:
        printf("\n(1)create directory /professors\n(2)remove directory /professors\n> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter the name of directory: \n> ");
            scanf("%s", &dir_name);
            snprintf(command, 100, "su professors -c\"cd /home/professors && mkdir %s;ls -l\"", dir_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed created..\n", dir_name);
        }

        else if (choice == 2)
        {   system("echo professors password for listing");
            system("su professors -c 'cd ~;ls -l'");
            printf("\nEnter the name of directory: \n> ");
            scanf("%s", &dir_name);
            snprintf(command, 100, "su professors -c\"cd /home/professors;rm -r %s;ls -l\"", dir_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed removed..\n", dir_name); 
        }
        break;

    case students:

        printf("\n(1)create file /students\n(2)remove file /students\n> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter the name of the file: \n> ");
            scanf("%s", &file_name);
            snprintf(command, 100, "su students -c\"cd /home/students && touch %s;ls -l\"", file_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed created..\n", file_name);            
        }

        else if (choice == 2)
        {   system("echo students password for listing");
            system("su students -c 'cd ~;ls -l'");
            printf("\nEnter the name of the file: \n> ");
            scanf("%s", &file_name);
            snprintf(command, 100, "su students -c\"cd /home/students;rm %s;ls -l\"", file_name);
            COMPLETION = system(command);
            if (COMPLETION == 0) printf ("\n'%s' has beed removed..\n", file_name);
        }
        break;
    default:
        printf("Invalid user.\n");
      break;
      }
}

void create_symlink(int user)

{
    char target[100];
    char link_name[100];
    int user_choice;
    int L_Choose;
    char command[200];
    char user_[200];
    if (user == dean)
    {

        printf ("\nChoose the user to create SL in \n(1)dean (2)professors (3)students: ");
        scanf ("%i", &user_choice);
        system("echo Enter dean passoword to List before updating: ");
        system("su dean -c 'ls -l /home/dean'");

        printf("\nEnter the target file: ");
        scanf("%s", target);

        printf ("\n(1)Soft_Link (2)Hard Link: ");
        scanf ("%i", &L_Choose);

        printf("\nEnter the symbolic link name: ");
        scanf("%s", link_name);

        switch (user_choice)
        {
        case dean:
            if (L_Choose == Soft_Link){
            snprintf(command, 200, "su dean -c \"ln -s /home/dean/%s /home/dean/%s;ls -l /home/dean\"", target, link_name);
            }
            else if (L_Choose == Hard_Link){
                snprintf(command, 200, "su dean -c \"ln /home/dean/%s /home/dean/%s;ls -l /home/dean\"", target, link_name);
            }
            break;
        
        case professors:
            if (L_Choose == Soft_Link){
            snprintf(command, 200, "su dean -c \"ln -s /home/dean/%s /home/professors/%s;ls -l /home/professors\"", target, link_name);
            }
            else if (L_Choose == Hard_Link){
                snprintf(command, 200, "su dean -c \"ln /home/dean/%s /home/professors/%s;ls -l /home/professors\"", target, link_name);
            }
            break;
        case students:
            if (L_Choose == Soft_Link){
            snprintf(command, 200, "su dean -c \"ln -s /home/dean/%s /home/students/%s;ls -l /home/students\"", target, link_name);
            }
            else if (L_Choose == Hard_Link){
                snprintf(command, 200, "su dean -c \"ln /home/dean/%s /home/students/%s;ls -l /home/students\"", target, link_name);
            }
            break;
        default:
            break;
        }
        
        int result = system(command);

        if (result == 0)
        {
            printf("\nSymbolic link created successfully: %s -> %s\n", link_name, target);
        }
    }
}

void Copy_F_D(int user){
    char command[200];
    char SOURCE[200];
    char DEST[200];
    int choice;
    char COMPLETE[200];

    if (user == dean)
    {
        printf("> Who you want to copy file to?:\n> (1)dean\n> (2)professors\n> (3)students: ");
        scanf ("%i", &choice);

        system("echo Enter dean password for listing");
        listF_D (dean);

        printf ("\nEnter the source file name: ");
        scanf ("%s", SOURCE);

        printf ("\nEnter the destination file name: ");
        scanf ("%s", DEST);
        printf ("\n");

        switch (choice)
        {
        case dean:

            system("echo dean");
            snprintf(command, 200, "su dean -c 'cd ~;cp %s %s;ls -l'", SOURCE, DEST);
            system(command);
            printf ("\n");
            snprintf(COMPLETE, 200, "echo %s has been copied to %s", SOURCE, DEST);
            system(COMPLETE);
            break;

        case professors:
            system("echo dean");
            snprintf(command, 200, "su dean -c 'cd ~;cp %s /home/professors/%s;ls -l /home/professors'", SOURCE, DEST);
            system(command);
            printf ("\n");
            snprintf(COMPLETE, 200, "echo %s has been copied to %s", SOURCE, DEST);
            system(COMPLETE);
            break;

        case students:
            system("echo dean");
            snprintf(command, 200, "su dean -c 'cd ~;cp %s /home/students/%s;ls -l /home/students'", SOURCE, DEST);
            system(command);
            printf ("\n");
            snprintf(COMPLETE, 200, "echo %s has been copied to %s", SOURCE, DEST);
            system(COMPLETE);
            break;
        }
    }

    else if (user == professors)
    {
        printf("> Who you want to copy file to?:\n> (1)professors\n> (2)students: ");
        scanf ("%i", &choice);

        system("echo Enter professors password for listing");
        listF_D (professors);

        printf ("\nEnter the source file name: ");
        scanf ("%s", SOURCE);

        printf ("\nEnter the destination file name: ");
        scanf ("%s", DEST);
        printf ("\n");

        switch (choice)
        {
        case professors - 1:
            system("echo professors");
            snprintf(command, 200, "su professors -c 'cd ~;cp %s %s;ls -l'", SOURCE, DEST);
            system(command);
            printf ("\n");
            snprintf(COMPLETE, 200, "echo %s has been copied to %s", SOURCE, DEST);
            system(COMPLETE);
            break;
        
        case students - 1:
            system("echo professors");
            snprintf(command, 200, "su professors -c 'cd ~;cp %s /home/students/%s;ls -l /home/students'", SOURCE, DEST);
            system(command);
            printf ("\n");
            snprintf(COMPLETE, 200, "echo %s has been copied to %s", SOURCE, DEST);
            system(COMPLETE);
            break;
        }
    }

   else if (user == students){

        system("echo Enter Students password for listing");
        listF_D (students);

        printf ("\nEnter the source file name: ");
        scanf ("%s", SOURCE);

        printf ("\nEnter the destination file name: ");
        scanf ("%s", DEST);
        printf ("\n");

        system("echo students");
        snprintf(command, 200, "su students -c 'cd ~;cp %s %s;ls -l'", SOURCE,DEST);
        system(command);
    }

}

void Move_F_D(int user) {
char command[200];
char source_path[200]; 
char destination_path[200];

if (user == professors || user == students) {

    if (user == professors)
    {
        system("echo Enter Professors for Listing");
        listF_D(professors);
    }
    else{
        system("echo Enter Students for Listing");
        listF_D(students);
    }
        printf("\nEnter the file or directory name to move: ");
        scanf("%s", source_path);
        printf("\nEnter the desired destination: ");
        scanf("%s", destination_path);
    }

else {
        printf("invalid user type.\n");
    }
if (user == professors) {
    system("echo Enter Professors");
        snprintf(command, 200, "su professors -c 'mv -i /home/professors/%s /home/professors/%s'", source_path, destination_path);
        system(command);
        printf ("\nDONE..\n");
    }
else if (user == students) {
    system("echo Enter Students");
        snprintf(command, 200, "su students -c 'mv -i /home/students/%s /home/students/%s'", source_path, destination_path);
        system(command);
        printf ("\nDONE..\n");
    } 
else {
        printf("invalid user type.\n");
    }
}

void Redirection(int user) {
    char command[200];
    char C_U_F[200];
    char TEXT[200];
    int C_U_CHOICE;

    if (user == professors) {
        system("echo Enter professors password for listing");
        system("su - professors -c 'ls -l /home/students'");

        printf("\nEnter the name of the log or note you want to update: \n");
        scanf("%s", C_U_F);

        printf("\nWrite what you want to update: \n");
        while (getchar() != '\n');
        fgets(TEXT, sizeof(TEXT), stdin);
        TEXT[strcspn(TEXT, "\n")] = '\0';

        snprintf(command, 200,"su - professors -c 'echo \"%s\" >> /home/students/%s'", TEXT, C_U_F);

        int result = system(command);
        if (result != 0) {
            printf("INVALID..\n");
        }
    } else if (user == students) {
        printf("\nDo you want to create or update assignment?:\n");
        printf("> 1: Create\n> 2: Update\n");
        scanf("%i", &C_U_CHOICE);

        switch (C_U_CHOICE) {
        case 1:
            printf("\n   (*if the file already exists, it rewrites the assignment*)\nEnter the name of the assignment you want to create:\n");
            scanf("%s", C_U_F);

            printf("\nWrite what you want to add:\n");
            while (getchar() != '\n');
            fgets(TEXT, sizeof(TEXT), stdin);
            TEXT[strcspn(TEXT, "\n")] = '\0';

            snprintf(command, 200,"su - students -c 'echo \"%s\" > /home/students/%s'", TEXT, C_U_F);

            system(command);
            break;

        case 2:
            system("echo Enter students password for listing");
            system("su - students -c 'ls -l /home/students'");
            printf("\nEnter the name of the assignment you want to update: \n");
            scanf("%s", C_U_F);

            printf("\nWrite what you want to update: \n");
            while (getchar() != '\n');
            fgets(TEXT, sizeof(TEXT), stdin);
            TEXT[strcspn(TEXT, "\n")] = '\0';

            snprintf(command, 200,"su - students -c 'echo \"%s\" >> /home/students/%s'", TEXT, C_U_F);

            system(command);
            break;

        default:
            printf("\n\nINVALID INPUT\n\n");
            break;
        }
    }
}


void create_alias(int user) {
    char alias_name[50];
    char command[200];
    char get_command[200];
    printf("\nEnter the alias name: ");
    scanf("%s", alias_name);

    printf("\nEnter the command you want the alias to run: ");
    while (getchar() != '\n');
    fgets(get_command, sizeof(get_command), stdin);
    get_command[strcspn(get_command, "\n")] = '\0';

    if (user == dean) {
        snprintf(command, 200, "su dean -c 'cd ~; echo alias %s=\\\"%s\\\" >> /home/dean/.bashrc; source /home/dean/.bashrc'", alias_name, get_command);
        system(command);

        printf("\nAlias created successfully for Dean user.\n");
    } else if (user == professors) {
        snprintf(command, 200, "su professors -c 'cd ~; echo alias %s=\\\"%s\\\" >> /home/professors/.bashrc; source /home/professors/.bashrc'", alias_name, get_command);
        system(command);

        printf("\nAlias created successfully for Professor user.\n");
    } else if (user == students) {
        snprintf(command, 200, "su students -c 'cd ~; echo alias %s=\\\"%s\\\" >> /home/students/.bashrc; source /home/students/.bashrc'", alias_name, get_command);
        system(command);

        printf("\nAlias created successfully for Student user.\n");
    }
}

void viewFileContent(int user) 
{
    char fileName[100];
    int viewOption;
    int numLines;
    char command[200];
    if (user == professors){
        system("echo Enter professors password for Listing");
        printf ("\n");
        listF_D(professors);
    }
    else{
        system("echo Enter students password for Listing");
        printf ("\n");
        listF_D(students);
    }
    printf("\nEnter the file name to view its content: ");
    scanf("%s", fileName);

    printf("\nChoose how to view the file:\n");
    printf("1. View entire content (cat)\n");
    printf("2. View first n lines (head)\n");
    printf("3. View last n lines (tail)\n");
    printf("> ");
    scanf("%d", &viewOption);

    switch (viewOption) 
    {
        case 1:
            if (user == professors)
             {
                snprintf(command, 200, "su professors -c 'cat /home/professors/%s'", fileName);

            } else if (user == students) {
                snprintf(command, 200, "su students -c 'cat /home/students/%s'", fileName);
            }
            break;

        case 2:
            printf("\nEnter the number of lines to display from the start: ");
            scanf("%d", &numLines);
                if (user == professors) 
                {
                snprintf(command, 200, "su professors -c 'head -n %d /home/professors/%s'", numLines, fileName);
            } 

            else if (user == students) {
                snprintf(command, 200, "su students -c 'head -n %d /home/students/%s'", numLines, fileName);
            }
            break;

        case 3:
            printf("\nEnter the number of lines to display from the end: ");
            scanf("%d", &numLines);
            if (user == professors) 
            {
                snprintf(command, 200, "su professors -c 'tail -n %d /home/professors/%s'", numLines, fileName);
            } 
            else if (user == students) 
            {
                snprintf(command, 200, "su students -c 'tail -n %d /home/students/%s'", numLines, fileName);
            }
            break;

        default:
            printf("\nInvalid option! Returning to the main menu.\n");
            return;
    }
    
    int result = system(command);
    if (result != 0)
    {
        printf("\nError: Unable to view the file. Please check the file name or permissions.\n");
    }
}


void search_files(int user) {
    char search_term[100];   
    char search_path[200];   
    char command[400];       
    int search_choice;       

 
    printf("Choose your search type:\n");
    printf("1. Search by file/directory name\n");
    printf("2. Search inside file contents\n");
    printf("> ");
    scanf("%d", &search_choice);

  
    if (user == dean) {

        snprintf(search_path, sizeof(search_path), "/home/dean");
    } 
    else if (user == professors) {

        snprintf(search_path, sizeof(search_path), "/home/professors");
    } 
    else if (user == students) {

        snprintf(search_path, sizeof(search_path), "/home/students");
    } 
    else {
        printf("Invalid user type.\n");
        return;
    }


    printf("Enter the search term (file/directory name or content): ");
    scanf("%s", search_term);

   
    if (search_choice == 1) {
        // find
        snprintf(command, sizeof(command), "su %s -c \"find %s -name '%s' -print\"", 
                 (user == dean ? "dean" : (user == professors ? "professors" : "students")), 
                 search_path, search_term);
        printf("\nSearching for files or directories with name '%s'...\n", search_term);
    } else if (search_choice == 2) {
       //grep
        snprintf(command, sizeof(command), "su %s -c \"grep -rnw '%s' -e '%s'\"", 
                 (user == dean ? "dean" : (user == professors ? "professors" : "students")), 
                 search_path, search_term);
        printf("\nSearching inside files for content '%s'...\n", search_term);
    } else {
        printf("Invalid search choice.\n");
        return;
    }

    int result = system(command);
    if (result == 0) {
        printf("\nSearch completed successfully.\n");
    } else {
        printf("\nNo matches found or an error occurred.\n");
    }

}