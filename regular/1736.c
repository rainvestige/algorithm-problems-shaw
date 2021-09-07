#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replacetime(char *seperatedtime, int i);

char * maximumTime(char * time){
    int timesize = strlen(time);
    char *seperatedtime = (char*)malloc(sizeof(char) * (timesize + 1));
    int i;

    for (i = 0; i < timesize; ++i) {
      seperatedtime[i] = time[i];
    }
    seperatedtime[i] = '\0';
    for (i = 0; i < timesize; ++i) {
      replacetime(seperatedtime, i);
    }
    return seperatedtime;
}

void replacetime(char *seperatedtime, int i) {
  if (seperatedtime[i] == '?') {
    switch (i) {
      case 0:
        if (seperatedtime[i+1] != '?' &&  seperatedtime[i+1] - '0' > 3) {
          seperatedtime[i] = '1';
        } else {
          seperatedtime[i] = '2';
        }
        break;
      case 1:
        if (seperatedtime[i-1] != '2') {
          seperatedtime[i] = '9';
        } else {
          seperatedtime[i] = '3';
        }
        break;
      case 2:
        // ':' colon
        break;
      case 3:
        seperatedtime[i] = '5';
        break;
      case 4:
        seperatedtime[i] = '9';
        break;
      default:
        printf("error\n");
        break;
    }
  }
}
