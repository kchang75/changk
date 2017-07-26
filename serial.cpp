/*********************
 * Kristi Chang         kristi.chang@csu.fullerton.edu
 * CPSC 351
 * Assignment 1
 * Due Date: July 26, 11:55 PM
 * File: serial.cpp
 *
 *********************/

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
using namespace std;

/* Read the URL files */
vector<string> urls;

/**
 * Forks children and lets them perform their tasks
 * @param urls - the urls to download
 */
void create_child(vector<string>& urls)
{	
	/* The process id */
	pid_t pid;
	int count = 0; //count the created children

	/* Go through all the URLs */
	for(vector<string>::iterator urlIt = urls.begin();
		urlIt != urls.end(); ++urlIt)
	{
		/* Create a child */
		pid = fork();
		count++;
		
		/* Make sure the fork was a success */
		if(pid < 0)
		{
			perror("fork: ");
			exit(1);
		}
		/* The child code */
		else if(pid == 0)
		{
			execlp("wget", "wget", urlIt->c_str(),NULL);
		}
		else
		{
			wait(NULL);
		}
	}
}


/**
 * Read the URLs from the file
 * @param urls - the URLs to download
 */

void read_urls(vector<string>& urls)
{
	/* Open the file */
	ifstream fileName("urls.txt");		
	
	string fileLine;
		
	/* Make sure the file was opened */
	if(fileName.is_open())
	{
		cout << "Successfully opened urls.txt\n\n";
	}
	else
	{
		cerr << "Failed to open urls.txt\n\n";
		exit(1);
	}
	
	/* Read the entire file */
	while(!fileName.eof())
	{
		/* Read a line */
		fileName >> fileLine;
		
		/* Are we at the end of the file */
		if(!fileName.eof())
		{
			urls.push_back(fileLine);
		}
	}
	
	/* Close the file */
	fileName.close();
}

int main()
{	

	/* Read the URLs */
	read_urls(urls);
	
	/* Create child processes */
	create_child(urls);
	
	wait(NULL);

	return 0;
	
}
