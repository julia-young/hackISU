#include <time.h>
#include <stdio.h>
#include <string.h>

#define BACK 1
#define ARMS 2
#define CARDIO 3
#define CHEST 4 
#define LEGS 5 
#define REC_CLASS 6
#define POOL 7
#define COURTS 8

int main() {
  time_t rawtime;
  struct tm * timeinfo;
  time( &rawtime );
  timeinfo = localtime( &rawtime );

  int timeHour = (timeinfo->tm_hour) - 5;

  if (timeHour < 0) {
    timeHour = 24 + (timeHour);
  }
  
  printf("%02d %02d", timeHour, timeinfo->tm_min);

  FILE * gymData = fopen("dataEntry.txt", "a");

  //fprintf(gymData, "hello world");
  fprintf(gymData, "%02d %02d %d\n", timeHour, timeinfo->tm_min, ARMS);

  fclose(gymData);
  return 0;
}