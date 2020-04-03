#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    // Initializing two pipes
	int fd1[2];
	int fd2[2];



	pid_t p;

	if (pipe(fd1)==-1)
	{
		fprintf(stderr, "Pipe Failed" );
		return 1;
	}
	if (pipe(fd2)==-1)
	{
		fprintf(stderr, "Pipe Failed" );
		return 1;
	}


	p = fork();

	if (p < 0)
	{
		fprintf(stderr, "fork Failed" );
		return 1;
	}

	// Parent process
	else if (p > 0)
	{
		char reverse_str[100];
		char input[100];
		printf("Enter String: ");
	    scanf("%[^\n]s", input);
		close(fd1[0]);
		write(fd1[1], input, strlen(input)+1);
        close(fd1[1]);

		// Wait for child to send a string
		wait(NULL);

		close(fd2[1]); // Close writing end of second pipe

		// Read string from child, print it
		read(fd2[0], reverse_str, 100);
		printf("Case Reversed String: %s\n", reverse_str);
		close(fd2[0]); //close reading end.
	}

	// child process
	else
	{
	    char input_str[100];
		close(fd1[1]); // Close writing end of first pipe
        read(fd1[0], input_str, 100);
		char reverse_str[100];

		// Reverse Case
		int i;
		for (i=0; i<strlen(input_str); i++){
			if(input_str[i]>='a' && input_str[i]<='z')
                reverse_str[i] = (char)((int)(input_str[i])-32);
            else if(input_str[i]>='A' && input_str[i]<='Z')
                reverse_str[i] = (char)((int)(input_str[i])+32);
            else
                reverse_str[i] = input_str[i];
		}


		reverse_str[i] = '\0'; // ends with '\0' {C programming concept}

		// Close both reading ends
		close(fd1[0]);
		close(fd2[0]);

		// Write reversed string and close writing end
		write(fd2[1], reverse_str, strlen(reverse_str)+1);
		close(fd2[1]);

		exit(0);
	}
}
