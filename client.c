#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include "comm.h"
#define MSGSIZE 1048
/* -------------------------Main function for the client ----------------------*/
void main(int argc, char * argv[]) {

	int pipe_to_user[2], pipe_to_server[2];
	char inbuf [MSGSIZE]; //Buffer for the client
	// You will need to get user name as a parameter, argv[1].

	if(connect_to_server("server.c", argv[1], pipe_to_user, pipe_to_server) == -1) {
		printf("Failed to connect to server\n");
		exit(-1);
	}
	else {
		printf("Connected to server\n");
		print_prompt(argv[1]);
	}

	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK); //Making Stdin NonBlocking

	print_prompt(argv[1]);

	while(1) {
	/* -------------- YOUR CODE STARTS HERE -----------------------------------*/
		close(pipe_to_user[1]); //Want to read from this pipe
		close(pipe_to_server[0]); //Want to write to this pipe

		// poll pipe retrieved and print it to sdiout
		//read(pipe_to_user[0], inbuf, 64);
		//fprintf (stderr, "%s\n", inbuf);
		//write(P_C[1], msg2, 64);
		// Poll stdin (input from the terminal) and send it to server (child process) via pipe
	}

	/* -------------- YOUR CODE ENDS HERE -----------------------------------*/
}

/*--------------------------End of main for the client --------------------------*/
