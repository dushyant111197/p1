
#include<stdio.h> 
 
#define N 10 
 
typedef struct 
{ 
      int p, a, b, priority;
      int q, ready; 
      int waiting_time;
    int turnaround_time
}P; 
 
int Queue(int m1) 
{ 
      if(m1 == 0 || m1 == 1 || m1 == 2 || m1 == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
} 
 
int main() 
{ 
      int remain,n, c, temp_process, time, j, y; 
      P temp; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d", &n);  
      remain=n;
     P process[n]; 
      for(c = 0; c < n; c++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &process[c].p); 
            printf("Arrival Time:\t"); 
            scanf("%d", &process[c].a); 
            printf("Burst Time:\t"); 
            scanf("%d", &process[c].b); 
            printf("Process Priority:\t"); 
            scanf("%d", &process[c].p); 
            temp_process = process[c].priority; 
            process[c].q = Queue(temp_process);
            process[c].ready = 0;
			process[c].waiting_time = process[c].turnaround_time = 0; 
      }
      process[0].turnaround_time = process[0].b;
      time = process[0].b; 
      for(y = 0; y < n; y++) 
      
      {
	  for(c=1; c<n; c++) {
        process[c].waiting_time = process[c-1].waiting_time + process[c-1].b;
        process[c].turnaround_time = process[c].waiting_time + process[c].b;
    } 
      
            for(c = y; c < n; c++) 
            { 
                  if(process[c].a < time) 
                  {
                        process[c].ready = 1; 
                  } 
            } 
            for(c = y; c< n - 1; c++) 
            {
                  for(j = c + 1; j < n; j++) 
                  { 
                        if(process[c].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[c].q == 2 && process[j].q == 1) 
                              { 
                                    temp = process[c]; 
                                    process[c] = process[j]; 
                                    process[j] = temp; 
                              } 
                        } 
                  } 
            } 
            for(c = y; c < n - 1; c++) 
            { 
                  for(j = c + 1; j < n; j++) 
                  {
                        if(process[c].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[c].q == 1 && process[j].q == 1) 
                              { 
                                    if(process[c].b > process[j].b) 
                                    { 
                                          temp = process[c]; 
                                          process[c] = process[j]; 
                                          process[j] = temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            }
			 

            for(c = y; c < n; c++) 
            {
                  if(process[c].ready == 1) 
                  { 
                        process[c].ready = 0; 
                  } 
            }
      }
       table(process, n);
       gantt(process, n);
      return 0;
}
void table(P p[], int n)
{
    int i;

    puts("+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+------------+--------------+-----------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].p, p[i].b, p[i].waiting_time, p[i].turnaround_time );
        puts("+-----+------------+--------------+-----------------+");
    }

}
void gantt(P p[], int n)
{
    int i, j;
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b - 1; j++) printf(" ");
        printf("P%d", p[i].p);
        for(j=0; j<p[i].b - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b; j++) printf("  ");
        if(p[i].turnaround_time > 9) printf("\b"); 
        printf("%d", p[i].turnaround_time);

    }
    printf("\n");

} 

 


