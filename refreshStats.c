#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

  //our data for the gym
  int totalPeople = 0;
  int arms = 0;
  int back = 0;
  int cardio = 0;
  int chest = 0;
  int legs = 0;
  int classes = 0;
  int pool = 0;
  int courts = 0;
  
  FILE *gymData;
  gymData = fopen("dataEntry.txt", "r");


    time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);

  //find the current hour and minutes
    int hour =  timeinfo->tm_hour;
    int minute = timeinfo ->tm_min;

    //adjust for the time-zone change
    if(hour < 5){
      hour = 24 - 5 - hour;
    }
    else{
      hour -= 5;
    }

  //changes the hour to last time allowed to be in the data set
  hour -= 1;

   char chr = getc(gymData);
   int numLines = 1;

  //counts the lines in the file
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            numLines = numLines + 1;
        }
        //take next character from file.
        chr = getc(gymData);
    }
  
  //checks the time to see if it needs to be removed
  int dataHours;
  int dataMinutes;
  int activity;

      fseek(gymData, 0, SEEK_SET);
  for(int i = 0; i < numLines; i++ ){

    //scans the file
    fscanf(gymData, "%d %d %d", &dataHours, &dataMinutes, &activity);

    printf("%d %d %d\n", dataHours, dataMinutes, activity);
    //skips this data if its not the correct time
    if(dataHours < hour || ((dataHours == hour) && (dataMinutes < minute))){
      continue;
    }
    //adds the data to our statistics
    else{
        if(activity == 1){
          arms++;
        }
        else if(activity == 2){
          back++;
        }
        else if(activity == 3){
          cardio++;
        }
        else if(activity == 4){
          chest++;
        }
        else if(activity == 5){
          legs++;
        }
        else if(activity == 6){
          classes++;
        }
        else if(activity == 7){
          pool++;
        }
        else if (activity == 8){
          courts++;
        }
      totalPeople++;
      }
    }
    fclose(gymData);

  //writes data to stats file
    FILE *gymStats = fopen("stats.txt", "w");
      fprintf(gymStats,"%d %d %d %d %d %d %d %d %d", totalPeople, arms, back, cardio, chest, legs, classes, pool, courts);
      fclose(gymStats);
  }