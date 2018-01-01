#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
// int getline(char line[], int maxline);
// void copy(char to[], char from[]);

main()
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	
	max = 0;
	while ((len = getlines(line, MAXLINE)) > 0){
		if (len > max) {
			max = len;
			copys(longest, line);
		}
	}
	if (max > 0) /* there was a line */
		printf("%s", longest);
	return 0;
}
/* getline: read a line into s, return length */
getlines(char s[],int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
copys(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}