
#include <time.h>

char g_logpath[150];

char *getdate8 (char *buff)
{
  struct tm     *tm_now;
  time_t        time_now;
  static char   sbuff[20];

  time_now = time (NULL);
  tm_now = localtime (&time_now);
  if (buff != NULL)  {
    sprintf (buff, "%04d%02d%02d", tm_now->tm_year + 1900,
                        tm_now->tm_mon + 1, tm_now->tm_mday);
    return (buff);
  } else  {
    sprintf (sbuff, "%04d%02d%02d", tm_now->tm_year + 1900,
                        tm_now->tm_mon + 1, tm_now->tm_mday);
    return (sbuff);
  }
}

char *gettime1 (char *buff)
{
  struct tm     *tm_now;
  time_t        time_now;
  static char   sbuff[20];

  time_now = time (NULL);
  tm_now = localtime (&time_now);
  if (buff != NULL)  {
    sprintf (buff, "%02d:%02d:%02d", tm_now->tm_hour, tm_now->tm_min,
                        tm_now->tm_sec);
    return (buff);
  } else  {
    sprintf (sbuff, "%02d:%02d:%02d", tm_now->tm_hour, tm_now->tm_min,
                        tm_now->tm_sec);
    return (sbuff);
  }
}


void write_log (char *level,char * msg)
{
  FILE          *fp;
  char          w_buff1[20], w_buff2[20];
  strcpy(g_logpath,"./log/OTIP");
  strcat(g_logpath,getdate8(w_buff1));
  fp = fopen (g_logpath, "a+");
  if (fp != NULL)  {
    fprintf (fp, "%s;%s;[%s];%s;%s;%s;\n", getdate8(w_buff1), gettime1(w_buff2),level,
      ,msg);
  }
  fclose (fp);
}