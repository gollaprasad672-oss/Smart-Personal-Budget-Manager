#include<stdio.h>
#include<string.h>


// Displays the main menu options
void menubar(){
    printf("\n=== SMART PERSONAL BUDGET MANAGER ===\n");
    printf("1.Add expense\n");
    printf("2.View my expenses\n");
    printf("3.Monthly summary\n");
    printf("4.Exit\n");
    printf("Choose an option : ");
}



// Takes user input and writes a new expense into expenses.txt
void addexpense(){
    char date[11];
    char category[20];
    float amount;
    char sdesc[50];

    // Input fields
    printf("Enter Date(DD-MM-YYYY): ");
    scanf("%s", date);
    
    printf("Enter Category(Food/Travel/Bills/Shopping/Others): ");
    scanf("%s", category);
    
    printf("Enter amount : ");
    scanf("%f", &amount);
    
    printf("Enter Short Description(one line) : ");
    getchar();  // Clear leftover newline from previous scanf
    fgets(sdesc, 50, stdin);   // Read description line
    

    // Opening file in append mode
    FILE *ptr;
    ptr = fopen("expenses.txt", "a");

    if(ptr==NULL){
        printf("Could not open file\n");
        return;     // Stop function if file cannot open
    }

    // Writing the entry in CSV format
    fprintf(ptr, "%s,%s,%.2f,%s", date,category,amount,sdesc);
    
    fclose(ptr);

    printf("Press enter to continue...");
    getchar();
}



// Reads and prints all stored expenses line-by-line
void viewexpense(){
    int ID=1;
    char date[11];
    char category[20];
    float amount;
    char sdesc[50];

    FILE *ptr;
    ptr = fopen("expenses.txt", "r");

    if(ptr==NULL){
        printf("No records found");
        return;
    }

    // Table header
    printf("\n%-6s %-12s %-10s %-7s %s", "ID","Date","Category","Amount","Description");
    printf("\n----------------------------------------------------\n");


    // fscanf reads one formatted line at a time
    while(fscanf(ptr , " %[^,],%[^,],%f,%[^\n]\n",
                 date, category, &amount, sdesc) != EOF)
    {
        // Print the parsed line
        printf("%-6d %-12s %-10s %-7.2f %s\n",
               ID, date, category, amount, sdesc);
       
        ID++;   // Increment expense number
    }

    getchar();
    fclose(ptr);

    printf("\nPress Enter to Continue...");
    getchar();
}



// Calculates and prints the summary of a specific month/year
void monthlysum(){

    char date[11];
    char category[20];
    float amount;
    char sdesc[50];

    int count=0;      // Number of entries in selected month

    // Category-wise totals
    float Food=0;
    float Travel=0;
    float Shopping=0;
    float Bills=0;
    float Others=0;
    float Total=0;

    int month,year;
    printf("Enter Month(1-12) : ");
    scanf("%d", &month);
    
    printf("Enter Year(e.g., 2025) : ");
    scanf("%d", &year);

    FILE *ptr;
    ptr = fopen("expenses.txt", "r");

    if(ptr==NULL){
        printf("No records found");
    }

    printf("\nPress Enter to Continue...");
    getchar();   // To pause after input
     

    // Read file line-by-line
    while(fscanf(ptr , " %[^,],%[^,],%f,%[^\n]\n",
                 date, category, &amount, sdesc) != EOF)
    {
        int d,m,y;

        // Extract day, month, year from the date string
        if(sscanf(date, "%d-%d-%d", &d,&m,&y) != 3)
            continue;   // Skip line if date is invalid

        // CHECK: does this entry belong to requested month?
        if(m==month && y==year){
            count++;
            Total += amount;
        }

        // NOTE: These below category totals count **all months**, not filtered month.
        // This is how your original code behaves.
        if(strcmp(category, "Food")==0){
            Food += amount;
        }
        else if(strcmp(category, "Travel")==0){
            Travel += amount;
        }
        else if(strcmp(category, "Shopping")==0){
            Shopping += amount;
        }
        else if(strcmp(category, "Bills")==0){
            Bills += amount;
        }
        else{
            Others += amount;
        }
    }


    // If no matching data found
    if(count==0){
        printf("No Expenses found for %d/%d\n", month,year);
        printf("\nPress Enter to Continue...");
        getchar();
    }

    // Print summary
    printf("Summary for %d/%d : %d entries, Total = %.2f\n",
           month,year,count,Total);

    printf("\nCategory Breakdown :\n");
    printf("Food     : %.2f\n", Food);
    printf("Travel   : %.2f\n", Travel);
    printf("Shopping : %.2f\n", Shopping);
    printf("Bills    : %.2f\n", Bills);
    printf("Others   : %.2f\n", Others);

    // Determine the top-spending category
    char top[15]="Food";
    float topval=Food;

    if(Travel > topval){
        topval = Travel;
        strcpy(top, "Travel");
    }
    if(Shopping > topval){
        topval = Shopping;
        strcpy(top, "Shopping");
    }
    if(Bills > topval){
        topval = Bills;
        strcpy(top, "Bills");
    }
    if(Others > topval){
        topval = Others;
        strcpy(top, "Others");
    }

    printf("Top Spending Category : %s (%.2f)\n", top, topval);

    printf("\nPress Enter to Continue...");
    getchar();
}



int main(){
    int choice;

    do{
        menubar();      // Show menu

        scanf("%d", &choice);   // Read user choice

        switch(choice){
        case 1: addexpense(); break;
        case 2: viewexpense(); break;
        case 3: monthlysum(); break;
        case 4: printf("Exiting..."); break;
        default: printf("Invalid entry");
        }
    
    }while(choice!=4);  // Loop until Exit is chosen
        
    return 0;
}
