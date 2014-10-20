#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int main()
{
/*
2014-10-09 23:58:41.890115 00:24:8c:c7:27:eb 00:0e:38:fe:73:00, UDP (17), 
140.113.215.239.8414 222.161.96.181.12611: 25
*/
	ifstream input;
	ofstream output;
	input.open("filtered_file",ios::in);
	output.open("flow_file_IP",ios::out);
	
	map<string, int> flow_IP;//src IP, port
	map<string, int>::iterator it;

	char pattern[1000+1]="";
	if(!input.is_open())
	{
		cerr<<"error"<<endl;
		return 0;
	}

	int flow_count = 0;
	while(input.eof()==false)
	{
		input.getline(pattern,1000);//first
		char* tmp = strtok(pattern, ", ");
	if(!tmp) break;
		input.getline(pattern,1000);//second
		tmp = strtok(pattern, ": ");
		string IP_port = tmp;

		it = flow_IP.find(IP_port);
		if(it == flow_IP.end())//not found
		{
			flow_IP.insert(pair<string, int>(IP_port,flow_count));
			output<<IP_port<<endl;
			flow_count++;
		}
		else
		{
			//packet count++
			//accumulate packet bytes
		}
	}
	cout<<"Total # of flows: "<<flow_count<<endl;
	input.close();
	output.close();
}
