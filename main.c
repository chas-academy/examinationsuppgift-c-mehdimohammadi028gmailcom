//Write your code in this file
#include<stdio.h>


int main(){
    int num_of_students= 5;
    int num_of_subjects= 13;
    char students [num_of_students][50]= {};
    int results[num_of_students][num_of_subjects] = {};

    // Mata in värdena för elevers namn respektiv ämne
    for (int s = 0; s < num_of_students; s++){
        scanf("%s", students[s]);
        for (int r = 0; r < num_of_subjects; r++){
            scanf("%d", &results[s][r]);
        }
    }

    // korrekta initials
    for (int i=0 ; i<num_of_students ; i++){
        if (students[i][0] >= 97 && students[i][0] <= 122 ){
            students[i][0] = students[i][0] - 32;
        }
    }

    // Beräkna studenternas medelvärden
    int averages[5]={};
    int highest_one= -1;
    int index = -1;
    for (int i = 0 ; i<num_of_students ; i++){
        for (int j = 0; j < num_of_subjects; j++){
            averages[i] += results[i][j];
        }
        averages[i] = averages[i]/num_of_subjects;
        if (averages[i] > highest_one){
            highest_one = averages[i];
            index = i;
        }
    }
    printf("%s\n", students[index]);

    //totala medelvärdet
    int sum=0;
    int tot_avg=0;
    for (int i=0 ; i<num_of_students ; i++){
        sum += averages[i];
    }
    tot_avg = sum/num_of_students;

    // elever som ligger under medelvärdet
    for (int i=0, j=0 ; i<num_of_students; i++){
        if(averages[i] < tot_avg){
            printf("%s\n", students[i]);
        }
    }
    return 0;
}