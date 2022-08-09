# Lab 11: Knock-Knock Client/Server

## My Name:
Peter Tsanev

## Time Spent On Assignment:
I spent around an hour on this lab.

## Did you collaborate with others?
I did not collaborate with others and worked only by myself.

## Did you use any external resources?
I did not use any external resources for this lab.

## Three things about the lab!
* It was cool and surprising to see two different PuTTy shells talking to each other.
* It was interesting learning about clients and servers and seeing more of what goes on under the hood.
* I was surprised to see how easy it was to connect via ports and servers.

## Example:
-bash-4.2$ make run_echo_server
gcc echo_server.c -o echo_server
./echo_server
Listening on file descriptor 3, port 1234
Waiting for connection...
Connection made: client_fd=4

-----
-bash-4.2$ make run_echo_client
gcc echo_client.c -o echo_client
./echo_client
Enter your message: pizza
SENDING: pizza

FROM SERVER:
How many times should the message repeat?
Enter number of times to repeat: 5
SENDING: 5

FROM SERVER:
pizza
pizza
pizza
pizza
pizza

Enter your message:

-----
Read 6 chars
===
pizza

-----
Enter your message: CS5008
SENDING: CS5008

FROM SERVER:
How many times should the message repeat?
Enter number of times to repeat: 2
SENDING: 2

FROM SERVER:
CS5008
CS5008

-----
Read 7 chars
===
CS5008

-----
Enter your message: x
SENDING: x

FROM SERVER:

Enter number of times to repeat:
SENDING:

FROM SERVER:

Enter your message:
SENDING:

make: [run_echo_client] Broken pipe

-----
Got terminating signal from client...Closing connection.

-----
Enter your message: hekko
SENDING: hekko

FROM SERVER:
How many times should the message repeat?
Enter number of times to repeat: x
SENDING: x

FROM SERVER:

Enter your message:
SENDING:

FROM SERVER:

Enter number of times to repeat:
SENDING:

make: [run_echo_client] Broken pipe

-----
Connection made: client_fd=4
Got terminating signal from client...Closing connection.

