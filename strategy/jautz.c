/*
 * ----------------------------------------------------------------------------
 * "THE COFFEE-WARE LICENSE" (Revision 23):
 * <toke@toke.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can bring me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "jautz.h"

uint write_cb(char *in, uint size, uint nmemb, void *out)
{
  uint r;
  r = size * nmemb;
  if (r < BUFSIZE) {
  	snprintf(out, r, "%s", in);  
  } else {
	printf("Something bad has happend. Server returned unexpected data.\n");
	exit (-1);
  }
  return(r);
}


kraus_t jautz_floor(struct tm *date){
  CURL *curl;
  CURLcode res;
  kraus_t floor;
  char url[255];
  char docbuf[BUFSIZE] = {0};  

  sprintf(url, DEFAULT_URL, 0);
  //printf("%s",url);

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &docbuf);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res == CURLE_OK) {
  	floor = atoi(docbuf);
    } else {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
      floor = ERROR_FLOOR;
    }
    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  return (kraus_t) floor;
}
