#include <stdio.h>

int main() {
    int votes[5][5] = {
            {1, 192, 48, 206, 37},
            {2, 147, 90, 312, 21},
            {3, 186, 12, 121, 38},
            {4, 114, 21, 408, 39},
            {5, 267, 13, 108, 29}
    };
    //This part of the program will display the table above and tally the total number of votes
    printf("%-20s%-20s%-20s%-20s%-20s\n", "Precinct", "Candidate A", "Candidate B", "Candidate C", "Candidate D");
    double totalvotes;
    for(int rows = 0; rows < 5; rows++)
    {
        for(int cols = 0; cols < 5; cols++)
        {
            printf("%-20d", votes[rows][cols]);
            totalvotes += votes[rows][cols];
        }
        printf("\n");
    }
    totalvotes -= 15;
    printf("***********************************************************************************************\n");
    //This part of the program will calculate and display each candidate's total votes
    double prcntdata[4];
    for(int cols = 1; cols < 5; cols++)
    {
        int temp = 0;
        for(int rows = 0; rows < 5; rows++)
        {
            temp += votes[rows][cols];
        }
        double prcntofvotes = (temp / totalvotes) * 100;
        prcntdata[cols-1] = prcntofvotes;
        printf("Candidate %d received %d votes, or %.2lf percent of votes\n", cols, temp, prcntofvotes);
    }
    printf("***********************************************************************************************\n");
    //This section of the program will declare a winner if one candidate has more than 50 percent of the votes
    if(prcntdata[0] > 50.00)
        printf("Candidate A won the election!");
    else if(prcntdata[1] > 50.00)
        printf("Candidate B won the election!");
    else if(prcntdata[2] > 50.00)
        printf("Candidate C won the election!");
    else if (prcntdata[3] > 50.00)
        printf("Candidate D won the election!");
    //This last conditional statement with determine the runoff
    else
    {
        if(prcntdata[0] > prcntdata[1] && prcntdata[0] > prcntdata[2] && prcntdata[0] > prcntdata[3])
        {
            printf("There is a runoff between Candidate A and ");
            if(prcntdata[1] > prcntdata[2] && prcntdata[1] > prcntdata[3])
                printf("Candidate B!");
            else if(prcntdata[2] > prcntdata[1] && prcntdata[2] > prcntdata[3])
                printf("Candidate C!");
            else if(prcntdata[3] > prcntdata[1] && prcntdata[3] > prcntdata[2])
                printf("Candidate D!");
        }
        else if(prcntdata[1] > prcntdata[0] && prcntdata[1] > prcntdata[2] && prcntdata[1] > prcntdata[3])
        {
            printf("There is a runoff between Candidate B and ");
            if(prcntdata[0] > prcntdata[2] && prcntdata[0] > prcntdata[3])
                printf("Candidate A!");
            else if(prcntdata[2] > prcntdata[0] && prcntdata[2] > prcntdata[3])
                printf("Candidate C!");
            else if(prcntdata[3] > prcntdata[0] && prcntdata[3] > prcntdata[2])
                printf("Candidate D!");
        }
        else if(prcntdata[2] > prcntdata[0] && prcntdata[2] > prcntdata[1] && prcntdata[0] > prcntdata[3])
        {
            printf("There is a runoff between Candidate C and ");
            if(prcntdata[1] > prcntdata[0] && prcntdata[1] > prcntdata[3])
                printf("Candidate B!");
            else if(prcntdata[0] > prcntdata[1] && prcntdata[0] > prcntdata[3])
                printf("Candidate A!");
            else if(prcntdata[3] > prcntdata[1] && prcntdata[3] > prcntdata[0])
                printf("Candidate D!");
        }
        if(prcntdata[3] > prcntdata[1] && prcntdata[3] > prcntdata[2] && prcntdata[3] > prcntdata[0])
        {
            printf("There is a runoff between Candidate D and ");
            if(prcntdata[1] > prcntdata[2] && prcntdata[1] > prcntdata[0])
                printf("Candidate B!");
            else if(prcntdata[2] > prcntdata[1] && prcntdata[2] > prcntdata[0])
                printf("Candidate C!");
            else if(prcntdata[0] > prcntdata[1] && prcntdata[0] > prcntdata[2])
                printf("Candidate A!");
        }
    }
}
